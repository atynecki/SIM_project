#pragma once

#include <string>
#include <imebra.h>
#include <list>
#include "DataRecord.h"

class DicomInterface
{
private:
	std::unique_ptr<imebra::DataSet> dataSet;
	std::unique_ptr<imebra::Image> image;
	std::list<DataRecord> dataRecordList;

	static DicomInterface* s_instance;

	DicomInterface() {};
	DicomInterface(const DicomInterface&) = delete;
	DicomInterface& operator=(const DicomInterface&) = delete;

	void loadImage();
	void loadAdminData();
	DataRecord getDataRecord(imebra::TagId tag);
	void setDataRecords(imebra::tagsIds_t tags);
	imebra::tagsIds_t loadConfigTags();

public:
	static DicomInterface* getInstance();
	~DicomInterface() {};
	void loadData(std::string path);
	std::string getImage(uint32_t* width, uint32_t* height);

	std::list<std::string> getDataRecordDescriptionList();
	std::list<std::string> getDataRecordValueList();

	DataRecord addDataRecord(uint16_t groupId, uint16_t elementId);
};
