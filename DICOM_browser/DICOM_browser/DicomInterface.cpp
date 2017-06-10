#include "DicomInterface.h"

/**
*  @file    DicomInterface.h
*  @author  Artur Tynecki
*  @date    May, 2017
*
*  @brief Dicom data service interface source file
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace System::Runtime::InteropServices;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing::Imaging;
using namespace std;
using namespace imebra;

DicomInterface* DicomInterface::s_instance = NULL;

DicomInterface* DicomInterface::getInstance()
{
	/* Create instance if does not exist */
	if (!s_instance)
	{
		s_instance = new DicomInterface;
	}
		
	return s_instance;
}

void DicomInterface::loadImage()
{
	/* Load first image from data set */
	this->image = unique_ptr<imebra::Image>(this->dataSet->getImageApplyModalityTransform(0));
	
	/* Get the size in pixels */
	long width = image->getWidth();
	long height = image->getHeight();

	/* Get the color space */
	std::string colorSpace = image->getColorSpace();

	this->imageData = ImageData(width, height, colorSpace);

	/* Get the VOI (center/width pairs) */
	vois_t vois = dataSet->getVOIs();
	if (!vois.empty())
	{
		VOIDescription voi = vois[0];
		wstring desc(L"VOI");
		voi.description = desc;
		imageData.SetVOI(voi);
	}

	// Retrieve the data handler
	std::unique_ptr<imebra::ReadingDataHandlerNumeric> dataHandler(image->getReadingDataHandler());

	// Get max and min value
	if (imebra::ColorTransformsFactory::isMonochrome(colorSpace))
	{
		int32_t min = imageData.GetMinPixel();
		int32_t max = imageData.GetMaxPixel();

		for (std::uint32_t scanY(0); scanY != height; ++scanY)
		{
			for (std::uint32_t scanX(0); scanX != width; ++scanX)
			{
				// For monochrome images
				std::int32_t value = dataHandler->getSignedLong(scanY * width + scanX);
				if (value > max)
				{
					max = value;
				}

				if (value < min)
				{
					min = value;
				}
			}
		}

		imageData.SetMaxPixel(max);
		imageData.SetMinPixel(min);
	}
}

DataRecord DicomInterface::getDataRecord(TagId tag)
{
	string value;
	string description;

	DataRecord record;

	/* Check if tag exist and it is different from pixel image */
	if ((dataSet->getTag(tag) != nullptr) && (tag.getGroupId() != 0x7FE0))
	{
		try
		{
			/* Get tag value */
			value = dataSet->getString(tag, 0, "none");
			if (value != "none")
			{
				/* Get tag description */
				description = DicomDictionary::getTagName(tag);

				/* Set data record */
				record.SetDescription(description);
				record.SetValue(value);
				record.SetGroupId(tag.getGroupId());
				record.SetElementId(tag.getTagId());
			}
		}
		catch (...)
		{
			return record;
		}
	}

	return record;
}

void DicomInterface::setDataRecords(tagsIds_t tags)
{
	for each(TagId it in tags)
	{
		DataRecord record = getDataRecord(it);

		if (!record.GetDescription().empty())
		{
			/* Add recrod to the list */
			dataRecordList.push_back(record);
		}
	} 
}

void DicomInterface::loadAdminData()
{
	/* Get all available tags from data set */
	tagsIds_t tagList = dataSet->getTags();
	/* Set data records */
	setDataRecords(tagList);
}

void DicomInterface::loadData(string path)
{
	/* Load DICOM data form the file */
	this->dataSet = unique_ptr<DataSet>(CodecFactory::load(StreamReader(FileStreamInput(path))));
	dataRecordList = std::list<DataRecord>();
	loadAdminData();
	loadImage();
}

string DicomInterface::getImage()
{
	imebra::TransformsChain chain;

	if (imebra::ColorTransformsFactory::isMonochrome(imageData.GetColorSpace()))
	{
		/* Allocate a VOILUT transform. If the DataSet does not contain any pre-defined
		settings then we will find the optimal ones. */
		imebra::VOILUT voilutTransform;

		/* Retrieve the LUTs */
		std::list<std::shared_ptr<imebra::LUT> > luts;
		for (size_t scanLUTs(0); ; ++scanLUTs)
		{
			try
			{
				luts.push_back(std::shared_ptr<imebra::LUT>(this->dataSet->getLUT(imebra::TagId(imebra::tagId_t::VOILUTSequence_0028_3010), scanLUTs)));

			}
			catch (const imebra::MissingDataElementError&)
			{
				break;
			}
		}

		/* Set tranformation data */
		VOIDescription voi = imageData.GetVOI();
		if (!voi.description.empty())
		{
			voilutTransform.setCenterWidth(voi.center, voi.width);
		}
		else if (!luts.empty())
		{
			voilutTransform.setLUT(*(luts.front().get()));
		}
		else
		{
			voilutTransform.applyOptimalVOI(*image.get(), 0, 0, imageData.GetWidth(), imageData.GetHeight());
		}

		/* Add transformation data to the chain */
		chain.addTransform(voilutTransform);

		/* Create a DrawBitmap that always apply the chain transform before getting the RGB image */
		imebra::DrawBitmap draw(chain);

		/* Ask for the size of the buffer (in bytes) */
		size_t requestedBufferSize = draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGBA, 4, 0, 0);

		/* Allocate the buffer and then ask DrawBitmap to fill it */
		std::string buffer(requestedBufferSize, char(0));
		draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGBA, 4, &(buffer.at(0)), requestedBufferSize);
		
		return buffer;
	}
	else
	{
		/* Set image without tranformation */
		imebra::DrawBitmap draw(chain);
		size_t requestedBufferSize = draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGB, 4, 0, 0);
		std::string buffer(requestedBufferSize, char(0));
		draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGB, 4, &(buffer.at(0)), requestedBufferSize);
		
		return buffer;
	}
}



vector<string> DicomInterface::getDataRecordDescriptionList()
{
	vector<string> descriptions;

	for each(DataRecord it in dataRecordList)
	{
		/* Set record description with format: descpritonValue (groupId,elementId) f.e. Patient Name (0010,0010)*/
		descriptions.push_back(it.GetDescription() + " (" + it.GetGroupIdAsString() + "," + it.GetElementIdAsString() + ")");
	}

	return descriptions;
}

vector<string> DicomInterface::getDataRecordValueList()
{
	vector<string> values;

	for each(DataRecord it in dataRecordList)
	{
		values.push_back(it.GetValue());
	}

	return values;
}

DataRecord DicomInterface::addDataRecord(uint16_t groupId, uint16_t elementId)
{
	TagId id(groupId, elementId);

	/* Create new data record */
	DataRecord newRecord = getDataRecord(id);

	/* If tag exist add to the list */
	if (!newRecord.GetDescription().empty())
	{
		dataRecordList.push_back(newRecord);
	}

	return newRecord;
}

ImageData* DicomInterface::GetImageData() 
{
	return &imageData;
}

void DicomInterface::SetImageVOI(double center, double width)
{
	/* Create new VOI*/
	VOIDescription voi;
	voi.center = center;
	voi.width = width;
	wstring desc(L"VOI");
	voi.description = desc;
	imageData.SetVOI(voi);
}


