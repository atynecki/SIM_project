
#include <string>
#include <imebra.h>

using namespace System::Drawing;

class DicomInterface
{
private:
	static DicomInterface* s_instance;
	DicomInterface() {};
	DicomInterface(const DicomInterface&) = delete;
	DicomInterface& operator=(const DicomInterface&) = delete;

	std::unique_ptr<imebra::DataSet> dataSet;

public:
	static DicomInterface* getInstance();
	~DicomInterface() {};
	std::string getPatientName();
	std::string getStudyDescription();
	void loadDataSet();
	Bitmap^ DicomInterface::getImage(int index);
};
