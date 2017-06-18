
#pragma once
/**
*  @file    MainView.h
*  @author  Jakub Maciag
*  @date    May, 2017
*
*  @brief Dicom browser GUI
*
*
*
*/
#include "DicomInterface.h"
#include "ImageData.h"
#include "imebra.h"
#include <iostream>
#include <vector>
#include <string>
#include "AddTagForm.h"
#include <msclr\marshal_cppstd.h>
#include <cmath>
#include "Interface2.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;



#pragma region GUI
	/// <summary>
	/// Summary for MainView
	/// </summary>
	public ref class MainView : public System::Windows::Forms::Form
	{
	public:
		MainView(void)
		{
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainView()
		{
			if (components)
			{
				delete components;
				delete interX;
				delete image;
				delete comboList;
				delete textBoxList;
				delete textBoxFList;
				delete listVal;
				delete listDesc;
				delete dataLX;


			}
		}
	private:Bitmap^ image;
	private:Interface2^ interX = gcnew Interface2();
	private:array<ComboBox^>^ comboList = gcnew array <ComboBox^>(50);
	private:array<TextBox^>^ textBoxList = gcnew array <TextBox^>(50);
	private:array<TextBox^>^ textBoxFList = gcnew array <TextBox^>(50);
	private:System::Collections::Generic::List<String^>^ listVal = gcnew System::Collections::Generic::List<String^>();
	private:System::Collections::Generic::List<String^>^ listDesc = gcnew System::Collections::Generic::List<String^>();
	private:System::Collections::Generic::List<String^>^ dataLX = gcnew System::Collections::Generic::List<String^>();
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::ComboBox^  tagsComboBox;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::ComboBox^  comboBox7;
	private: System::Windows::Forms::ComboBox^  comboBox8;
	private: System::Windows::Forms::ComboBox^  comboBox9;
	private: System::Windows::Forms::ComboBox^  comboBox10;
	private: System::Windows::Forms::ComboBox^  comboBox11;
	private: System::Windows::Forms::ComboBox^  comboBox12;
	private: System::Windows::Forms::ComboBox^  comboBox13;
	private: System::Windows::Forms::ComboBox^  comboBox14;
	private: System::Windows::Forms::ComboBox^  comboBox15;
	private: System::Windows::Forms::ComboBox^  comboBox16;
	private: System::Windows::Forms::ComboBox^  comboBox17;
	private: System::Windows::Forms::ComboBox^  comboBox18;
	private: System::Windows::Forms::ComboBox^  comboBox19;
	private: System::Windows::Forms::ComboBox^  comboBox20;
	private: System::Windows::Forms::ComboBox^  comboBox21;
	private: System::Windows::Forms::ComboBox^  comboBox22;
	private: System::Windows::Forms::ComboBox^  comboBox23;
	private: System::Windows::Forms::ComboBox^  comboBox24;
	private: System::Windows::Forms::ComboBox^  comboBox25;
	private: System::Windows::Forms::ComboBox^  comboBox26;
	private: System::Windows::Forms::ComboBox^  comboBox27;
	private: System::Windows::Forms::ComboBox^  comboBox28;
	private: System::Windows::Forms::ComboBox^  comboBox29;
	private: System::Windows::Forms::ComboBox^  comboBox30;
	private: System::Windows::Forms::ComboBox^  comboBox31;
	private: System::Windows::Forms::ComboBox^  comboBox32;
	private: System::Windows::Forms::ComboBox^  comboBox33;
	private: System::Windows::Forms::ComboBox^  comboBox34;
	private: System::Windows::Forms::ComboBox^  comboBox35;
	private: System::Windows::Forms::ComboBox^  comboBox36;
	private: System::Windows::Forms::ComboBox^  comboBox37;
	private: System::Windows::Forms::ComboBox^  comboBox38;
	private: System::Windows::Forms::ComboBox^  comboBox39;
	private: System::Windows::Forms::ComboBox^  comboBox40;
	private: System::Windows::Forms::ComboBox^  comboBox41;
	private: System::Windows::Forms::ComboBox^  comboBox42;
	private: System::Windows::Forms::ComboBox^  comboBox43;
	private: System::Windows::Forms::ComboBox^  comboBox44;
	private: System::Windows::Forms::ComboBox^  comboBox45;
	private: System::Windows::Forms::ComboBox^  comboBox46;
	private: System::Windows::Forms::ComboBox^  comboBox47;
	private: System::Windows::Forms::ComboBox^  comboBox48;
	private: System::Windows::Forms::ComboBox^  comboBox49;
	private: System::Windows::Forms::ComboBox^  comboBox50;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::TextBox^  textBox26;
	private: System::Windows::Forms::TextBox^  textBox27;
	private: System::Windows::Forms::TextBox^  textBox28;
	private: System::Windows::Forms::TextBox^  textBox29;
	private: System::Windows::Forms::TextBox^  textBox30;
	private: System::Windows::Forms::TextBox^  textBox31;
	private: System::Windows::Forms::TextBox^  textBox32;
	private: System::Windows::Forms::TextBox^  textBox33;
	private: System::Windows::Forms::TextBox^  textBox34;
	private: System::Windows::Forms::TextBox^  textBox35;
	private: System::Windows::Forms::TextBox^  textBox36;
	private: System::Windows::Forms::TextBox^  textBox37;
	private: System::Windows::Forms::TextBox^  textBox38;
	private: System::Windows::Forms::TextBox^  textBox39;
	private: System::Windows::Forms::TextBox^  textBox40;
	private: System::Windows::Forms::TextBox^  textBox41;
	private: System::Windows::Forms::TextBox^  textBox42;
	private: System::Windows::Forms::TextBox^  textBox43;
	private: System::Windows::Forms::TextBox^  textBox44;
	private: System::Windows::Forms::TextBox^  textBox45;
	private: System::Windows::Forms::TextBox^  textBox46;
	private: System::Windows::Forms::TextBox^  textBox47;
	private: System::Windows::Forms::TextBox^  textBox48;
	private: System::Windows::Forms::TextBox^  textBox49;
	private: System::Windows::Forms::TextBox^  textBox50;
	private: System::Windows::Forms::TextBox^  textBox51;
	private: System::Windows::Forms::TextBox^  textBox52;
	private: System::Windows::Forms::TextBox^  textBox53;
	private: System::Windows::Forms::TextBox^  textBox54;
	private: System::Windows::Forms::TextBox^  textBox55;
	private: System::Windows::Forms::TextBox^  textBox56;
	private: System::Windows::Forms::TextBox^  textBox57;
	private: System::Windows::Forms::TextBox^  textBox58;
	private: System::Windows::Forms::TextBox^  textBox59;
	private: System::Windows::Forms::TextBox^  textBox60;
	private: System::Windows::Forms::TextBox^  textBox61;
	private: System::Windows::Forms::TextBox^  textBox62;
	private: System::Windows::Forms::TextBox^  textBox63;
	private: System::Windows::Forms::TextBox^  textBox64;
	private: System::Windows::Forms::TextBox^  textBox65;
	private: System::Windows::Forms::TextBox^  textBox66;
	private: System::Windows::Forms::TextBox^  textBox67;
	private: System::Windows::Forms::TextBox^  textBox68;
	private: System::Windows::Forms::TextBox^  textBox69;
	private: System::Windows::Forms::TextBox^  textBox70;
	private: System::Windows::Forms::TextBox^  textBox71;
	private: System::Windows::Forms::TextBox^  textBox72;
	private: System::Windows::Forms::TextBox^  textBox73;
	private: System::Windows::Forms::TextBox^  textBox74;
	private: System::Windows::Forms::TextBox^  textBox75;
	private: System::Windows::Forms::TextBox^  textBox76;
	private: System::Windows::Forms::TextBox^  textBox77;
	private: System::Windows::Forms::TextBox^  textBox78;
	private: System::Windows::Forms::TextBox^  textBox79;
	private: System::Windows::Forms::TextBox^  textBox80;
	private: System::Windows::Forms::TextBox^  textBox81;
	private: System::Windows::Forms::TextBox^  textBox82;
	private: System::Windows::Forms::TextBox^  textBox83;
	private: System::Windows::Forms::TextBox^  textBox84;
	private: System::Windows::Forms::TextBox^  textBox85;
	private: System::Windows::Forms::TextBox^  textBox86;
	private: System::Windows::Forms::TextBox^  textBox87;
	private: System::Windows::Forms::TextBox^  textBox88;
	private: System::Windows::Forms::TextBox^  textBox89;
	private: System::Windows::Forms::TextBox^  textBox90;
	private: System::Windows::Forms::TextBox^  textBox91;
	private: System::Windows::Forms::TextBox^  textBox92;
	private: System::Windows::Forms::TextBox^  textBox93;
	private: System::Windows::Forms::TextBox^  textBox94;
	private: System::Windows::Forms::TextBox^  textBox95;
	private: System::Windows::Forms::TextBox^  textBox96;
	private: System::Windows::Forms::TextBox^  textBox97;
	private: System::Windows::Forms::TextBox^  textBox98;
	private: System::Windows::Forms::TextBox^  textBox99;
	private: System::Windows::Forms::TextBox^  textBox100;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  info1;
	private: System::Windows::Forms::Label^  info2;
	private: System::Windows::Forms::Label^  info3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;



	protected:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox10 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox11 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox12 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox13 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox14 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox15 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox16 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox17 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox18 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox19 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox20 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox21 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox22 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox23 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox24 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox25 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox26 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox27 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox28 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox29 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox30 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox31 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox32 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox33 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox34 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox35 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox36 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox37 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox38 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox39 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox40 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox41 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox42 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox43 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox44 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox45 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox46 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox47 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox48 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox49 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox50 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->textBox34 = (gcnew System::Windows::Forms::TextBox());
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->textBox39 = (gcnew System::Windows::Forms::TextBox());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->textBox41 = (gcnew System::Windows::Forms::TextBox());
			this->textBox42 = (gcnew System::Windows::Forms::TextBox());
			this->textBox43 = (gcnew System::Windows::Forms::TextBox());
			this->textBox44 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45 = (gcnew System::Windows::Forms::TextBox());
			this->textBox46 = (gcnew System::Windows::Forms::TextBox());
			this->textBox47 = (gcnew System::Windows::Forms::TextBox());
			this->textBox48 = (gcnew System::Windows::Forms::TextBox());
			this->textBox49 = (gcnew System::Windows::Forms::TextBox());
			this->textBox50 = (gcnew System::Windows::Forms::TextBox());
			this->textBox51 = (gcnew System::Windows::Forms::TextBox());
			this->textBox52 = (gcnew System::Windows::Forms::TextBox());
			this->textBox53 = (gcnew System::Windows::Forms::TextBox());
			this->textBox54 = (gcnew System::Windows::Forms::TextBox());
			this->textBox55 = (gcnew System::Windows::Forms::TextBox());
			this->textBox56 = (gcnew System::Windows::Forms::TextBox());
			this->textBox57 = (gcnew System::Windows::Forms::TextBox());
			this->textBox58 = (gcnew System::Windows::Forms::TextBox());
			this->textBox59 = (gcnew System::Windows::Forms::TextBox());
			this->textBox60 = (gcnew System::Windows::Forms::TextBox());
			this->textBox61 = (gcnew System::Windows::Forms::TextBox());
			this->textBox62 = (gcnew System::Windows::Forms::TextBox());
			this->textBox63 = (gcnew System::Windows::Forms::TextBox());
			this->textBox64 = (gcnew System::Windows::Forms::TextBox());
			this->textBox65 = (gcnew System::Windows::Forms::TextBox());
			this->textBox66 = (gcnew System::Windows::Forms::TextBox());
			this->textBox67 = (gcnew System::Windows::Forms::TextBox());
			this->textBox68 = (gcnew System::Windows::Forms::TextBox());
			this->textBox70 = (gcnew System::Windows::Forms::TextBox());
			this->textBox71 = (gcnew System::Windows::Forms::TextBox());
			this->textBox72 = (gcnew System::Windows::Forms::TextBox());
			this->textBox73 = (gcnew System::Windows::Forms::TextBox());
			this->textBox74 = (gcnew System::Windows::Forms::TextBox());
			this->textBox75 = (gcnew System::Windows::Forms::TextBox());
			this->textBox76 = (gcnew System::Windows::Forms::TextBox());
			this->textBox77 = (gcnew System::Windows::Forms::TextBox());
			this->textBox78 = (gcnew System::Windows::Forms::TextBox());
			this->textBox79 = (gcnew System::Windows::Forms::TextBox());
			this->textBox80 = (gcnew System::Windows::Forms::TextBox());
			this->textBox81 = (gcnew System::Windows::Forms::TextBox());
			this->textBox82 = (gcnew System::Windows::Forms::TextBox());
			this->textBox83 = (gcnew System::Windows::Forms::TextBox());
			this->textBox84 = (gcnew System::Windows::Forms::TextBox());
			this->textBox85 = (gcnew System::Windows::Forms::TextBox());
			this->textBox86 = (gcnew System::Windows::Forms::TextBox());
			this->textBox87 = (gcnew System::Windows::Forms::TextBox());
			this->textBox88 = (gcnew System::Windows::Forms::TextBox());
			this->textBox89 = (gcnew System::Windows::Forms::TextBox());
			this->textBox90 = (gcnew System::Windows::Forms::TextBox());
			this->textBox91 = (gcnew System::Windows::Forms::TextBox());
			this->textBox92 = (gcnew System::Windows::Forms::TextBox());
			this->textBox93 = (gcnew System::Windows::Forms::TextBox());
			this->textBox94 = (gcnew System::Windows::Forms::TextBox());
			this->textBox95 = (gcnew System::Windows::Forms::TextBox());
			this->textBox96 = (gcnew System::Windows::Forms::TextBox());
			this->textBox97 = (gcnew System::Windows::Forms::TextBox());
			this->textBox98 = (gcnew System::Windows::Forms::TextBox());
			this->textBox99 = (gcnew System::Windows::Forms::TextBox());
			this->textBox100 = (gcnew System::Windows::Forms::TextBox());
			this->textBox69 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tagsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->info1 = (gcnew System::Windows::Forms::Label());
			this->info2 = (gcnew System::Windows::Forms::Label());
			this->info3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoScroll = true;
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				200)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				259)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				251)));
			this->tableLayoutPanel1->Controls->Add(this->comboBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->comboBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->comboBox3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->comboBox4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->comboBox5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->comboBox6, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->comboBox7, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->comboBox8, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->comboBox9, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->comboBox10, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->comboBox11, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->comboBox12, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->comboBox13, 0, 12);
			this->tableLayoutPanel1->Controls->Add(this->comboBox14, 0, 13);
			this->tableLayoutPanel1->Controls->Add(this->comboBox15, 0, 14);
			this->tableLayoutPanel1->Controls->Add(this->comboBox16, 0, 15);
			this->tableLayoutPanel1->Controls->Add(this->comboBox17, 0, 16);
			this->tableLayoutPanel1->Controls->Add(this->comboBox18, 0, 17);
			this->tableLayoutPanel1->Controls->Add(this->comboBox19, 0, 18);
			this->tableLayoutPanel1->Controls->Add(this->comboBox20, 0, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox3, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox4, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox5, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->textBox6, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox7, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox8, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox9, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox10, 1, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox11, 1, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox12, 1, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox13, 1, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox14, 1, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox15, 1, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox16, 1, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox17, 1, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox18, 1, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox19, 1, 18);
			this->tableLayoutPanel1->Controls->Add(this->textBox20, 1, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->comboBox21, 0, 20);
			this->tableLayoutPanel1->Controls->Add(this->comboBox22, 0, 21);
			this->tableLayoutPanel1->Controls->Add(this->comboBox23, 0, 22);
			this->tableLayoutPanel1->Controls->Add(this->comboBox24, 0, 23);
			this->tableLayoutPanel1->Controls->Add(this->comboBox25, 0, 24);
			this->tableLayoutPanel1->Controls->Add(this->comboBox26, 0, 25);
			this->tableLayoutPanel1->Controls->Add(this->comboBox27, 0, 26);
			this->tableLayoutPanel1->Controls->Add(this->comboBox28, 0, 27);
			this->tableLayoutPanel1->Controls->Add(this->comboBox29, 0, 28);
			this->tableLayoutPanel1->Controls->Add(this->comboBox30, 0, 29);
			this->tableLayoutPanel1->Controls->Add(this->comboBox31, 0, 30);
			this->tableLayoutPanel1->Controls->Add(this->comboBox32, 0, 31);
			this->tableLayoutPanel1->Controls->Add(this->comboBox33, 0, 32);
			this->tableLayoutPanel1->Controls->Add(this->comboBox34, 0, 33);
			this->tableLayoutPanel1->Controls->Add(this->comboBox35, 0, 34);
			this->tableLayoutPanel1->Controls->Add(this->comboBox36, 0, 35);
			this->tableLayoutPanel1->Controls->Add(this->comboBox37, 0, 36);
			this->tableLayoutPanel1->Controls->Add(this->comboBox38, 0, 37);
			this->tableLayoutPanel1->Controls->Add(this->comboBox39, 0, 38);
			this->tableLayoutPanel1->Controls->Add(this->comboBox40, 0, 39);
			this->tableLayoutPanel1->Controls->Add(this->comboBox41, 0, 40);
			this->tableLayoutPanel1->Controls->Add(this->comboBox42, 0, 41);
			this->tableLayoutPanel1->Controls->Add(this->comboBox43, 0, 42);
			this->tableLayoutPanel1->Controls->Add(this->comboBox44, 0, 43);
			this->tableLayoutPanel1->Controls->Add(this->comboBox45, 0, 44);
			this->tableLayoutPanel1->Controls->Add(this->comboBox46, 0, 45);
			this->tableLayoutPanel1->Controls->Add(this->comboBox47, 0, 46);
			this->tableLayoutPanel1->Controls->Add(this->comboBox48, 0, 47);
			this->tableLayoutPanel1->Controls->Add(this->comboBox49, 0, 48);
			this->tableLayoutPanel1->Controls->Add(this->comboBox50, 0, 49);
			this->tableLayoutPanel1->Controls->Add(this->textBox21, 1, 20);
			this->tableLayoutPanel1->Controls->Add(this->textBox22, 1, 21);
			this->tableLayoutPanel1->Controls->Add(this->textBox23, 1, 22);
			this->tableLayoutPanel1->Controls->Add(this->textBox24, 1, 23);
			this->tableLayoutPanel1->Controls->Add(this->textBox25, 1, 24);
			this->tableLayoutPanel1->Controls->Add(this->textBox26, 1, 25);
			this->tableLayoutPanel1->Controls->Add(this->textBox27, 1, 26);
			this->tableLayoutPanel1->Controls->Add(this->textBox28, 1, 27);
			this->tableLayoutPanel1->Controls->Add(this->textBox29, 1, 28);
			this->tableLayoutPanel1->Controls->Add(this->textBox30, 1, 29);
			this->tableLayoutPanel1->Controls->Add(this->textBox31, 1, 30);
			this->tableLayoutPanel1->Controls->Add(this->textBox32, 1, 31);
			this->tableLayoutPanel1->Controls->Add(this->textBox33, 1, 32);
			this->tableLayoutPanel1->Controls->Add(this->textBox34, 1, 33);
			this->tableLayoutPanel1->Controls->Add(this->textBox35, 1, 34);
			this->tableLayoutPanel1->Controls->Add(this->textBox36, 1, 35);
			this->tableLayoutPanel1->Controls->Add(this->textBox37, 1, 36);
			this->tableLayoutPanel1->Controls->Add(this->textBox38, 1, 37);
			this->tableLayoutPanel1->Controls->Add(this->textBox39, 1, 38);
			this->tableLayoutPanel1->Controls->Add(this->textBox40, 1, 39);
			this->tableLayoutPanel1->Controls->Add(this->textBox41, 1, 40);
			this->tableLayoutPanel1->Controls->Add(this->textBox42, 1, 41);
			this->tableLayoutPanel1->Controls->Add(this->textBox43, 1, 42);
			this->tableLayoutPanel1->Controls->Add(this->textBox44, 1, 43);
			this->tableLayoutPanel1->Controls->Add(this->textBox45, 1, 44);
			this->tableLayoutPanel1->Controls->Add(this->textBox46, 1, 45);
			this->tableLayoutPanel1->Controls->Add(this->textBox47, 1, 46);
			this->tableLayoutPanel1->Controls->Add(this->textBox48, 1, 47);
			this->tableLayoutPanel1->Controls->Add(this->textBox49, 1, 48);
			this->tableLayoutPanel1->Controls->Add(this->textBox50, 1, 49);
			this->tableLayoutPanel1->Controls->Add(this->textBox51, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox52, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox53, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox54, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox55, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->textBox56, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox57, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox58, 2, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox59, 2, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox60, 2, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox61, 2, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox62, 2, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox63, 2, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox64, 2, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox65, 2, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox66, 2, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox67, 2, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox68, 2, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox70, 2, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox71, 2, 20);
			this->tableLayoutPanel1->Controls->Add(this->textBox72, 2, 21);
			this->tableLayoutPanel1->Controls->Add(this->textBox73, 2, 22);
			this->tableLayoutPanel1->Controls->Add(this->textBox74, 2, 23);
			this->tableLayoutPanel1->Controls->Add(this->textBox75, 2, 24);
			this->tableLayoutPanel1->Controls->Add(this->textBox76, 2, 25);
			this->tableLayoutPanel1->Controls->Add(this->textBox77, 2, 26);
			this->tableLayoutPanel1->Controls->Add(this->textBox78, 2, 27);
			this->tableLayoutPanel1->Controls->Add(this->textBox79, 2, 28);
			this->tableLayoutPanel1->Controls->Add(this->textBox80, 2, 29);
			this->tableLayoutPanel1->Controls->Add(this->textBox81, 2, 30);
			this->tableLayoutPanel1->Controls->Add(this->textBox82, 2, 31);
			this->tableLayoutPanel1->Controls->Add(this->textBox83, 2, 32);
			this->tableLayoutPanel1->Controls->Add(this->textBox84, 2, 33);
			this->tableLayoutPanel1->Controls->Add(this->textBox85, 2, 34);
			this->tableLayoutPanel1->Controls->Add(this->textBox86, 2, 35);
			this->tableLayoutPanel1->Controls->Add(this->textBox87, 2, 36);
			this->tableLayoutPanel1->Controls->Add(this->textBox88, 2, 37);
			this->tableLayoutPanel1->Controls->Add(this->textBox89, 2, 38);
			this->tableLayoutPanel1->Controls->Add(this->textBox90, 2, 39);
			this->tableLayoutPanel1->Controls->Add(this->textBox91, 2, 40);
			this->tableLayoutPanel1->Controls->Add(this->textBox92, 2, 41);
			this->tableLayoutPanel1->Controls->Add(this->textBox93, 2, 42);
			this->tableLayoutPanel1->Controls->Add(this->textBox94, 2, 43);
			this->tableLayoutPanel1->Controls->Add(this->textBox95, 2, 44);
			this->tableLayoutPanel1->Controls->Add(this->textBox96, 2, 45);
			this->tableLayoutPanel1->Controls->Add(this->textBox97, 2, 46);
			this->tableLayoutPanel1->Controls->Add(this->textBox98, 2, 47);
			this->tableLayoutPanel1->Controls->Add(this->textBox99, 2, 48);
			this->tableLayoutPanel1->Controls->Add(this->textBox100, 2, 49);
			this->tableLayoutPanel1->Controls->Add(this->textBox69, 2, 18);
			this->tableLayoutPanel1->Location = System::Drawing::Point(14, 82);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 50;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(710, 1084);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(3, 2);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox1->MaxLength = 700;
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(193, 28);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox_SelectionChangeCommitted);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(3, 32);
			this->comboBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(193, 28);
			this->comboBox2->TabIndex = 1;
			this->comboBox2->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox2_SelectionChangeCommitted);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(3, 62);
			this->comboBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(193, 28);
			this->comboBox3->TabIndex = 2;
			this->comboBox3->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox3_SelectionChangeCommitted);
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(3, 92);
			this->comboBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(193, 28);
			this->comboBox4->TabIndex = 3;
			this->comboBox4->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox4_SelectionChangeCommitted);
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(3, 122);
			this->comboBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(193, 28);
			this->comboBox5->TabIndex = 4;
			this->comboBox5->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox5_SelectionChangeCommitted);
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Location = System::Drawing::Point(3, 152);
			this->comboBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(193, 28);
			this->comboBox6->TabIndex = 5;
			this->comboBox6->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox6_SelectionChangeCommitted);
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Location = System::Drawing::Point(3, 182);
			this->comboBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(193, 28);
			this->comboBox7->TabIndex = 6;
			this->comboBox7->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox7_SelectionChangeCommitted);
			// 
			// comboBox8
			// 
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Location = System::Drawing::Point(3, 212);
			this->comboBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(193, 28);
			this->comboBox8->TabIndex = 7;
			this->comboBox8->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox8_SelectionChangeCommitted);
			// 
			// comboBox9
			// 
			this->comboBox9->FormattingEnabled = true;
			this->comboBox9->Location = System::Drawing::Point(3, 242);
			this->comboBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox9->Name = L"comboBox9";
			this->comboBox9->Size = System::Drawing::Size(193, 28);
			this->comboBox9->TabIndex = 8;
			this->comboBox9->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox9_SelectionChangeCommitted);
			// 
			// comboBox10
			// 
			this->comboBox10->FormattingEnabled = true;
			this->comboBox10->Location = System::Drawing::Point(3, 272);
			this->comboBox10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox10->Name = L"comboBox10";
			this->comboBox10->Size = System::Drawing::Size(193, 28);
			this->comboBox10->TabIndex = 9;
			this->comboBox10->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox10_SelectionChangeCommitted);
			// 
			// comboBox11
			// 
			this->comboBox11->FormattingEnabled = true;
			this->comboBox11->Location = System::Drawing::Point(3, 302);
			this->comboBox11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox11->Name = L"comboBox11";
			this->comboBox11->Size = System::Drawing::Size(193, 28);
			this->comboBox11->TabIndex = 10;
			this->comboBox11->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox11_SelectionChangeCommitted);
			// 
			// comboBox12
			// 
			this->comboBox12->FormattingEnabled = true;
			this->comboBox12->Location = System::Drawing::Point(3, 332);
			this->comboBox12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox12->Name = L"comboBox12";
			this->comboBox12->Size = System::Drawing::Size(193, 28);
			this->comboBox12->TabIndex = 11;
			this->comboBox12->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox12_SelectionChangeCommitted);
			// 
			// comboBox13
			// 
			this->comboBox13->FormattingEnabled = true;
			this->comboBox13->Location = System::Drawing::Point(3, 362);
			this->comboBox13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox13->Name = L"comboBox13";
			this->comboBox13->Size = System::Drawing::Size(193, 28);
			this->comboBox13->TabIndex = 12;
			this->comboBox13->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox13_SelectionChangeCommitted);
			// 
			// comboBox14
			// 
			this->comboBox14->FormattingEnabled = true;
			this->comboBox14->Location = System::Drawing::Point(3, 392);
			this->comboBox14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox14->Name = L"comboBox14";
			this->comboBox14->Size = System::Drawing::Size(193, 28);
			this->comboBox14->TabIndex = 13;
			this->comboBox14->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox14_SelectionChangeCommitted);
			// 
			// comboBox15
			// 
			this->comboBox15->FormattingEnabled = true;
			this->comboBox15->Location = System::Drawing::Point(3, 422);
			this->comboBox15->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox15->Name = L"comboBox15";
			this->comboBox15->Size = System::Drawing::Size(193, 28);
			this->comboBox15->TabIndex = 14;
			this->comboBox15->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox15_SelectionChangeCommitted);
			// 
			// comboBox16
			// 
			this->comboBox16->FormattingEnabled = true;
			this->comboBox16->Location = System::Drawing::Point(3, 452);
			this->comboBox16->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox16->Name = L"comboBox16";
			this->comboBox16->Size = System::Drawing::Size(193, 28);
			this->comboBox16->TabIndex = 15;
			this->comboBox16->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox16_SelectionChangeCommitted);
			// 
			// comboBox17
			// 
			this->comboBox17->FormattingEnabled = true;
			this->comboBox17->Location = System::Drawing::Point(3, 482);
			this->comboBox17->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox17->Name = L"comboBox17";
			this->comboBox17->Size = System::Drawing::Size(193, 28);
			this->comboBox17->TabIndex = 16;
			this->comboBox17->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox17_SelectionChangeCommitted);
			// 
			// comboBox18
			// 
			this->comboBox18->FormattingEnabled = true;
			this->comboBox18->Location = System::Drawing::Point(3, 512);
			this->comboBox18->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox18->Name = L"comboBox18";
			this->comboBox18->Size = System::Drawing::Size(193, 28);
			this->comboBox18->TabIndex = 17;
			this->comboBox18->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox18_SelectionChangeCommitted);
			// 
			// comboBox19
			// 
			this->comboBox19->FormattingEnabled = true;
			this->comboBox19->Location = System::Drawing::Point(3, 542);
			this->comboBox19->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox19->Name = L"comboBox19";
			this->comboBox19->Size = System::Drawing::Size(193, 28);
			this->comboBox19->TabIndex = 18;
			this->comboBox19->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox19_SelectionChangeCommitted);
			// 
			// comboBox20
			// 
			this->comboBox20->FormattingEnabled = true;
			this->comboBox20->Location = System::Drawing::Point(3, 572);
			this->comboBox20->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox20->Name = L"comboBox20";
			this->comboBox20->Size = System::Drawing::Size(193, 28);
			this->comboBox20->TabIndex = 19;
			this->comboBox20->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox20_SelectionChangeCommitted);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(203, 32);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(250, 26);
			this->textBox2->TabIndex = 21;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(203, 62);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(250, 26);
			this->textBox3->TabIndex = 22;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(203, 92);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(250, 26);
			this->textBox4->TabIndex = 23;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(203, 122);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(250, 26);
			this->textBox5->TabIndex = 24;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(203, 152);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(250, 26);
			this->textBox6->TabIndex = 25;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(203, 182);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(250, 26);
			this->textBox7->TabIndex = 26;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(203, 212);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(250, 26);
			this->textBox8->TabIndex = 27;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(203, 242);
			this->textBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(250, 26);
			this->textBox9->TabIndex = 28;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(203, 272);
			this->textBox10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(250, 26);
			this->textBox10->TabIndex = 29;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(203, 302);
			this->textBox11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(250, 26);
			this->textBox11->TabIndex = 30;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(203, 332);
			this->textBox12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(250, 26);
			this->textBox12->TabIndex = 31;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(203, 362);
			this->textBox13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(250, 26);
			this->textBox13->TabIndex = 32;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(203, 392);
			this->textBox14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(250, 26);
			this->textBox14->TabIndex = 33;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(203, 422);
			this->textBox15->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(250, 26);
			this->textBox15->TabIndex = 34;
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(203, 452);
			this->textBox16->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(250, 26);
			this->textBox16->TabIndex = 35;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(203, 482);
			this->textBox17->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(250, 26);
			this->textBox17->TabIndex = 36;
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(203, 512);
			this->textBox18->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(250, 26);
			this->textBox18->TabIndex = 37;
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(203, 542);
			this->textBox19->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(250, 26);
			this->textBox19->TabIndex = 38;
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(203, 572);
			this->textBox20->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(250, 26);
			this->textBox20->TabIndex = 39;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(203, 2);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(250, 26);
			this->textBox1->TabIndex = 20;
			// 
			// comboBox21
			// 
			this->comboBox21->FormattingEnabled = true;
			this->comboBox21->Location = System::Drawing::Point(3, 602);
			this->comboBox21->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox21->Name = L"comboBox21";
			this->comboBox21->Size = System::Drawing::Size(193, 28);
			this->comboBox21->TabIndex = 40;
			this->comboBox21->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox21_SelectionChangeCommitted);
			// 
			// comboBox22
			// 
			this->comboBox22->FormattingEnabled = true;
			this->comboBox22->Location = System::Drawing::Point(3, 632);
			this->comboBox22->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox22->Name = L"comboBox22";
			this->comboBox22->Size = System::Drawing::Size(193, 28);
			this->comboBox22->TabIndex = 41;
			this->comboBox22->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox22_SelectionChangeCommitted);
			// 
			// comboBox23
			// 
			this->comboBox23->FormattingEnabled = true;
			this->comboBox23->Location = System::Drawing::Point(3, 662);
			this->comboBox23->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox23->Name = L"comboBox23";
			this->comboBox23->Size = System::Drawing::Size(193, 28);
			this->comboBox23->TabIndex = 42;
			this->comboBox23->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox23_SelectionChangeCommitted);
			// 
			// comboBox24
			// 
			this->comboBox24->FormattingEnabled = true;
			this->comboBox24->Location = System::Drawing::Point(3, 692);
			this->comboBox24->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox24->Name = L"comboBox24";
			this->comboBox24->Size = System::Drawing::Size(193, 28);
			this->comboBox24->TabIndex = 43;
			this->comboBox24->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox24_SelectionChangeCommitted);
			// 
			// comboBox25
			// 
			this->comboBox25->FormattingEnabled = true;
			this->comboBox25->Location = System::Drawing::Point(3, 722);
			this->comboBox25->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox25->Name = L"comboBox25";
			this->comboBox25->Size = System::Drawing::Size(193, 28);
			this->comboBox25->TabIndex = 44;
			this->comboBox25->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox25_SelectionChangeCommitted);
			// 
			// comboBox26
			// 
			this->comboBox26->FormattingEnabled = true;
			this->comboBox26->Location = System::Drawing::Point(3, 752);
			this->comboBox26->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox26->Name = L"comboBox26";
			this->comboBox26->Size = System::Drawing::Size(193, 28);
			this->comboBox26->TabIndex = 45;
			this->comboBox26->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox26_SelectionChangeCommitted);
			// 
			// comboBox27
			// 
			this->comboBox27->FormattingEnabled = true;
			this->comboBox27->Location = System::Drawing::Point(3, 782);
			this->comboBox27->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox27->Name = L"comboBox27";
			this->comboBox27->Size = System::Drawing::Size(193, 28);
			this->comboBox27->TabIndex = 46;
			this->comboBox27->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox27_SelectionChangeCommitted);
			// 
			// comboBox28
			// 
			this->comboBox28->FormattingEnabled = true;
			this->comboBox28->Location = System::Drawing::Point(3, 812);
			this->comboBox28->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox28->Name = L"comboBox28";
			this->comboBox28->Size = System::Drawing::Size(193, 28);
			this->comboBox28->TabIndex = 47;
			this->comboBox28->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox28_SelectionChangeCommitted);
			// 
			// comboBox29
			// 
			this->comboBox29->FormattingEnabled = true;
			this->comboBox29->Location = System::Drawing::Point(3, 842);
			this->comboBox29->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox29->Name = L"comboBox29";
			this->comboBox29->Size = System::Drawing::Size(193, 28);
			this->comboBox29->TabIndex = 48;
			this->comboBox29->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox29_SelectionChangeCommitted);
			// 
			// comboBox30
			// 
			this->comboBox30->FormattingEnabled = true;
			this->comboBox30->Location = System::Drawing::Point(3, 872);
			this->comboBox30->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox30->Name = L"comboBox30";
			this->comboBox30->Size = System::Drawing::Size(193, 28);
			this->comboBox30->TabIndex = 49;
			this->comboBox30->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox30_SelectionChangeCommitted);
			// 
			// comboBox31
			// 
			this->comboBox31->FormattingEnabled = true;
			this->comboBox31->Location = System::Drawing::Point(3, 902);
			this->comboBox31->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox31->Name = L"comboBox31";
			this->comboBox31->Size = System::Drawing::Size(193, 28);
			this->comboBox31->TabIndex = 50;
			this->comboBox31->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox31_SelectionChangeCommitted);
			// 
			// comboBox32
			// 
			this->comboBox32->FormattingEnabled = true;
			this->comboBox32->Location = System::Drawing::Point(3, 932);
			this->comboBox32->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox32->Name = L"comboBox32";
			this->comboBox32->Size = System::Drawing::Size(193, 28);
			this->comboBox32->TabIndex = 51;
			this->comboBox32->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox32_SelectionChangeCommitted);
			// 
			// comboBox33
			// 
			this->comboBox33->FormattingEnabled = true;
			this->comboBox33->Location = System::Drawing::Point(3, 962);
			this->comboBox33->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox33->Name = L"comboBox33";
			this->comboBox33->Size = System::Drawing::Size(193, 28);
			this->comboBox33->TabIndex = 52;
			this->comboBox33->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox33_SelectionChangeCommitted);
			// 
			// comboBox34
			// 
			this->comboBox34->FormattingEnabled = true;
			this->comboBox34->Location = System::Drawing::Point(3, 992);
			this->comboBox34->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox34->Name = L"comboBox34";
			this->comboBox34->Size = System::Drawing::Size(193, 28);
			this->comboBox34->TabIndex = 53;
			this->comboBox34->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox34_SelectionChangeCommitted);
			// 
			// comboBox35
			// 
			this->comboBox35->FormattingEnabled = true;
			this->comboBox35->Location = System::Drawing::Point(3, 1022);
			this->comboBox35->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox35->Name = L"comboBox35";
			this->comboBox35->Size = System::Drawing::Size(193, 28);
			this->comboBox35->TabIndex = 54;
			this->comboBox35->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox35_SelectionChangeCommitted);
			// 
			// comboBox36
			// 
			this->comboBox36->FormattingEnabled = true;
			this->comboBox36->Location = System::Drawing::Point(3, 1052);
			this->comboBox36->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox36->Name = L"comboBox36";
			this->comboBox36->Size = System::Drawing::Size(193, 28);
			this->comboBox36->TabIndex = 55;
			this->comboBox36->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox36_SelectionChangeCommitted);
			// 
			// comboBox37
			// 
			this->comboBox37->FormattingEnabled = true;
			this->comboBox37->Location = System::Drawing::Point(3, 1082);
			this->comboBox37->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox37->Name = L"comboBox37";
			this->comboBox37->Size = System::Drawing::Size(193, 28);
			this->comboBox37->TabIndex = 56;
			this->comboBox37->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox37_SelectionChangeCommitted);
			// 
			// comboBox38
			// 
			this->comboBox38->FormattingEnabled = true;
			this->comboBox38->Location = System::Drawing::Point(3, 1112);
			this->comboBox38->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox38->Name = L"comboBox38";
			this->comboBox38->Size = System::Drawing::Size(193, 28);
			this->comboBox38->TabIndex = 57;
			this->comboBox38->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox38_SelectionChangeCommitted);
			// 
			// comboBox39
			// 
			this->comboBox39->FormattingEnabled = true;
			this->comboBox39->Location = System::Drawing::Point(3, 1142);
			this->comboBox39->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox39->Name = L"comboBox39";
			this->comboBox39->Size = System::Drawing::Size(193, 28);
			this->comboBox39->TabIndex = 58;
			this->comboBox39->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox39_SelectionChangeCommitted);
			// 
			// comboBox40
			// 
			this->comboBox40->FormattingEnabled = true;
			this->comboBox40->Location = System::Drawing::Point(3, 1172);
			this->comboBox40->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox40->Name = L"comboBox40";
			this->comboBox40->Size = System::Drawing::Size(193, 28);
			this->comboBox40->TabIndex = 59;
			this->comboBox40->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox40_SelectionChangeCommitted);
			// 
			// comboBox41
			// 
			this->comboBox41->FormattingEnabled = true;
			this->comboBox41->Location = System::Drawing::Point(3, 1202);
			this->comboBox41->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox41->Name = L"comboBox41";
			this->comboBox41->Size = System::Drawing::Size(193, 28);
			this->comboBox41->TabIndex = 60;
			this->comboBox41->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox41_SelectionChangeCommitted);
			// 
			// comboBox42
			// 
			this->comboBox42->FormattingEnabled = true;
			this->comboBox42->Location = System::Drawing::Point(3, 1232);
			this->comboBox42->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox42->Name = L"comboBox42";
			this->comboBox42->Size = System::Drawing::Size(193, 28);
			this->comboBox42->TabIndex = 61;
			this->comboBox42->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox42_SelectionChangeCommitted);
			// 
			// comboBox43
			// 
			this->comboBox43->FormattingEnabled = true;
			this->comboBox43->Location = System::Drawing::Point(3, 1262);
			this->comboBox43->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox43->Name = L"comboBox43";
			this->comboBox43->Size = System::Drawing::Size(193, 28);
			this->comboBox43->TabIndex = 62;
			this->comboBox43->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox43_SelectionChangeCommitted);
			// 
			// comboBox44
			// 
			this->comboBox44->FormattingEnabled = true;
			this->comboBox44->Location = System::Drawing::Point(3, 1292);
			this->comboBox44->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox44->Name = L"comboBox44";
			this->comboBox44->Size = System::Drawing::Size(193, 28);
			this->comboBox44->TabIndex = 63;
			this->comboBox44->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox44_SelectionChangeCommitted);
			// 
			// comboBox45
			// 
			this->comboBox45->FormattingEnabled = true;
			this->comboBox45->Location = System::Drawing::Point(3, 1322);
			this->comboBox45->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox45->Name = L"comboBox45";
			this->comboBox45->Size = System::Drawing::Size(193, 28);
			this->comboBox45->TabIndex = 64;
			this->comboBox45->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox45_SelectionChangeCommitted);
			// 
			// comboBox46
			// 
			this->comboBox46->FormattingEnabled = true;
			this->comboBox46->Location = System::Drawing::Point(3, 1352);
			this->comboBox46->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox46->Name = L"comboBox46";
			this->comboBox46->Size = System::Drawing::Size(193, 28);
			this->comboBox46->TabIndex = 65;
			this->comboBox46->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox46_SelectionChangeCommitted);
			// 
			// comboBox47
			// 
			this->comboBox47->FormattingEnabled = true;
			this->comboBox47->Location = System::Drawing::Point(3, 1382);
			this->comboBox47->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox47->Name = L"comboBox47";
			this->comboBox47->Size = System::Drawing::Size(193, 28);
			this->comboBox47->TabIndex = 66;
			this->comboBox47->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox47_SelectionChangeCommitted);
			// 
			// comboBox48
			// 
			this->comboBox48->FormattingEnabled = true;
			this->comboBox48->Location = System::Drawing::Point(3, 1412);
			this->comboBox48->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox48->Name = L"comboBox48";
			this->comboBox48->Size = System::Drawing::Size(193, 28);
			this->comboBox48->TabIndex = 67;
			this->comboBox48->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox48_SelectionChangeCommitted);
			// 
			// comboBox49
			// 
			this->comboBox49->FormattingEnabled = true;
			this->comboBox49->Location = System::Drawing::Point(3, 1442);
			this->comboBox49->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox49->Name = L"comboBox49";
			this->comboBox49->Size = System::Drawing::Size(193, 28);
			this->comboBox49->TabIndex = 68;
			this->comboBox49->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox49_SelectionChangeCommitted);
			// 
			// comboBox50
			// 
			this->comboBox50->FormattingEnabled = true;
			this->comboBox50->Location = System::Drawing::Point(3, 1472);
			this->comboBox50->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox50->Name = L"comboBox50";
			this->comboBox50->Size = System::Drawing::Size(193, 28);
			this->comboBox50->TabIndex = 69;
			this->comboBox50->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainView::comboBox50_SelectionChangeCommitted);
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(203, 602);
			this->textBox21->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(250, 26);
			this->textBox21->TabIndex = 70;
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(203, 632);
			this->textBox22->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(250, 26);
			this->textBox22->TabIndex = 71;
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(203, 662);
			this->textBox23->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(250, 26);
			this->textBox23->TabIndex = 72;
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(203, 692);
			this->textBox24->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(250, 26);
			this->textBox24->TabIndex = 73;
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(203, 722);
			this->textBox25->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(250, 26);
			this->textBox25->TabIndex = 74;
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(203, 752);
			this->textBox26->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(250, 26);
			this->textBox26->TabIndex = 75;
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(203, 782);
			this->textBox27->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(250, 26);
			this->textBox27->TabIndex = 76;
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(203, 812);
			this->textBox28->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(250, 26);
			this->textBox28->TabIndex = 77;
			// 
			// textBox29
			// 
			this->textBox29->Location = System::Drawing::Point(203, 842);
			this->textBox29->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(250, 26);
			this->textBox29->TabIndex = 78;
			// 
			// textBox30
			// 
			this->textBox30->Location = System::Drawing::Point(203, 872);
			this->textBox30->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(250, 26);
			this->textBox30->TabIndex = 79;
			// 
			// textBox31
			// 
			this->textBox31->Location = System::Drawing::Point(203, 902);
			this->textBox31->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(250, 26);
			this->textBox31->TabIndex = 80;
			// 
			// textBox32
			// 
			this->textBox32->Location = System::Drawing::Point(203, 932);
			this->textBox32->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(250, 26);
			this->textBox32->TabIndex = 81;
			// 
			// textBox33
			// 
			this->textBox33->Location = System::Drawing::Point(203, 962);
			this->textBox33->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(250, 26);
			this->textBox33->TabIndex = 82;
			// 
			// textBox34
			// 
			this->textBox34->Location = System::Drawing::Point(203, 992);
			this->textBox34->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox34->Name = L"textBox34";
			this->textBox34->Size = System::Drawing::Size(250, 26);
			this->textBox34->TabIndex = 83;
			// 
			// textBox35
			// 
			this->textBox35->Location = System::Drawing::Point(203, 1022);
			this->textBox35->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox35->Name = L"textBox35";
			this->textBox35->Size = System::Drawing::Size(250, 26);
			this->textBox35->TabIndex = 84;
			// 
			// textBox36
			// 
			this->textBox36->Location = System::Drawing::Point(203, 1052);
			this->textBox36->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox36->Name = L"textBox36";
			this->textBox36->Size = System::Drawing::Size(250, 26);
			this->textBox36->TabIndex = 85;
			// 
			// textBox37
			// 
			this->textBox37->Location = System::Drawing::Point(203, 1082);
			this->textBox37->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox37->Name = L"textBox37";
			this->textBox37->Size = System::Drawing::Size(250, 26);
			this->textBox37->TabIndex = 86;
			// 
			// textBox38
			// 
			this->textBox38->Location = System::Drawing::Point(203, 1112);
			this->textBox38->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox38->Name = L"textBox38";
			this->textBox38->Size = System::Drawing::Size(250, 26);
			this->textBox38->TabIndex = 87;
			// 
			// textBox39
			// 
			this->textBox39->Location = System::Drawing::Point(203, 1142);
			this->textBox39->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox39->Name = L"textBox39";
			this->textBox39->Size = System::Drawing::Size(250, 26);
			this->textBox39->TabIndex = 88;
			// 
			// textBox40
			// 
			this->textBox40->Location = System::Drawing::Point(203, 1172);
			this->textBox40->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox40->Name = L"textBox40";
			this->textBox40->Size = System::Drawing::Size(250, 26);
			this->textBox40->TabIndex = 89;
			// 
			// textBox41
			// 
			this->textBox41->Location = System::Drawing::Point(203, 1202);
			this->textBox41->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox41->Name = L"textBox41";
			this->textBox41->Size = System::Drawing::Size(250, 26);
			this->textBox41->TabIndex = 90;
			// 
			// textBox42
			// 
			this->textBox42->Location = System::Drawing::Point(203, 1232);
			this->textBox42->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox42->Name = L"textBox42";
			this->textBox42->Size = System::Drawing::Size(250, 26);
			this->textBox42->TabIndex = 91;
			// 
			// textBox43
			// 
			this->textBox43->Location = System::Drawing::Point(203, 1262);
			this->textBox43->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox43->Name = L"textBox43";
			this->textBox43->Size = System::Drawing::Size(250, 26);
			this->textBox43->TabIndex = 92;
			// 
			// textBox44
			// 
			this->textBox44->Location = System::Drawing::Point(203, 1292);
			this->textBox44->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox44->Name = L"textBox44";
			this->textBox44->Size = System::Drawing::Size(250, 26);
			this->textBox44->TabIndex = 93;
			// 
			// textBox45
			// 
			this->textBox45->Location = System::Drawing::Point(203, 1322);
			this->textBox45->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox45->Name = L"textBox45";
			this->textBox45->Size = System::Drawing::Size(250, 26);
			this->textBox45->TabIndex = 94;
			// 
			// textBox46
			// 
			this->textBox46->Location = System::Drawing::Point(203, 1352);
			this->textBox46->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox46->Name = L"textBox46";
			this->textBox46->Size = System::Drawing::Size(250, 26);
			this->textBox46->TabIndex = 95;
			// 
			// textBox47
			// 
			this->textBox47->Location = System::Drawing::Point(203, 1382);
			this->textBox47->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox47->Name = L"textBox47";
			this->textBox47->Size = System::Drawing::Size(250, 26);
			this->textBox47->TabIndex = 96;
			// 
			// textBox48
			// 
			this->textBox48->Location = System::Drawing::Point(203, 1412);
			this->textBox48->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox48->Name = L"textBox48";
			this->textBox48->Size = System::Drawing::Size(250, 26);
			this->textBox48->TabIndex = 97;
			// 
			// textBox49
			// 
			this->textBox49->Location = System::Drawing::Point(203, 1442);
			this->textBox49->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox49->Name = L"textBox49";
			this->textBox49->Size = System::Drawing::Size(250, 26);
			this->textBox49->TabIndex = 98;
			// 
			// textBox50
			// 
			this->textBox50->Location = System::Drawing::Point(203, 1472);
			this->textBox50->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox50->Name = L"textBox50";
			this->textBox50->Size = System::Drawing::Size(250, 26);
			this->textBox50->TabIndex = 99;
			// 
			// textBox51
			// 
			this->textBox51->Location = System::Drawing::Point(462, 4);
			this->textBox51->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox51->Name = L"textBox51";
			this->textBox51->Size = System::Drawing::Size(180, 26);
			this->textBox51->TabIndex = 100;
			// 
			// textBox52
			// 
			this->textBox52->Location = System::Drawing::Point(462, 34);
			this->textBox52->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox52->Name = L"textBox52";
			this->textBox52->Size = System::Drawing::Size(180, 26);
			this->textBox52->TabIndex = 101;
			// 
			// textBox53
			// 
			this->textBox53->Location = System::Drawing::Point(462, 64);
			this->textBox53->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox53->Name = L"textBox53";
			this->textBox53->Size = System::Drawing::Size(180, 26);
			this->textBox53->TabIndex = 102;
			// 
			// textBox54
			// 
			this->textBox54->Location = System::Drawing::Point(462, 94);
			this->textBox54->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox54->Name = L"textBox54";
			this->textBox54->Size = System::Drawing::Size(180, 26);
			this->textBox54->TabIndex = 103;
			// 
			// textBox55
			// 
			this->textBox55->Location = System::Drawing::Point(462, 124);
			this->textBox55->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox55->Name = L"textBox55";
			this->textBox55->Size = System::Drawing::Size(180, 26);
			this->textBox55->TabIndex = 104;
			// 
			// textBox56
			// 
			this->textBox56->Location = System::Drawing::Point(462, 154);
			this->textBox56->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox56->Name = L"textBox56";
			this->textBox56->Size = System::Drawing::Size(180, 26);
			this->textBox56->TabIndex = 105;
			// 
			// textBox57
			// 
			this->textBox57->Location = System::Drawing::Point(462, 184);
			this->textBox57->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox57->Name = L"textBox57";
			this->textBox57->Size = System::Drawing::Size(180, 26);
			this->textBox57->TabIndex = 106;
			// 
			// textBox58
			// 
			this->textBox58->Location = System::Drawing::Point(462, 214);
			this->textBox58->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox58->Name = L"textBox58";
			this->textBox58->Size = System::Drawing::Size(180, 26);
			this->textBox58->TabIndex = 107;
			// 
			// textBox59
			// 
			this->textBox59->Location = System::Drawing::Point(462, 244);
			this->textBox59->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox59->Name = L"textBox59";
			this->textBox59->Size = System::Drawing::Size(180, 26);
			this->textBox59->TabIndex = 108;
			// 
			// textBox60
			// 
			this->textBox60->Location = System::Drawing::Point(462, 274);
			this->textBox60->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox60->Name = L"textBox60";
			this->textBox60->Size = System::Drawing::Size(180, 26);
			this->textBox60->TabIndex = 109;
			// 
			// textBox61
			// 
			this->textBox61->Location = System::Drawing::Point(462, 304);
			this->textBox61->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox61->Name = L"textBox61";
			this->textBox61->Size = System::Drawing::Size(180, 26);
			this->textBox61->TabIndex = 110;
			// 
			// textBox62
			// 
			this->textBox62->Location = System::Drawing::Point(462, 334);
			this->textBox62->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox62->Name = L"textBox62";
			this->textBox62->Size = System::Drawing::Size(180, 26);
			this->textBox62->TabIndex = 111;
			// 
			// textBox63
			// 
			this->textBox63->Location = System::Drawing::Point(462, 364);
			this->textBox63->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox63->Name = L"textBox63";
			this->textBox63->Size = System::Drawing::Size(180, 26);
			this->textBox63->TabIndex = 112;
			// 
			// textBox64
			// 
			this->textBox64->Location = System::Drawing::Point(462, 394);
			this->textBox64->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox64->Name = L"textBox64";
			this->textBox64->Size = System::Drawing::Size(180, 26);
			this->textBox64->TabIndex = 113;
			// 
			// textBox65
			// 
			this->textBox65->Location = System::Drawing::Point(462, 424);
			this->textBox65->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox65->Name = L"textBox65";
			this->textBox65->Size = System::Drawing::Size(180, 26);
			this->textBox65->TabIndex = 114;
			// 
			// textBox66
			// 
			this->textBox66->Location = System::Drawing::Point(462, 454);
			this->textBox66->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox66->Name = L"textBox66";
			this->textBox66->Size = System::Drawing::Size(180, 26);
			this->textBox66->TabIndex = 115;
			// 
			// textBox67
			// 
			this->textBox67->Location = System::Drawing::Point(462, 484);
			this->textBox67->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox67->Name = L"textBox67";
			this->textBox67->Size = System::Drawing::Size(180, 26);
			this->textBox67->TabIndex = 116;
			// 
			// textBox68
			// 
			this->textBox68->Location = System::Drawing::Point(462, 514);
			this->textBox68->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox68->Name = L"textBox68";
			this->textBox68->Size = System::Drawing::Size(180, 26);
			this->textBox68->TabIndex = 117;
			// 
			// textBox70
			// 
			this->textBox70->Location = System::Drawing::Point(462, 574);
			this->textBox70->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox70->Name = L"textBox70";
			this->textBox70->Size = System::Drawing::Size(180, 26);
			this->textBox70->TabIndex = 119;
			// 
			// textBox71
			// 
			this->textBox71->Location = System::Drawing::Point(462, 604);
			this->textBox71->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox71->Name = L"textBox71";
			this->textBox71->Size = System::Drawing::Size(180, 26);
			this->textBox71->TabIndex = 120;
			// 
			// textBox72
			// 
			this->textBox72->Location = System::Drawing::Point(462, 634);
			this->textBox72->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox72->Name = L"textBox72";
			this->textBox72->Size = System::Drawing::Size(180, 26);
			this->textBox72->TabIndex = 121;
			// 
			// textBox73
			// 
			this->textBox73->Location = System::Drawing::Point(462, 664);
			this->textBox73->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox73->Name = L"textBox73";
			this->textBox73->Size = System::Drawing::Size(180, 26);
			this->textBox73->TabIndex = 122;
			// 
			// textBox74
			// 
			this->textBox74->Location = System::Drawing::Point(462, 694);
			this->textBox74->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox74->Name = L"textBox74";
			this->textBox74->Size = System::Drawing::Size(180, 26);
			this->textBox74->TabIndex = 123;
			// 
			// textBox75
			// 
			this->textBox75->Location = System::Drawing::Point(462, 724);
			this->textBox75->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox75->Name = L"textBox75";
			this->textBox75->Size = System::Drawing::Size(180, 26);
			this->textBox75->TabIndex = 124;
			// 
			// textBox76
			// 
			this->textBox76->Location = System::Drawing::Point(462, 754);
			this->textBox76->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox76->Name = L"textBox76";
			this->textBox76->Size = System::Drawing::Size(180, 26);
			this->textBox76->TabIndex = 125;
			// 
			// textBox77
			// 
			this->textBox77->Location = System::Drawing::Point(462, 784);
			this->textBox77->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox77->Name = L"textBox77";
			this->textBox77->Size = System::Drawing::Size(180, 26);
			this->textBox77->TabIndex = 126;
			// 
			// textBox78
			// 
			this->textBox78->Location = System::Drawing::Point(462, 814);
			this->textBox78->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox78->Name = L"textBox78";
			this->textBox78->Size = System::Drawing::Size(180, 26);
			this->textBox78->TabIndex = 127;
			// 
			// textBox79
			// 
			this->textBox79->Location = System::Drawing::Point(462, 844);
			this->textBox79->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox79->Name = L"textBox79";
			this->textBox79->Size = System::Drawing::Size(180, 26);
			this->textBox79->TabIndex = 128;
			// 
			// textBox80
			// 
			this->textBox80->Location = System::Drawing::Point(462, 874);
			this->textBox80->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox80->Name = L"textBox80";
			this->textBox80->Size = System::Drawing::Size(180, 26);
			this->textBox80->TabIndex = 129;
			// 
			// textBox81
			// 
			this->textBox81->Location = System::Drawing::Point(462, 904);
			this->textBox81->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox81->Name = L"textBox81";
			this->textBox81->Size = System::Drawing::Size(180, 26);
			this->textBox81->TabIndex = 130;
			// 
			// textBox82
			// 
			this->textBox82->Location = System::Drawing::Point(462, 934);
			this->textBox82->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox82->Name = L"textBox82";
			this->textBox82->Size = System::Drawing::Size(180, 26);
			this->textBox82->TabIndex = 131;
			// 
			// textBox83
			// 
			this->textBox83->Location = System::Drawing::Point(462, 964);
			this->textBox83->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox83->Name = L"textBox83";
			this->textBox83->Size = System::Drawing::Size(180, 26);
			this->textBox83->TabIndex = 132;
			// 
			// textBox84
			// 
			this->textBox84->Location = System::Drawing::Point(462, 994);
			this->textBox84->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox84->Name = L"textBox84";
			this->textBox84->Size = System::Drawing::Size(180, 26);
			this->textBox84->TabIndex = 133;
			// 
			// textBox85
			// 
			this->textBox85->Location = System::Drawing::Point(462, 1024);
			this->textBox85->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox85->Name = L"textBox85";
			this->textBox85->Size = System::Drawing::Size(180, 26);
			this->textBox85->TabIndex = 134;
			// 
			// textBox86
			// 
			this->textBox86->Location = System::Drawing::Point(462, 1054);
			this->textBox86->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox86->Name = L"textBox86";
			this->textBox86->Size = System::Drawing::Size(180, 26);
			this->textBox86->TabIndex = 135;
			// 
			// textBox87
			// 
			this->textBox87->Location = System::Drawing::Point(462, 1084);
			this->textBox87->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox87->Name = L"textBox87";
			this->textBox87->Size = System::Drawing::Size(180, 26);
			this->textBox87->TabIndex = 136;
			// 
			// textBox88
			// 
			this->textBox88->Location = System::Drawing::Point(462, 1114);
			this->textBox88->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox88->Name = L"textBox88";
			this->textBox88->Size = System::Drawing::Size(180, 26);
			this->textBox88->TabIndex = 137;
			// 
			// textBox89
			// 
			this->textBox89->Location = System::Drawing::Point(462, 1144);
			this->textBox89->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox89->Name = L"textBox89";
			this->textBox89->Size = System::Drawing::Size(180, 26);
			this->textBox89->TabIndex = 138;
			// 
			// textBox90
			// 
			this->textBox90->Location = System::Drawing::Point(462, 1174);
			this->textBox90->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox90->Name = L"textBox90";
			this->textBox90->Size = System::Drawing::Size(180, 26);
			this->textBox90->TabIndex = 139;
			// 
			// textBox91
			// 
			this->textBox91->Location = System::Drawing::Point(462, 1204);
			this->textBox91->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox91->Name = L"textBox91";
			this->textBox91->Size = System::Drawing::Size(180, 26);
			this->textBox91->TabIndex = 140;
			// 
			// textBox92
			// 
			this->textBox92->Location = System::Drawing::Point(462, 1234);
			this->textBox92->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox92->Name = L"textBox92";
			this->textBox92->Size = System::Drawing::Size(180, 26);
			this->textBox92->TabIndex = 141;
			// 
			// textBox93
			// 
			this->textBox93->Location = System::Drawing::Point(462, 1264);
			this->textBox93->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox93->Name = L"textBox93";
			this->textBox93->Size = System::Drawing::Size(180, 26);
			this->textBox93->TabIndex = 142;
			// 
			// textBox94
			// 
			this->textBox94->Location = System::Drawing::Point(462, 1294);
			this->textBox94->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox94->Name = L"textBox94";
			this->textBox94->Size = System::Drawing::Size(180, 26);
			this->textBox94->TabIndex = 143;
			// 
			// textBox95
			// 
			this->textBox95->Location = System::Drawing::Point(462, 1324);
			this->textBox95->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox95->Name = L"textBox95";
			this->textBox95->Size = System::Drawing::Size(180, 26);
			this->textBox95->TabIndex = 144;
			// 
			// textBox96
			// 
			this->textBox96->Location = System::Drawing::Point(462, 1354);
			this->textBox96->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox96->Name = L"textBox96";
			this->textBox96->Size = System::Drawing::Size(180, 26);
			this->textBox96->TabIndex = 145;
			// 
			// textBox97
			// 
			this->textBox97->Location = System::Drawing::Point(462, 1384);
			this->textBox97->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox97->Name = L"textBox97";
			this->textBox97->Size = System::Drawing::Size(180, 26);
			this->textBox97->TabIndex = 146;
			// 
			// textBox98
			// 
			this->textBox98->Location = System::Drawing::Point(462, 1414);
			this->textBox98->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox98->Name = L"textBox98";
			this->textBox98->Size = System::Drawing::Size(180, 26);
			this->textBox98->TabIndex = 147;
			// 
			// textBox99
			// 
			this->textBox99->Location = System::Drawing::Point(462, 1444);
			this->textBox99->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox99->Name = L"textBox99";
			this->textBox99->Size = System::Drawing::Size(180, 26);
			this->textBox99->TabIndex = 148;
			// 
			// textBox100
			// 
			this->textBox100->Location = System::Drawing::Point(462, 1474);
			this->textBox100->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox100->Name = L"textBox100";
			this->textBox100->Size = System::Drawing::Size(180, 26);
			this->textBox100->TabIndex = 149;
			// 
			// textBox69
			// 
			this->textBox69->Location = System::Drawing::Point(462, 544);
			this->textBox69->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox69->Name = L"textBox69";
			this->textBox69->Size = System::Drawing::Size(180, 26);
			this->textBox69->TabIndex = 118;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Open";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainView::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(443, 12);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(144, 39);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainView::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(350, 12);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(87, 39);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainView::button3_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(862, 9);
			this->trackBar1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->trackBar1->Maximum = 4500;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(1270, 69);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->Value = 4500;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &MainView::trackBar1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(752, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"WW:";
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->tagsComboBox);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->panel1->Location = System::Drawing::Point(755, 136);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(2292, 1523);
			this->panel1->TabIndex = 6;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainView::tagsPanel_MouseClick);
			// 
			// tagsComboBox
			// 
			this->tagsComboBox->DropDownHeight = 150;
			this->tagsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->tagsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->tagsComboBox->FormattingEnabled = true;
			this->tagsComboBox->IntegralHeight = false;
			this->tagsComboBox->Location = System::Drawing::Point(39, 35);
			this->tagsComboBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tagsComboBox->Name = L"tagsComboBox";
			this->tagsComboBox->Size = System::Drawing::Size(281, 28);
			this->tagsComboBox->TabIndex = 0;
			this->tagsComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainView::tagsComboBox_SelectedIndexChanged);
			this->tagsComboBox->DropDownClosed += gcnew System::EventHandler(this, &MainView::tagsComboBox_DropDownClosed);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(136, 12);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(122, 40);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Add Tag";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainView::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(264, 12);
			this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(79, 39);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Load";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainView::button5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(752, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"WP:";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(862, 60);
			this->trackBar2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->trackBar2->Maximum = 4500;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(1270, 69);
			this->trackBar2->TabIndex = 11;
			this->trackBar2->Value = 4500;
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &MainView::trackBar2_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(824, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(824, 82);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 20);
			this->label5->TabIndex = 13;
			this->label5->Text = L"0";
			// 
			// info1
			// 
			this->info1->AutoSize = true;
			this->info1->Location = System::Drawing::Point(14, 58);
			this->info1->Name = L"info1";
			this->info1->Size = System::Drawing::Size(98, 20);
			this->info1->TabIndex = 14;
			this->info1->Text = L"Tags choice:";
			// 
			// info2
			// 
			this->info2->AutoSize = true;
			this->info2->Location = System::Drawing::Point(217, 58);
			this->info2->Name = L"info2";
			this->info2->Size = System::Drawing::Size(119, 20);
			this->info2->TabIndex = 15;
			this->info2->Text = L"Tags value edit:";
			// 
			// info3
			// 
			this->info3->AutoSize = true;
			this->info3->Location = System::Drawing::Point(476, 58);
			this->info3->Name = L"info3";
			this->info3->Size = System::Drawing::Size(123, 20);
			this->info3->TabIndex = 16;
			this->info3->Text = L"Tags labels edit:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(605, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 20);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Font size:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(609, 38);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(74, 26);
			this->numericUpDown1->TabIndex = 20;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MainView::numericUpDown1_ValueChanged);
			// 
			// MainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(2148, 1306);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->info3);
			this->Controls->Add(this->info2);
			this->Controls->Add(this->info1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MainView";
			this->Text = L"DICOM Browser";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainView::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma endregion


#pragma region Code of application

		/**
		*  @author Jakub Maci퉓
		*  @brief Creating array of comboboxes
		*
		*  @param [in] array<ComboBox^>^ comboList
		*
		*  @return none
		*/
	private:void createComboArray(array<ComboBox^>^ comboList)
	{
		comboList[0] = comboBox1;
		comboList[1] = comboBox2;
		comboList[2] = comboBox3;
		comboList[3] = comboBox4;
		comboList[4] = comboBox5;
		comboList[5] = comboBox6;
		comboList[6] = comboBox7;
		comboList[7] = comboBox8;
		comboList[8] = comboBox9;
		comboList[9] = comboBox10;
		comboList[10] = comboBox11;
		comboList[11] = comboBox12;
		comboList[12] = comboBox13;
		comboList[13] = comboBox14;
		comboList[14] = comboBox15;
		comboList[15] = comboBox16;
		comboList[16] = comboBox17;
		comboList[17] = comboBox18;
		comboList[18] = comboBox19;
		comboList[19] = comboBox20;
		comboList[20] = comboBox21;
		comboList[21] = comboBox22;
		comboList[22] = comboBox23;
		comboList[23] = comboBox24;
		comboList[24] = comboBox25;
		comboList[25] = comboBox26;
		comboList[26] = comboBox27;
		comboList[27] = comboBox28;
		comboList[28] = comboBox29;
		comboList[29] = comboBox30;
		comboList[30] = comboBox31;
		comboList[31] = comboBox32;
		comboList[32] = comboBox33;
		comboList[33] = comboBox34;
		comboList[34] = comboBox35;
		comboList[35] = comboBox36;
		comboList[36] = comboBox37;
		comboList[37] = comboBox38;
		comboList[38] = comboBox39;
		comboList[39] = comboBox40;
		comboList[40] = comboBox41;
		comboList[41] = comboBox42;
		comboList[42] = comboBox43;
		comboList[43] = comboBox44;
		comboList[44] = comboBox45;
		comboList[45] = comboBox46;
		comboList[46] = comboBox47;
		comboList[47] = comboBox48;
		comboList[48] = comboBox49;
		comboList[49] = comboBox50;

	}

			/**
			*  @author Jakub Maci퉓
			*  @brief Creating array of textboxes
			*
			*  @param [in] array<TextBox^>^ textBoxList
			*
			*  @return none
			*/
	private:void createTextBoxList(array<TextBox^>^ textBoxList)
	{
		textBoxList[0] = textBox1;
		textBoxList[1] = textBox2;
		textBoxList[2] = textBox3;
		textBoxList[3] = textBox4;
		textBoxList[4] = textBox5;
		textBoxList[5] = textBox6;
		textBoxList[6] = textBox7;
		textBoxList[7] = textBox8;
		textBoxList[8] = textBox9;
		textBoxList[9] = textBox10;
		textBoxList[10] = textBox11;
		textBoxList[11] = textBox12;
		textBoxList[12] = textBox13;
		textBoxList[13] = textBox14;
		textBoxList[14] = textBox15;
		textBoxList[15] = textBox16;
		textBoxList[16] = textBox17;
		textBoxList[17] = textBox18;
		textBoxList[18] = textBox19;
		textBoxList[19] = textBox20;
		textBoxList[20] = textBox21;
		textBoxList[21] = textBox22;
		textBoxList[22] = textBox23;
		textBoxList[23] = textBox24;
		textBoxList[24] = textBox25;
		textBoxList[25] = textBox26;
		textBoxList[26] = textBox27;
		textBoxList[27] = textBox28;
		textBoxList[28] = textBox29;
		textBoxList[29] = textBox30;
		textBoxList[30] = textBox31;
		textBoxList[31] = textBox32;
		textBoxList[32] = textBox33;
		textBoxList[33] = textBox34;
		textBoxList[34] = textBox35;
		textBoxList[35] = textBox36;
		textBoxList[36] = textBox37;
		textBoxList[37] = textBox38;
		textBoxList[38] = textBox39;
		textBoxList[39] = textBox40;
		textBoxList[40] = textBox41;
		textBoxList[41] = textBox42;
		textBoxList[42] = textBox43;
		textBoxList[43] = textBox44;
		textBoxList[44] = textBox45;
		textBoxList[45] = textBox46;
		textBoxList[46] = textBox47;
		textBoxList[47] = textBox48;
		textBoxList[48] = textBox49;
		textBoxList[49] = textBox50;

	}

			/**
			*  @author Jakub Maci퉓
			*  @brief Creating array of textboxes for tags labels
			*
			*  @param [in] array<TextBox^>^ textBoxFlagList
			*
			*  @return none
			*/
	private:void createTextBoxListFLAGS(array<TextBox^>^ textBoxFlagList)
	{
		textBoxFlagList[0] = textBox51;
		textBoxFlagList[1] = textBox52;
		textBoxFlagList[2] = textBox53;
		textBoxFlagList[3] = textBox54;
		textBoxFlagList[4] = textBox55;
		textBoxFlagList[5] = textBox56;
		textBoxFlagList[6] = textBox57;
		textBoxFlagList[7] = textBox58;
		textBoxFlagList[8] = textBox59;
		textBoxFlagList[9] = textBox60;
		textBoxFlagList[10] = textBox61;
		textBoxFlagList[11] = textBox62;
		textBoxFlagList[12] = textBox63;
		textBoxFlagList[13] = textBox64;
		textBoxFlagList[14] = textBox65;
		textBoxFlagList[15] = textBox66;
		textBoxFlagList[16] = textBox67;
		textBoxFlagList[17] = textBox68;
		textBoxFlagList[18] = textBox69;
		textBoxFlagList[19] = textBox70;
		textBoxFlagList[20] = textBox71;
		textBoxFlagList[21] = textBox72;
		textBoxFlagList[22] = textBox73;
		textBoxFlagList[23] = textBox74;
		textBoxFlagList[24] = textBox75;
		textBoxFlagList[25] = textBox76;
		textBoxFlagList[26] = textBox77;
		textBoxFlagList[27] = textBox78;
		textBoxFlagList[28] = textBox79;
		textBoxFlagList[29] = textBox80;
		textBoxFlagList[30] = textBox81;
		textBoxFlagList[31] = textBox82;
		textBoxFlagList[32] = textBox83;
		textBoxFlagList[33] = textBox84;
		textBoxFlagList[34] = textBox85;
		textBoxFlagList[35] = textBox86;
		textBoxFlagList[36] = textBox87;
		textBoxFlagList[37] = textBox88;
		textBoxFlagList[38] = textBox89;
		textBoxFlagList[39] = textBox90;
		textBoxFlagList[40] = textBox91;
		textBoxFlagList[41] = textBox92;
		textBoxFlagList[42] = textBox93;
		textBoxFlagList[43] = textBox94;
		textBoxFlagList[44] = textBox95;
		textBoxFlagList[45] = textBox96;
		textBoxFlagList[46] = textBox97;
		textBoxFlagList[47] = textBox98;
		textBoxFlagList[48] = textBox99;
		textBoxFlagList[49] = textBox100;
	}

			/**
			*  @author Jakub Maci퉓
			*  @brief Loading MainView windows form do: hide combobox on panel and create arrays of comboboxes and textboxes
			*
			*  @param [in] array<TextBox^>^ textBoxFlagList
			*
			*  @return none
			*/
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		// hide tagsComboBox
		tagsComboBox->Visible = false;
		//create arrays
		createComboArray(comboList);
		createTextBoxList(textBoxList);
		createTextBoxListFLAGS(textBoxFList);
	}

			 /**
			 *  @author Jakub Maci퉓 and Emilia Siemieniuk and Paulina Nowak
			 *  @brief open file button listener
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		/// Create new open file dialog box to choice a path to file - Emilia Siemieniuk and Paulina Nowak
		OpenFileDialog^ openDial = gcnew OpenFileDialog();
		/// Declaration of file type
		openDial->Filter = "Pliki DCIM|*.DCIM|Wszystkie pliki|*.*";
		if (openDial->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			/// cancel dialog box
			return;
		}

		/// path conversion - Jakub Maci퉓
		String^ fullPath = openDial->FileName;
		std::string path = msclr::interop::marshal_as<std::string>(fullPath);
		///load dicom data
		interX->loadDicomData(path);
		interX->displayDicomImage(panel1);
		///geting dicom tags data
		std::vector<std::string> desc = DicomInterface::getInstance()->getDataRecordDescriptionList();
		std::vector<std::string> val = DicomInterface::getInstance()->getDataRecordValueList();
		///clean up list elements
		interX->clearCombos(comboList);
		interX->clearText(textBoxList);
		interX->clearText(textBoxFList);
		dataLX->RemoveRange(0, dataLX->Count);
		tagsComboBox->Items->Clear();
		(panel1->Controls)->Clear();
		this->panel1->Controls->Add(this->tagsComboBox);

		///fill list with dicom tags data
		interX->setItemsToCombo(comboList, desc);
		interX->convertSTDtoList(val, desc, listVal, listDesc);

		///set up data for sliders
		this->trackBar1->Minimum = DicomInterface::getInstance()->GetImageData()->GetMinPixel();
		this->trackBar1->Maximum = DicomInterface::getInstance()->GetImageData()->GetMaxPixel();
		this->trackBar1->Value = this->trackBar1->Maximum;
		label4->Text = Convert::ToString(this->trackBar1->Value);
		this->trackBar2->Minimum = DicomInterface::getInstance()->GetImageData()->GetMinPixel();
		this->trackBar2->Maximum = DicomInterface::getInstance()->GetImageData()->GetMaxPixel();
		this->trackBar2->Value = Convert::ToInt32(DicomInterface::getInstance()->GetImageData()->GetVOI().center);
		label5->Text = Convert::ToString(this->trackBar2->Value);
	}

			 /**
			 *  @author Jakub Maci퉓
			 *  @brief save button listener
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		interX->savePanelToImageFile(panel1);
	}

			 /**
			 *  @author Jakub Maci퉓
			 *  @brief reset button listener
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		///clear labels on panel, clear list wit loaded tags
		dataLX->RemoveRange(0, dataLX->Count);
		tagsComboBox->Items->Clear();
		(panel1->Controls)->Clear();
		this->panel1->Controls->Add(this->tagsComboBox);
	}

			 /**
			 *  @author Jakub Maci퉓
			 *  @brief AddTagForm button listener
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		///create new window as a dialog window
		AddTagForm^ windowAdd = gcnew AddTagForm();
		System::Windows::Forms::DialogResult dialR;
		///if addtag then get returned string values into list of items in every combobox and add values to main list of data
		dialR = windowAdd->ShowDialog();
		if (dialR == System::Windows::Forms::DialogResult::OK)
		{
			for (int i = 0; i < 50; i++)
			{
				comboList[i]->Items->Add(windowAdd->getAddDes() + " (" + windowAdd->getAddGr() + "," + windowAdd->getAddEl() + ")");
			}
			listDesc->Add(windowAdd->getAddDes());
			listVal->Add(windowAdd->getAddVal());
			windowAdd->~AddTagForm();
		}
		/// else do nothing
		else if (dialR == System::Windows::Forms::DialogResult::Cancel) {
			windowAdd->~AddTagForm();
		}
	}

			 /**
			 *  @author Jakub Maci퉓
			 *  @brief load button listener
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		///read every combobox and textbox and if it is not empty then write it to data list for using it on panel
		///add data list to combobox on panel 
		for (int i = 0; i < 50; i++)
		{
			if ((textBoxFList[i]->Text->Equals("")) && (textBoxList[i]->Text->Equals("")))
			{

			}
			else
				dataLX->Add(textBoxFList[i]->Text + " " + textBoxList[i]->Text);
		}
		interX->fillTagComboBox(dataLX, tagsComboBox);
	}

#pragma endregion

#pragma region Contrast
			 /**
			 *  @author Jakub Maci퉓
			 *  @brief WW changer - trackBar 1
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		///Setting WW of image VOI in LUT  
		DicomInterface::getInstance()->SetImageVOI((double)trackBar2->Value, (double)trackBar1->Value);
		int index = trackBar1->Value;
		label4->Text = Convert::ToString(index);
		interX->displayDicomImage(panel1);
	}

			 /**
			 *  @author Jakub Maci퉓
			 *  @brief WC changer - trackBar 2
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		///Setting WC of image VOI in LUT  
		DicomInterface::getInstance()->SetImageVOI((double)trackBar2->Value, (double)trackBar1->Value);
		int index = trackBar2->Value;
		label5->Text = Convert::ToString(index);
		interX->displayDicomImage(panel1);

	}

#pragma endregion

#pragma region Active tags on panel

			 Point^ _LastClickPosition = gcnew Point(); /**< mouse clicked point  */
			 int fontSize = 8; /**< font size */
			 int _TagCount_Current = 0; /**< Number of tags added by user on panel */
			 const int _TagCount_Max = 50; /**< maximum number of tags on panel */

										   /**
										   *  @author Emilia Siemieniuk and Paulina Nowak
										   *  @brief set unvisible tagcombobox after selecting item
										   *
										   *  @param [in] System::Object^  sender
										   *  @param [in] System::Windows::Forms::MouseEventArgs^  e
										   *  @return none
										   */
	private: System::Void tagsComboBox_DropDownClosed(System::Object^  sender, System::EventArgs^  e)
	{
		tagsComboBox->Visible = false;
	}

			 /**
			 *  @author Emilia Siemieniuk and Paulina Nowak
			 *  @brief creating labels on panel
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::Windows::Forms::MouseEventArgs^  e
			 *  @return none
			 */
	private: System::Void tagsComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		// if selected index equals -1 - no one item was choosen 
		if (tagsComboBox->SelectedIndex == -1)
			return;
		// increment tag number
		_TagCount_Current++;
		// create new label
		System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
		label->AutoSize = true;
		label->Location = System::Drawing::Point(181, 53);
		label->Size = System::Drawing::Size(25, 9);
		label->Font = (gcnew System::Drawing::Font(L"SegoeUI", fontSize, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		label->ForeColor = Color::White;
		label->BackColor = Color::Transparent;
		label->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainView::tagLabel_MouseClick);
		label->Text = tagsComboBox->SelectedItem->ToString();
		// add label and set ist localisation
		panel1->Controls->Add(label);
		//localisation = mouse clicked point
		(label->Location) = System::Drawing::Point(_LastClickPosition->X, _LastClickPosition->Y);
	}

			 /**
			 *  @author Emilia Siemieniuk and Paulina Nowak
			 *  @brief mouse clicked on labels listener
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::Windows::Forms::MouseEventArgs^  e
			 *  @return none
			 */
	private: System::Void tagLabel_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		// check if it was a right mouse button
		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			// if yes, decrement number of labels
			_TagCount_Current--;
			(panel1->Controls)->Remove((System::Windows::Forms::Control^) sender);
		}
	}

			 /**
			 *  @author Emilia Siemieniuk and Paulina Nowak
			 *  @brief mouse clicked on panel listener
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::Windows::Forms::MouseEventArgs^  e
			 *  @return none
			 */
	private: System::Void tagsPanel_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		// check if it was left mouse button - clicked
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			// check if it possible to add next tag on panel
			if (_TagCount_Current >= _TagCount_Max)
			{
				//show messagebox
				MessageBox::Show("You can't add next tag");
			}
			else
			{
				//set up mouse clicked point localisation
				_LastClickPosition = e->Location;
				// show comboBox with tags
				tagsComboBox->Location = e->Location;
				tagsComboBox->SelectedIndex = -1;
				tagsComboBox->DroppedDown = true;
				tagsComboBox->Visible = true;
			}
		}
	}

			 /**
			 *  @author Jakub Maci퉓
			 *  @brief Change font size listener
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		fontSize = Convert::ToInt32(numericUpDown1->Value);
	}

#pragma endregion

#pragma region ComboBoxes listeners

			 /**
			 *Comboboxe's listeners of selecting items and put it into textboxes
			 */
	private: System::Void comboBox_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(0, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox2_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(1, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox3_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(2, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox4_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(3, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox5_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(4, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox6_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(5, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox7_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(6, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox8_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(7, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox9_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(8, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox10_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(9, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox11_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(10, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox12_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(11, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox13_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(12, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox14_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(13, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox15_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(14, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox16_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(15, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox17_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(16, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox18_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(17, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox19_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(18, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox20_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(19, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox21_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(20, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox22_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(21, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox23_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(22, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox24_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(23, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox25_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(24, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox26_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(25, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox27_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(26, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox28_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(27, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox29_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(28, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox30_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(29, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox31_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(30, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox32_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(31, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox33_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(32, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox34_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(33, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox35_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(34, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox36_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(35, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox37_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(36, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox38_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(37, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox39_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(38, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox40_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(39, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox41_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(40, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox42_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(41, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox43_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(42, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox44_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(43, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox45_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(44, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox46_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(45, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox47_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(46, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox48_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(47, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox49_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(48, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
	private: System::Void comboBox50_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		interX->setValueSelected(49, listVal, listDesc, textBoxList, textBoxFList, comboList);
	}
#pragma endregion

	};
}



