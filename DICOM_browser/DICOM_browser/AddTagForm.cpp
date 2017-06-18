/**
*  @file    AddTagForm.cpp
*  @author  Jakub Maci¹g
*  @date    May, 2017
*
*  @brief AddTagForm class source file
*
* A class represetning Windows Form to fill and add additional dicom tag.
* It contains textBoxessuch as: tag description, tag group number, tag element number, tag value
*
*/

#include "AddTagForm.h"
#include "MainView.h"
#include <vector>
#include <string>
#include <iostream>

using namespace Project2;
[STAThread]
void runAdd()
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::AddTagForm form;
	Application::Run(%form);
}