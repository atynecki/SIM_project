/**
*  @file    MainView.cpp
*  @author  Jakub Maciag
*  @date    May, 2017
*
*  @brief Dicom browser GUI
*
*
*
*/
#include "MainView.h"
#include <vector>
#include <string>
#include <iostream>

using namespace Project2;
[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MainView form;
	Application::Run(%form);
}



