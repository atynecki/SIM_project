#include "DicomInterface.h"
#include <string.h>
#include <list>

using namespace System::Runtime::InteropServices;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing::Imaging;

DicomInterface* DicomInterface::s_instance = NULL;

DicomInterface* DicomInterface::getInstance()
{
	if (!s_instance)
		s_instance = new DicomInterface;
	return s_instance;
}

void DicomInterface::loadDataSet()
{
	this->dataSet = std::unique_ptr<imebra::DataSet>(imebra::CodecFactory::load("CT-MONO2-16-brain"));
}

std::string DicomInterface::getPatientName()
{
	std::wstring patientNameCharacter = this->dataSet->getUnicodeString(imebra::TagId(imebra::tagId_t::PatientName_0010_0010), 0);
	std::string result(patientNameCharacter.begin(), patientNameCharacter.end());
	return result;
}

std::string DicomInterface::getStudyDescription()
{
	std::string studyDesc = this->dataSet->getString(imebra::TagId(imebra::tagId_t::StudyDescription_0008_1030), 1);
	//std::string result((const char*)&studyDesc[0], sizeof(wchar_t) / sizeof(char)*studyDesc.size());

	return studyDesc;
}

Bitmap^ DicomInterface::getImage(int index)
{
	Bitmap^ ret = nullptr;

	std::unique_ptr<imebra::Image> image(this->dataSet->getImageApplyModalityTransform(index));
	
	// Get the color space
	std::string colorSpace = image->getColorSpace();

	// Get the size in pixels
	std::uint32_t width = image->getWidth();
	std::uint32_t height = image->getHeight();

	imebra::TransformsChain chain;

	if (imebra::ColorTransformsFactory::isMonochrome(image->getColorSpace()))
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
				luts.push_back(std::shared_ptr<imebra::LUT> (this->dataSet->getLUT(imebra::TagId(imebra::tagId_t::VOILUTSequence_0028_3010), scanLUTs)));

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

		String^ buffer_ptr = gcnew String(buffer.c_str());
		IntPtr sptr = Marshal::StringToHGlobalAnsi(buffer_ptr);
		ret = gcnew Bitmap(width, height, 4*width, Imaging::PixelFormat::Format32bppRgb, sptr);

		return ret;
	}

	return {};
}


