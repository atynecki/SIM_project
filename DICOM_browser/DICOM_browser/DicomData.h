#pragma once

#include <string>

class DicomData
{
private:
	std::string image;
	std::uint32_t image_width;
	std::uint32_t image_height;
	std::string patientName;

public:
	DicomData();
	~DicomData();

	void setPatientName(std::string name)
	{
		this->patientName = name;
	}
	std::string getPatientName(void)
	{
		return patientName;
	}

	void setImage(std::string image, std::uint32_t width, std::uint32_t height)
	{
		this->image = image;
		this->image_width = width;
		this->image_height = height;
	}

	void getImage(std::string* image_out, std::uint32_t* width, std::uint32_t* height)
	{
		*image_out = this->image;
		*width = this->image_width;
		*height = this->image_height;
	}
};