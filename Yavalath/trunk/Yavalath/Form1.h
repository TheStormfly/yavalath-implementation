#include "stdafx.h"
#pragma once

namespace Yavalath {

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		Board* board;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			board = new Board();
			board->Initialize();
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
	private: System::Windows::Forms::Panel^  panel1;
	protected: 











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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Location = System::Drawing::Point(-1, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(563, 504);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 495);
			this->Controls->Add(this->panel1);
			this->MaximumSize = System::Drawing::Size(577, 533);
			this->MinimumSize = System::Drawing::Size(577, 533);
			this->Name = L"Form1";
			this->Text = L"Yavalath";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
				 System::Drawing::SolidBrush^ myBrush;
				 
				 if (true) // marca brancas
					myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
				 else
					myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);

					this->panel1->CreateGraphics()->FillEllipse(myBrush, e->X - 20, e->Y - 20, 45, 45);
			 }
	};
}

