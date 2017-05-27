#include "DataRecord.h"

#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

DataRecord::DataRecord()
{
	this->groupId = 0;
	this->elementId = 0;
}

DataRecord::DataRecord(string description, string value, uint16_t groupId, uint16_t elementId)
{
	this->description = description;
	this->value = value;
	this->groupId = groupId;
	this->elementId = elementId;
}

string DataRecord::GetDescription()
{
	return this->description;
}

void DataRecord::SetDescription(string description)
{
	this->description = description;
}

string DataRecord::GetValue()
{
	return this->value;
}

void DataRecord::SetValue(string value)
{
	this->value = value;
}

uint16_t DataRecord::GetGroupId()
{
	return this->groupId;
}

string DataRecord::GetGroupIdAsString()
{
	string hexStr;

	std::stringstream sstream;
	sstream << "0x"
		<< std::setfill('0') << std::setw(4)
		<< std::hex << this->groupId;

	hexStr = sstream.str();
	sstream.clear();

	return hexStr;
}

void DataRecord::SetGroupId(uint16_t groupId)
{
	this->groupId = groupId;
}

uint16_t DataRecord::GetElementId()
{
	return this->elementId;
}

void DataRecord::SetElementId(uint16_t elementId)
{
	this->elementId = elementId;
}

string DataRecord::GetElementIdAsString()
{
	string hexStr;

	std::stringstream sstream;
	sstream << "0x"
		<< std::setfill('0') << std::setw(4)
		<< std::hex << this->elementId;

	hexStr = sstream.str();
	sstream.clear();

	return hexStr;
}