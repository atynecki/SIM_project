#pragma once
/**
*  @file    Interface2.h
*  @author  Jakub Maciag, Renata Rycyk, Emilia Siemieniuk, Paulina Nowak, Artur Tynecki
*  @date    May, 2017
*
*  @brief Interface for parts of GUI
*
*/
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Runtime::InteropServices;
using namespace System::IO;

ref class Interface2
{
public:
	/**
	*  @brief Default constructor
	*/
	Interface2();

#pragma region DICOM INTERFACE
	/**
	*  @author Artur Tynecki
	*  @brief Loading DICOM DATA
	*
	*  @param [in] std::string path - path to DICOM file
	*  @return none
	*/
	void loadDicomData(std::string path);

	/**
	*  @author Artur Tynecki
	*  @brief Load Dicom Image
	*
	*  @param [in] none
	*  @return Bitmap object with DICOM Image
	*/
	Bitmap^ loadDicomImage();

	/**
	*  @author Artur Tynecki & Jakub Maci¹g
	*  @brief Loading DICOM image to panel
	*
	*  @param [in] System::Windows::Forms::Panel^ panel1
	*  @return none
	*/
	void displayDicomImage(System::Windows::Forms::Panel^ panel1);

#pragma endregion

#pragma region comboBoxes and textBoxes operating methods
	/**
	*  @author Renata Rycyk
	*  @brief clear combobox elements
	*
	*  @param [in] array<System::Windows::Forms::ComboBox^>^ cL - array of comboboxs
	*  @return none
	*/
	void clearCombos(array<System::Windows::Forms::ComboBox^>^ cL);

	/**
	*  @author Renata Rycyk
	*  @brief clear textbox elements
	*
	*  @param [in] array<System::Windows::Forms::TextBox^>^ tx - array of textboxs
	*  @return none
	*/
	void clearText(array<System::Windows::Forms::TextBox^>^ tx);

	/**
	*  @author Renata Rycyk
	*  @brief Loading DICOM DATA
	*
	*  @param [in] array<ComboBox^>^ comboList - array of comboboxes
	*  @param [in] std::vector<std::string> desc - vector of tag's description from dicom file
	*
	*  @return none
	*/
	void setItemsToCombo(array<ComboBox^>^ comboList, std::vector<std::string> desc);

	/**
	*  @author Jakub Maci¹g
	*  @brief Filling system list with dicom data
	*
	*  @param [in] std::vector<std::string> valS - vector of tag's value from dicom file
	*  @param [in] std::vector<std::string> decS - vector of tag's description from dicom file
	*  @param [in] System::Collections::Generic::List<String^>^ listVal
	*  @param [in] System::Collections::Generic::List<String^>^ listDesc
	*
	*  @return none
	*/
	void convertSTDtoList(std::vector<std::string> valS, std::vector<std::string> decS,
		System::Collections::Generic::List<String^>^ listVal, System::Collections::Generic::List<String^>^ listDesc);
	/**
	*  @author Jakub Maci¹g
	*  @brief Loading data to textboxes by selected data in combobox
	*
	*  @param [in] int index - index of array element
	*  @param [in] System::Collections::Generic::List<System::String^>^ listV - list of dicom tag's value
	*  @param [in] System::Collections::Generic::List<System::String^>^ listD - list of dicom tag's description
	*  @param [in] array<System::Windows::Forms::TextBox^>^ tBL - array of textboxes [value]
	*  @param [in] array<System::Windows::Forms::TextBox^>^ tBLF - array of textboxest [short description]
	*  @param [in] array<System::Windows::Forms::ComboBox^>^ comboL - array of comboboxes
	*  @return none
	*/
	void setValueSelected(int index, System::Collections::Generic::List<System::String^>^ listV,
		System::Collections::Generic::List<System::String^>^ listD,
		array<System::Windows::Forms::TextBox^>^ tBL, array<System::Windows::Forms::TextBox^>^ tBLF,
		array<System::Windows::Forms::ComboBox^>^ comboL);

	/**
	*  @author Emilia Siemieniuk and Paulina Nowak
	*  @brief Loading data from list to combobox's items
	*
	*  @param [in] System::Collections::Generic::List<System::String^>^ valueList - list of final loaded data
	*  @param [in] System::Windows::Forms::ComboBox^ tagC - active combobox on panel
	*  @return none
	*/
	void fillTagComboBox(System::Collections::Generic::List<System::String^>^ valueList, System::Windows::Forms::ComboBox^ tagC);

#pragma endregion

#pragma region Save button

	/**
	*  @author Artur Tynecki, Renata Rycyk
	*  @brief Save button function
	*
	*  @param [in] System::Windows::Forms::Panel^ panel1 - panel with Dicom Image and Tags
	*
	*/
	void savePanelToImageFile(System::Windows::Forms::Panel^ panel1);

#pragma endregion
};


