#include "MainView.h"
#include "DicomInterface.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	DICOM_browser::MainView mainView;

	DicomInterface::getInstance()->loadDataSet();
	Bitmap^ image = DicomInterface::getInstance()->getImage(0);
	mainView.setImage(image);
	Application::Run(%mainView);
}

