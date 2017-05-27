#pragma once

#include "DicomInterface.h"
#include <list>

namespace DICOM_browser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;

	/// <summary>
	/// Summary for MainView
	/// </summary>
	public ref class MainView : public System::Windows::Forms::Form
	{
	public:
		MainView(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
			}
		}
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Label^  label1;
	public:
		void setName(String^ name)
		{
			this->label1->Text = name;
		}
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;
			 Bitmap^ image;
	public:
		void setImage(Bitmap^ image)
		{
			this->pictureBox1->Image = image;
		}

	protected:

	private:
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 23);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->SizeMode = PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->linkLabel1->LinkColor = System::Drawing::Color::Black;
			this->linkLabel1->Location = System::Drawing::Point(870, 48);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(235, 40);
			this->linkLabel1->TabIndex = 1;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Patient Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::Color::Navy;
			this->label1->Location = System::Drawing::Point(873, 127);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 40);
			this->label1->TabIndex = 2;
			this->label1->Text = L"patient name";
			// 
			// MainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1206, 694);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainView";
			this->Text = L"DICOM Browser";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainView::MainView_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region View controller code
		private:
			void loadDicomData(std::string path)
			{
				DicomInterface::getInstance()->loadData(path);
			}

			void displayDicomImage()
			{
				uint32_t width;
				uint32_t height;
				std::string imageBuffer;

				imageBuffer = DicomInterface::getInstance()->getImage(&width, &height);
				String^ buffer_ptr = gcnew String(imageBuffer.c_str());
				IntPtr sptr = Marshal::StringToHGlobalAnsi(buffer_ptr);
				Bitmap^ image = gcnew Bitmap(width, height, 4*width, Imaging::PixelFormat::Format32bppArgb, sptr);
				this->pictureBox1->Image = image;
			}
#pragma endregion

	private: System::Void MainView_Load(System::Object^  sender, System::EventArgs^  e) {
		
		loadDicomData("D:\\Projects\\GIT\\SIM_project\\image\\CT-MONO2-16-ankle");
		displayDicomImage();

		std::list<std::string> desc = DicomInterface::getInstance()->getDataRecordDescriptionList();
		std::list<std::string> val = DicomInterface::getInstance()->getDataRecordValueList();
	}
	};
}
