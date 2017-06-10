#pragma once

/**
*  @file    DicomInterface.h
*  @author  Artur Tynecki
*  @date    May, 2017
*
*  @brief Dicom data service interface header file
*
* A class represetning DICOM data service interface. 
* It constians method to load DICOM date and transfer them to GUI layer.
* The class is implemented as singleton. 
* 
*
*/

#include <string>
#include <imebra.h>
#include <list>
#include "DataRecord.h"
#include "ImageData.h"

class DicomInterface
{
private:
	std::unique_ptr<imebra::DataSet> dataSet;	/**< DICOM data set */
	std::unique_ptr<imebra::Image> image;		/**< DICOM image */
	ImageData imageData;						/**< DICOM image data */
	std::list<DataRecord> dataRecordList;		/**< DICOM data record list */
	static DicomInterface* s_instance;			/**< DICOM interface instance */

	/**
	*  @brief Default constructor (unavailable)
	*/
	DicomInterface() {};

	/**
	*  @brief Copy constructor (unavailable)
	*/
	DicomInterface(const DicomInterface&) = delete;

	/**
	*  @brief Operator "=" (unavailable)
	*/
	DicomInterface& operator=(const DicomInterface&) = delete;

	/**
	*  @brief Load DICOM image from set
	*
	*  @param none
	*  @return none
	*/
	void loadImage();

	/**
	*  @brief Load Tags form set
	*
	*  @param none
	*  @return none
	*/
	void loadAdminData();

	/**
	*  @brief Get data record by tag definition
	*
	*  @param [in] tag - DICOM tag definition(group id, element id)
	*  @return return data record if tag exist else retrun nullptr 
	*/
	DataRecord getDataRecord(imebra::TagId tag);

	/**
	*  @brief Set data to data records list
	*
	*  @param [in] tags - DICOM tags definition list
	*  @return none
	*/
	void setDataRecords(imebra::tagsIds_t tags);

public:
	/**
	*  @brief Get DICOM interface instance
	*
	*  @param none
	*  @return pointer to class instance
	*/
	static DicomInterface* getInstance();

	/**
	*  @brief Load DICOM data
	*
	*  @param [in] path - path to DICOM file 
	*  @return none
	*/
	void loadData(std::string path);

	/**
	*  @brief Get DICOM image
	*
	*  Get DICOM image from 0 index
	*  @return image buffer
	*/
	std::string getImage();

	/**
	*  @brief Get data record descriptiom list
	*
	*  Select tag description from data set, format and return
	*  @param none
	*  @return dicom data description vector
	*/
	std::vector<std::string> getDataRecordDescriptionList();

	/**
	*  @brief Get data record value list
	*
	*  Select tag value from data set, format and return
	*  @param none
	*  @return dicom data value vector
	*/
	std::vector<std::string> getDataRecordValueList();

	/**
	*  @brief Add data record to list
	*
	*  Check if tag with specified group id and element id exist,
	*  if yes add to the list and return new record
	*  @param [in] groupId - DICOM tag group ID
	*  @param [in] elementId - DICOM tag element ID
	*  @return DICOM data record
	*/
	DataRecord addDataRecord(uint16_t groupId, uint16_t elementId);

	/**
	*  @brief Get image data
	*
	*  @param none
	*  @return Pointer to image 
	*/
	ImageData* GetImageData();

	/**
	*  @brief 
	*
	*  @param
	*  @return
	*/
	void SetImageVOI(double center, double width);
};
