#pragma once
#include "JogoIA.h"

namespace Yavalath {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  Pos1;
	private: System::Windows::Forms::Label^  Pos2;








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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Pos1 = (gcnew System::Windows::Forms::Label());
			this->Pos2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Yellow;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 8);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(563, 496);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Pos1
			// 
			this->Pos1->BackColor = System::Drawing::Color::Gold;
			this->Pos1->Location = System::Drawing::Point(140, 32);
			this->Pos1->Name = L"Pos1";
			this->Pos1->Size = System::Drawing::Size(36, 30);
			this->Pos1->TabIndex = 1;
			this->Pos1->Click += gcnew System::EventHandler(this, &Form1::Pos1_Click);
			// 
			// Pos2
			// 
			this->Pos2->BackColor = System::Drawing::Color::Gold;
			this->Pos2->Location = System::Drawing::Point(201, 32);
			this->Pos2->Name = L"Pos2";
			this->Pos2->Size = System::Drawing::Size(36, 30);
			this->Pos2->TabIndex = 1;
			this->Pos2->Click += gcnew System::EventHandler(this, &Form1::Pos2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 516);
			this->Controls->Add(this->Pos2);
			this->Controls->Add(this->Pos1);
			this->Controls->Add(this->pictureBox1);
			this->MaximumSize = System::Drawing::Size(577, 554);
			this->MinimumSize = System::Drawing::Size(577, 554);
			this->Name = L"Form1";
			this->Text = L"Yavalath";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	
	private: System::Void Pos1_Click(System::Object^  sender, System::EventArgs^  e) {
			 Pos1->BackColor = System::Drawing::Color::Black;	 
			 }
	private: System::Void Pos2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Pos2->BackColor = System::Drawing::Color::White;	 
			 }
	};
}

