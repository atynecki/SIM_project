#pragma once

#include <string>

class DataRecord
{
private:
	std::string description;
	std::string value;
	uint16_t groupId;
	uint16_t elementId;

public:
	DataRecord();
	DataRecord(std::string description, std::string value, uint16_t groupId, uint16_t elementId);
	std::string GetDescription();
	void SetDescription(std::string description);
	std::string GetValue();
	void SetValue(std::string value);
	uint16_t GetGroupId();
	std::string GetGroupIdAsString();
	void SetGroupId(uint16_t groupId);
	uint16_t GetElementId();
	void SetElementId(uint16_t elementId);
	std::string GetElementIdAsString();
};
