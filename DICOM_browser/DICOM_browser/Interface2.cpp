/**
*  @file    Interface2.cpp
*  @author  Jakub Maciag, Renata Rycyk, Emilia Siemieniuk, Paulina Nowak, Artur Tynecki
*  @date    May, 2017
*
*  @brief Interface for parts of GUI
*
*/

#include "DicomInterface.h"
#include "ImageData.h"
#include "imebra.h"
#include <iostream>
#include <vector>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <cmath>
#include "Interface2.h"


Interface2::Interface2()
{
}

#pragma region DICOM INTERFACE

///Load data from dicom file 
void Interface2::loadDicomData(std::string path)
{
	DicomInterface::getInstance()->loadData(path);
}

/**
*Taking image parameters from dicom data
*Creating image buffer
*Creating bitmap
*Fill bitmap from image buffer
*Marshal library to convert string to pixels
*/
Bitmap^ Interface2::loadDicomImage()
{
	uint32_t width = DicomInterface::getInstance()->GetImageData()->GetWidth();
	uint32_t height = DicomInterface::getInstance()->GetImageData()->GetHeight();
	std::string imageBuffer;

	/* Get DICOM image buffer */
	imageBuffer = DicomInterface::getInstance()->getImage();

	/* Create bitmap */
	Bitmap^ image = gcnew Bitmap(width, height);

	/* Set bitmap pixels */
	BitmapData^ bmpData = image->LockBits(System::Drawing::Rectangle(0, 0, width, height),
		ImageLockMode::ReadWrite, PixelFormat::Format32bppRgb);
	cli::array<Byte>^ pixels = gcnew cli::array<Byte>(imageBuffer.size());
	Marshal::Copy(IntPtr(&imageBuffer[0]), pixels, 0, imageBuffer.size());
	Marshal::Copy(pixels, 0, bmpData->Scan0, imageBuffer.size());
	image->UnlockBits(bmpData);
	return image;
}

/**
*Loading bitmap from dicom
*Setting bitmap as background of panel
*Setting size of panel as size of dicom image
*/
void Interface2::displayDicomImage(System::Windows::Forms::Panel^ panel1)
{
	Bitmap^ img = this->loadDicomImage();
	panel1->BackgroundImage = this->loadDicomImage();
	panel1->BackgroundImageLayout = ImageLayout::Tile;
	panel1->Height = panel1->BackgroundImage->Height;
	panel1->Width = panel1->BackgroundImage->Width;
}

#pragma endregion

#pragma region comboBoxes and textBoxes operating methods

/**
*Getting array of comboboxes
*Clearing items of every combobox
*/
void Interface2::clearCombos(array<ComboBox^>^ cL)
{
	for (int i = 0; i < cL->Length; i++)
	{
		cL[i]->Items->Clear();
		cL[i]->ResetText();
		cL[i]->Refresh();
	}
}

/**
*Getting array of textboxes
*Clearing text of every combobox
*/
void Interface2::clearText(array<TextBox^>^ tx)
{
	for (int i = 0; i < tx->Length; i++)
	{
		tx[i]->Clear();
		tx[i]->ResetText();
	}
}

/**
*Getting array of comboboxes and description vector from dicom
*Filling every combobox with data from description vector
*conversion from std::string to System::String^
*/
void Interface2::setItemsToCombo(array<ComboBox^>^ comboList, std::vector<std::string> desc)
{
	array<String^>^ stringArray1 = gcnew array<String^>(desc.size());
	for (int j = 0; j < comboList->Length; j++)
	{
		for (int i = 0; i < desc.size(); i++)
		{
			stringArray1[i] = gcnew String(desc[i].c_str());
			comboList[j]->Items->Add(stringArray1[i]);
		}
	}
}

/**
*Clearing main lists of data from dicom
*converting to System::String
*filling lists with data from dicom
*/
void Interface2::convertSTDtoList(std::vector<std::string> valS, std::vector<std::string> decS, System::Collections::Generic::List<String^>^ listVal, System::Collections::Generic::List<String^>^ listDesc)
{
	listVal->RemoveRange(0, listVal->Count);
	listDesc->RemoveRange(0, listDesc->Count);

	array<String^>^ stringArray2 = gcnew array<String^>(valS.size());
	array<String^>^ stringArray3 = gcnew array<String^>(decS.size());
	for (int j = 0; j < valS.size(); j++)
	{
		stringArray2[j] = gcnew String(valS[j].c_str());
		stringArray3[j] = gcnew String(decS[j].c_str());
	}
	for (int j = 0; j < stringArray2->Length; j++)
	{
		listVal->Add(stringArray2[j]);
		String^ temp = stringArray3[j];
		int index = temp->IndexOf("(");
		temp = temp->Remove(index);
		listDesc->Add(temp);
	}
}

/**
*Setting index of combobox
*getting index of selected item in combobox
*transfer it to adequate textbox and getting adequate value
*/
void Interface2::setValueSelected(int index, System::Collections::Generic::List<System::String^>^ listV, System::Collections::Generic::List<System::String^>^ listD, array<TextBox^>^ tBL, array<TextBox^>^ tBLF, array<ComboBox^>^ comboL) {
	int i = comboL[index]->SelectedIndex;
	tBL[index]->Text = listV[i];
	tBLF[index]->Text = listD[i];
	i = 0;
}

/**
*Clearing and filling combobox on panel with loaded data from list (by button)
*/
void Interface2::fillTagComboBox(System::Collections::Generic::List<String^>^ valueList, System::Windows::Forms::ComboBox^ tagC)
{
	tagC->Items->Clear();
	for each (String^ item in valueList)
	{
		tagC->Items->Add(item);
	}

}

#pragma endregion

#pragma region Save button function

void Interface2::savePanelToImageFile(System::Windows::Forms::Panel^ panel1)
{
	/* Show save image dialog */
	SaveFileDialog ^ saveImageDialog = gcnew SaveFileDialog();
	saveImageDialog->Filter =
		"JPG Image | *.jpg | JPEG Image | *.jpeg | Bitmap Image | *.bmp | GIF Image | *.gif | PNG Image | *.png | TIFF Image | *.tiff";
	saveImageDialog->Title = "Save result";
	saveImageDialog->RestoreDirectory = true;

	/* Get destination path and image extension */
	if ((saveImageDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) && (saveImageDialog->FileName != ""))
	{
		System::Drawing::Rectangle rc = panel1->ClientRectangle;
		Bitmap^ bmp = gcnew Bitmap(rc.Width, rc.Height);

		/* Draw panel to bitmap */
		panel1->DrawToBitmap(bmp, rc);

		/* Save bitmap to image file */
		bmp->Save(saveImageDialog->FileName);
	}
}

#pragma endregion