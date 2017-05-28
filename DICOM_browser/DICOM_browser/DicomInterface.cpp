#include "DicomInterface.h"

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
	if (!s_instance)
	{
		s_instance = new DicomInterface;
	}
		
	return s_instance;
}

void DicomInterface::loadImage()
{
	this->image = unique_ptr<imebra::Image>(this->dataSet->getImageApplyModalityTransform(0));
}

tagsIds_t DicomInterface::loadConfigTags()
{
	tagsIds_t configTags;

	string line;
	ifstream configFile("CONFIG.txt");
	if (configFile.is_open())
	{
		while (getline(configFile, line))
		{
			string id;
			int data[2];
			stringstream ss(line);

			for (int index = 0; index < 2; index++)
			{
				string value;
				getline(ss, value, ',');
				stringstream str;
				str << value;
				str >> std::hex >> data[index];
			}
			
			configTags.push_back(TagId(data[0], data[1]));
		}
		configFile.close();
	}

	return configTags;
}

DataRecord DicomInterface::getDataRecord(TagId tag)
{
	string value;
	string description;

	DataRecord record;

	if ((dataSet->getTag(tag) != nullptr) && (tag.getGroupId() != 0x7FE0))
	{
		try
		{
			value = dataSet->getString(tag, 0, "none");
			if (value != "none")
			{
				description = DicomDictionary::getTagName(tag);
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
			dataRecordList.push_back(record);
		}
	} 
}

void DicomInterface::loadAdminData()
{
	//tagsIds_t tagList = loadConfigTags();
	tagsIds_t tagList = dataSet->getTags();
	setDataRecords(tagList);
}

/*API function*/
void DicomInterface::loadData(string path)
{
	this->dataSet = unique_ptr<DataSet>(CodecFactory::load(StreamReader(FileStreamInput(path))));
	loadAdminData();
	loadImage();
}

string DicomInterface::getImage(uint32_t* width, uint32_t* height)
{
	// Get the color space
	std::string colorSpace = image->getColorSpace();

	// Get the size in pixels
	*width = image->getWidth();
	*height = image->getHeight();

	imebra::TransformsChain chain;

	if (imebra::ColorTransformsFactory::isMonochrome(colorSpace))
	{
		// Allocate a VOILUT transform. If the DataSet does not contain any pre-defined
		//  settings then we will find the optimal ones.
		imebra::VOILUT voilutTransform;

		// Retrieve the VOIs (center/width pairs)
		imebra::vois_t vois = dataSet->getVOIs();

		// Retrieve the LUTs
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

		if (!vois.empty())
		{
			voilutTransform.setCenterWidth(vois[0].center, vois[0].width);
		}
		else if (!luts.empty())
		{
			voilutTransform.setLUT(*(luts.front().get()));
		}
		else
		{
			voilutTransform.applyOptimalVOI(*image.get(), 0, 0, *width, *height);
		}

		chain.addTransform(voilutTransform);

		// We create a DrawBitmap that always apply the chain transform before getting the RGB image
		imebra::DrawBitmap draw(chain);

		// Ask for the size of the buffer (in bytes)
		size_t requestedBufferSize = draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGBA, 4, 0, 0);

		// Now we allocate the buffer and then ask DrawBitmap to fill it
		std::string buffer(requestedBufferSize, char(0));
		draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGBA, 4, &(buffer.at(0)), requestedBufferSize);
		return buffer;
	}
	else
	{
		imebra::DrawBitmap draw(chain);
		// Ask for the size of the buffer (in bytes)
		size_t requestedBufferSize = draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGB, 4, 0, 0);

		// Now we allocate the buffer and then ask DrawBitmap to fill it
		std::string buffer(requestedBufferSize, char(0));
		draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGB, 4, &(buffer.at(0)), requestedBufferSize);
		return buffer;
	}
}

list<string> DicomInterface::getDataRecordDescriptionList()
{
	list<string> descriptions;

	for each(DataRecord it in dataRecordList)
	{
		descriptions.push_back(it.GetDescription() + " (" + it.GetGroupIdAsString() + "," + it.GetElementIdAsString() + ")");
	}

	return descriptions;
}

list<string> DicomInterface::getDataRecordValueList()
{
	list<string> values;

	for each(DataRecord it in dataRecordList)
	{
		values.push_back(it.GetValue());
	}

	return values;
}

DataRecord DicomInterface::addDataRecord(uint16_t groupId, uint16_t elementId)
{
	TagId id(groupId, elementId);

	DataRecord newRecord = getDataRecord(id);

	if (!newRecord.GetDescription().empty())
	{
		dataRecordList.push_back(newRecord);
	}

	return newRecord;
}


