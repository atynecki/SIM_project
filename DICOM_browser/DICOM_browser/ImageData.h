#pragma once

/**
*  @file    ImageData.h
*  @author  Artur Tynecki
*  @date    June, 2017
*
*  @brief Image Data class header file
*
* A class represetning DICOM image details. It contains information such as:
* image size (width, height), color space, VOI, minimum and maximum pixel values
*
*/

#include <string.h>
#include <list>
#include <imebra.h>

class ImageData
{
private:
	long imageWidth;									/**< DICOM image width */
	long imageHeight;									/**< DICOM image height */
	std::string colorSpace;								/**< DICOM image color space */
	std::string windowWidth;							/**< DICOM image window width */
	int32_t minPixel;									/**< DICOM image minimum pixel value */
	int32_t maxPixel;									/**< DICOM image maximum pixel value */
	imebra::VOIDescription VOI;							/**< DICOM image VOI */

public:
	/**
	*  @brief Default constructor
	*/
	ImageData();

	/**
	*  @brief Parameterized constructor
	*
	*  @param [in] width - DICOM image width
	*  @param [in] height - DICOM image height
	*  @param [in] colorSpace - DICOM image color space
	*  @param [in] windowWidth - DICOM image windowWidth
	*/
	ImageData(long width, long height, std::string colorSpace, std::string windowWidth);

	/**
	*  @brief Get width
	*
	*  @param none
	*  @return value of image width
	*/
	long GetWidth();

	/**
	*  @brief Get height
	*
	*  @param none
	*  @return value of image height
	*/
	long GetHeight();

	/**
	*  @brief Get color space
	*
	*  @param none
	*  @return value of color space
	*/
	std::string GetColorSpace();

	/**
	*  @brief Get window width
	*
	*  @param none
	*  @return value of window width
	*/
	std::string GetWindowWidth();

	/**
	*  @brief Get minimum pixel
	*
	*  @param none
	*  @return value of minimum pixel
	*/
	int32_t GetMinPixel();

	/**
	*  @brief Set minimum pixel
	*
	*  @param [in] value - value to set
	*  @return none
	*/
	void SetMinPixel(int32_t value);

	/**
	*  @brief Get maximum pixel
	*
	*  @param none
	*  @return value of maximum pixel
	*/
	int32_t GetMaxPixel();

	/**
	*  @brief Set maximum pixel
	*
	*  @param [in] value - value to set
	*  @return none
	*/
	void SetMaxPixel(int32_t value);

	/**
	*  @brief Get VOI
	*
	*  @param none
	*  @return value of VOI
	*/
	imebra::VOIDescription GetVOI();

	/**
	*  @brief Set VOI
	*
	*  @param [in] value - value to set
	*  @return none
	*/
	void SetVOI(imebra::VOIDescription value);
};
