#include "DicomInterface.h"

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

/*API function*/
void DicomInterface::loadData(string path)
{
	this->dataSet = unique_ptr<DataSet>(CodecFactory::load(StreamReader(FileStreamInput(path))));
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

	descriptions.push_front("PatientName(0010,0010)");

	return descriptions;
}

list<string> DicomInterface::getDataRecordValueList()
{
	list<string> values;

	values.push_front("Jan Kowalski");

	return values;
}




