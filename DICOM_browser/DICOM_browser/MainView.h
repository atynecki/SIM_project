#pragma once

#include "DicomInterface.h"
#include <list>
#include <vector>

namespace DICOM_browser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(46, 45);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(592, 358);
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
			// panel1
			// 
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(48, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(684, 426);
			this->panel1->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 406);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 2;
			this->label4->Text = L"label4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(630, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 0;
			this->label2->Text = L"label2";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(916, 251);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 71);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainView::button1_Click);
			// 
			// MainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1206, 694);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel1);
			this->Name = L"MainView";
			this->Text = L"DICOM Browser";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainView::MainView_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region View controller code
		private:
			/**
			*  @brief Load DICOM data from file
			*
			*  @param [in] path - path to DICOM file
			*  @return none
			*/
			void loadDicomData(std::string path)
			{
				DicomInterface::getInstance()->loadData(path);
			}

			/**
			*  @brief Load DICOM image
			*
			*  Get image from Dicom interface and transform to Bitmap
			*  @param none
			*  @return dicom image in Bitmap form
			*/
			Bitmap^ loadDicomImage()
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
			*  @brief Display DICOM image
			*
			*  Load dicom image and add to picture box
			*  @param none
			*  @return none
			*/
			void displayDicomImage()
			{
				this->pictureBox1->Image = loadDicomImage();
				this->pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
			}

			/**
			*  @brief Save data panel to image file
			*
			*  Get destination path and extansion with SaveImageDialog, save panel to image file
			*  @param none
			*  @return none
			*/
			void savePanelToImageFile()
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
					
					/* Fram panel to bitmap */
					this->panel1->DrawToBitmap(bmp, rc);

					/* Save bitmap to image file */
					bmp->Save(saveImageDialog->FileName);
				}
			}

			/**
			*  @brief Change image contrast
			*
			*  @param [in] windowCenter - value of window center
			*  @param [in] windowWidth - value of window width
			*  @return none
			*/
			void changeContrast(double windowCenter, double windowWidth)
			{
				DicomInterface::getInstance()->SetImageVOI(windowCenter, windowWidth);
				displayDicomImage();
			}
#pragma endregion

	private: System::Void MainView_Load(System::Object^  sender, System::EventArgs^  e) {
		
		/* Example of use DicomInterface */
		loadDicomData("D:\\Projects\\GIT\\SIM_project\\image\\CT-MONO2-16-ankle");
		//displayDicomImage();

		//std::vector<std::string> desc = DicomInterface::getInstance()->getDataRecordDescriptionList();
		//std::vector<std::string> val = DicomInterface::getInstance()->getDataRecordValueList();
		int32_t maxPixel = DicomInterface::getInstance()->GetImageData()->GetMaxPixel();
		int32_t minPixel = DicomInterface::getInstance()->GetImageData()->GetMinPixel();
		double windowCenter = DicomInterface::getInstance()->GetImageData()->GetVOI().center;
		double windowWidth = DicomInterface::getInstance()->GetImageData()->GetVOI().width;
		std::string windowWidthStr = DicomInterface::getInstance()->GetImageData()->GetWindowWidth();

		changeContrast(windowCenter, (windowWidth*0.5));
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		/* Example of use SavePaneToImageFile */
		savePanelToImageFile();
	}
};
}
