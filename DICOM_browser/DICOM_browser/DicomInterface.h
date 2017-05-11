#pragma once

#include <string>
#include <imebra.h>
#include "DicomData.h"

using namespace System::Drawing;
using namespace System;

class DicomInterface
{
private:
	std::unique_ptr<imebra::DataSet> dataSet;

	static DicomInterface* s_instance;
	static DicomData* dicomData;

	DicomInterface() {};
	DicomInterface(const DicomInterface&) = delete;
	DicomInterface& operator=(const DicomInterface&) = delete;

	void loadPatientName();
	void loadImage();

public:
	static DicomInterface* getInstance();
	~DicomInterface() {};
	void loadData(std::string path);
	Bitmap^ getImage();
	String^ getName();
};
