#pragma once

/**
*  @file    DataRecord.h
*  @author  Artur Tynecki
*  @date    May, 2017
*
*  @brief Data Record class header file
*
* A class represetning DICOM data record. It contains tags information such as:
* tag description, tag group number, tag element number, tag value
*
*/

#include <string>

class DataRecord
{
private:
	std::string description;	/**< DICOM tag description */
	std::string value;			/**< DICOM tag value */
	uint16_t groupId;			/**< DICOM tag group ID */
	uint16_t elementId;			/**< DICOM tag element ID */

public:
	/**
	*  @brief Default constructor
	*/
	DataRecord();
	
	/**
	*  @brief Parameterized constructor
	*
	*  @param [in] description - DICOM tag description
	*  @param [in] value - DICOM tag value
	*  @param [in] groupId - DICOM tag groupId
	*  @param [in] elementId - DICOM tag elementId
	*/
	DataRecord(std::string description, std::string value, uint16_t groupId, uint16_t elementId);
	
	/**
	*  @brief Get description
	*
	*  @param none
	*  @return value of description member 
	*/
	std::string GetDescription();

	/**
	*  @brief Set description
	*
	*  @param [in] description - value of description
	*  @return none
	*/
	void SetDescription(std::string description);
	
	/**
	*  @brief Get value
	*
	*  @param none
	*  @return value of value member
	*/
	std::string GetValue();

	/**
	*  @brief Set value
	*
	*  @param [in] value - value to set
	*  @return none
	*/
	void SetValue(std::string value);
	
	/**
	*  @brief Get group ID
	*
	*  @param none
	*  @return value of group ID as number
	*/
	uint16_t GetGroupId();

	/**
	*  @brief Get group ID as string
	*
	*  @param none
	*  @return value of group ID as string
	*/
	std::string GetGroupIdAsString();

	/**
	*  @brief Set group ID
	*
	*  @param [in] groupId - value of group Id
	*  @return none
	*/
	void SetGroupId(uint16_t groupId);

	/**
	*  @brief Get element ID
	*
	*  @param none
	*  @return value of element ID as number
	*/
	uint16_t GetElementId();

	/**
	*  @brief Get element ID as string
	*
	*  @param none
	*  @return value of element ID as string
	*/
	std::string GetElementIdAsString();

	/**
	*  @brief Set element ID
	*
	*  @param [in] elementId - value of element ID
	*  @return none
	*/
	void SetElementId(uint16_t elementId);
};
