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

	DicomInterface::getInstance()->loadData("CT-MONO2-16-ankle");
	mainView.setImage(DicomInterface::getInstance()->getImage());
	mainView.setName(DicomInterface::getInstance()->getName());
	Application::Run(%mainView);
}

