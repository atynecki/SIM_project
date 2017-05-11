#include "DicomInterface.h"
#include <list>

using namespace System::Runtime::InteropServices;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing::Imaging;
using namespace std;
using namespace imebra;

DicomInterface* DicomInterface::s_instance = NULL;
DicomData* DicomInterface::dicomData = NULL;

DicomInterface* DicomInterface::getInstance()
{
	if (!s_instance)
	{
		s_instance = new DicomInterface;
		dicomData = new DicomData;
	}
		
	return s_instance;
}

void DicomInterface::loadPatientName()
{
	std::string patientName = this->dataSet->getString(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), 0);
	dicomData->setPatientName(patientName);
}

void DicomInterface::loadImage()
{
	std::unique_ptr<imebra::Image> image(this->dataSet->getImageApplyModalityTransform(0));

	// Get the color space
	std::string colorSpace = image->getColorSpace();

	// Get the size in pixels
	std::uint32_t width = image->getWidth();
	std::uint32_t height = image->getHeight();

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
			voilutTransform.applyOptimalVOI(*image.get(), 0, 0, width, height);
		}

		chain.addTransform(voilutTransform);

		// We create a DrawBitmap that always apply the chain transform before getting the RGB image
		imebra::DrawBitmap draw(chain);

		// Ask for the size of the buffer (in bytes)
		size_t requestedBufferSize = draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGBA, 4, 0, 0);

		// Now we allocate the buffer and then ask DrawBitmap to fill it
		std::string buffer(requestedBufferSize, char(0));
		draw.getBitmap(*image.get(), imebra::drawBitmapType_t::drawBitmapRGBA, 4, &(buffer.at(0)), requestedBufferSize);

		dicomData->setImage(buffer, width, height);
	}
}

void DicomInterface::loadData(string path)
{
	this->dataSet = unique_ptr<DataSet>(CodecFactory::load(StreamReader(FileStreamInput(path))));
	loadPatientName();
	loadImage();
}

Bitmap^ DicomInterface::getImage()
{
	Bitmap^ ret = nullptr;
	string buffer;
	uint32_t width;
	uint32_t height;

	dicomData->getImage(&buffer, &width, &height);

	String^ buffer_ptr = gcnew String(buffer.c_str());
	IntPtr sptr = Marshal::StringToHGlobalAnsi(buffer_ptr);
	ret = gcnew Bitmap(width, height, 4 * width, Imaging::PixelFormat::Format32bppRgb, sptr);
	
	return ret;
}

String^ DicomInterface::getName()
{	
	String^ ret = nullptr;

	ret = gcnew String(dicomData->getPatientName().c_str());
	return ret;
}



