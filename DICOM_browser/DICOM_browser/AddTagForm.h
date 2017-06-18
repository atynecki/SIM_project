#pragma once
/**
*  @file    AddTagForm.h
*  @author  Jakub Maci퉓
*  @date    May, 2017
*
*  @brief AddTagForm class header file
*
* A class represetning Windows Form to fill and add additional dicom tag.
* It contains textBoxessuch as: tag description, tag group number, tag element number, tag value
*
*/

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddTagForm
	/// </summary>
	public ref class AddTagForm : public System::Windows::Forms::Form
	{
	public:
		/**
		*  @brief Default constructor
		*/
		AddTagForm(void)
		{
			InitializeComponent();
		}

#pragma region 
		/**
		*  @author Jakub Maci퉓
		*  @brief Get added ID group
		*
		*  @param [in] none
		*  @return System::String^ group
		*/
	public: System::String^ getAddGr()
	{
		return group;
	}

			/**
			*  @author Jakub Maci퉓
			*  @brief Get added ID element
			*
			*  @param [in] none
			*  @return System::String^ element
			*/
	public: System::String^ getAddEl()
	{
		return element;
	}
			/**
			*  @author Jakub Maci퉓
			*  @brief Get added Description
			*
			*  @param [in] none
			*  @return System::String^ description
			*/
	public: System::String^ getAddDes()
	{
		return description;
	}
			/**
			*  @author Jakub Maci퉓
			*  @brief Get added value
			*
			*  @param [in] none
			*  @return System::String^ value
			*/
	public: System::String^ getAddVal()
	{
		return value;
	}

			/**
			*  @author Jakub Maci퉓
			*  @brief Button Cancel - listener
			*
			*  @param [in] System::Object^  sender
			*  @param [in] System::EventArgs^  e
			*  @return none
			*/
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

			 /**
			 *  @author Jakub Maci퉓
			 *  @brief Button Add Tag - listener write added texts to String variables
			 *
			 *  @param [in] System::Object^  sender
			 *  @param [in] System::EventArgs^  e
			 *  @return none
			 */
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		group = this->textBox1->Text;
		element = this->textBox2->Text;
		description = this->textBox3->Text;
		value = this->textBox4->Text;
		this->Close();

	}

#pragma endregion

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddTagForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Collections::Generic::List<String^>^ dataList;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private:  String^ group;
	private:  String^ element;
	private:  String^ description;
	private:  String^ value;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(53, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Group ID";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(156, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(156, 68);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 22);
			this->textBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(53, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Element ID";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(156, 122);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(558, 22);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(156, 184);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(558, 22);
			this->textBox4->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(56, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Description";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(59, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Value";
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button2->Location = System::Drawing::Point(156, 244);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(184, 46);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Add Tag";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddTagForm::button2_Click);
			// 
			// button3
			// 
			this->button3->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button3->Location = System::Drawing::Point(380, 244);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(189, 46);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Close";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AddTagForm::button3_Click);
			// 
			// AddTagForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(746, 302);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"AddTagForm";
			this->Text = L"Add Tags";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	};
}
