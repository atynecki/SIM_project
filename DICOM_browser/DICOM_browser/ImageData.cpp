/**
*  @file    ImageData.cpp
*  @author  Artur Tynecki
*  @date    June, 2017
*
*  @brief Image Data class source file
*
*/

#include "ImageData.h"
#include <limits>

using namespace std;
using namespace imebra;

ImageData::ImageData()
{
	this->imageWidth = 0;
	this->imageHeight = 0;
	this->minPixel = numeric_limits<int32_t>::max();
	this->maxPixel = 0;
}

ImageData::ImageData(long width, long height, string colorSpace)
{
	this->imageWidth = width;
	this->imageHeight = height;
	this->colorSpace = colorSpace;
	this->minPixel = numeric_limits<int32_t>::max();
	this->maxPixel = 0;
}

long ImageData::GetWidth()
{
	return this->imageWidth;
}

long ImageData::GetHeight()
{
	return this->imageHeight;
}

string ImageData::GetColorSpace()
{
	return this->colorSpace;
}

int32_t ImageData::GetMinPixel()
{
	return this->minPixel;
}

void ImageData::SetMinPixel(int32_t value)
{
	this->minPixel = value;
}

int32_t ImageData::GetMaxPixel()
{
	return this->maxPixel;
}

void ImageData::SetMaxPixel(int32_t value)
{
	this->maxPixel = value;
}

VOIDescription ImageData::GetVOI()
{
	return this->VOI;
}

void ImageData::SetVOI(VOIDescription value)
{
	this->VOI = value;
}


