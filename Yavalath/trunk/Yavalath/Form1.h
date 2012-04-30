#pragma once
#include "stdafx.h"

namespace Yavalath {

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		Board* board;
		Minimax* minimax;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			board = new Board();
			minimax = new Minimax();
			this->minimax->newGame = false;
						
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
	private: System::Windows::Forms::Button^  newgame;
	private: System::Windows::Forms::RadioButton^  whiteone;
	private: System::Windows::Forms::RadioButton^  blackone;


	private: System::Windows::Forms::Label^  Turno;
	private: System::Windows::Forms::ComboBox^  selectComputer;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  estadoAtualBoard;


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
			this->estadoAtualBoard = (gcnew System::Windows::Forms::Label());
			this->newgame = (gcnew System::Windows::Forms::Button());
			this->whiteone = (gcnew System::Windows::Forms::RadioButton());
			this->blackone = (gcnew System::Windows::Forms::RadioButton());
			this->Turno = (gcnew System::Windows::Forms::Label());
			this->selectComputer = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->estadoAtualBoard);
			this->panel1->Location = System::Drawing::Point(-1, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(568, 504);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			// 
			// estadoAtualBoard
			// 
			this->estadoAtualBoard->AutoSize = true;
			this->estadoAtualBoard->Location = System::Drawing::Point(3, 0);
			this->estadoAtualBoard->Name = L"estadoAtualBoard";
			this->estadoAtualBoard->Size = System::Drawing::Size(89, 13);
			this->estadoAtualBoard->TabIndex = 0;
			this->estadoAtualBoard->Text = L"ESTADO ATUAL";
			// 
			// newgame
			// 
			this->newgame->Location = System::Drawing::Point(620, 455);
			this->newgame->Name = L"newgame";
			this->newgame->Size = System::Drawing::Size(92, 28);
			this->newgame->TabIndex = 1;
			this->newgame->Text = L"New Game";
			this->newgame->UseVisualStyleBackColor = true;
			this->newgame->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// whiteone
			// 
			this->whiteone->Location = System::Drawing::Point(611, 350);
			this->whiteone->Name = L"whiteone";
			this->whiteone->Size = System::Drawing::Size(85, 17);
			this->whiteone->TabIndex = 0;
			this->whiteone->TabStop = true;
			this->whiteone->Text = L"White";
			this->whiteone->UseVisualStyleBackColor = true;
			this->whiteone->CheckedChanged += gcnew System::EventHandler(this, &Form1::whiteone_CheckedChanged);
			// 
			// blackone
			// 
			this->blackone->Location = System::Drawing::Point(675, 350);
			this->blackone->Name = L"blackone";
			this->blackone->Size = System::Drawing::Size(85, 17);
			this->blackone->TabIndex = 2;
			this->blackone->TabStop = true;
			this->blackone->Text = L"Black";
			this->blackone->UseVisualStyleBackColor = true;
			// 
			// Turno
			// 
			this->Turno->AutoSize = true;
			this->Turno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Turno->Location = System::Drawing::Point(573, 135);
			this->Turno->Name = L"Turno";
			this->Turno->Size = System::Drawing::Size(105, 42);
			this->Turno->TabIndex = 7;
			this->Turno->Text = L"Turn:";
			// 
			// selectComputer
			// 
			this->selectComputer->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) {L"White", L"Black"});
			this->selectComputer->FormattingEnabled = true;
			this->selectComputer->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Black", L"White"});
			this->selectComputer->Location = System::Drawing::Point(634, 391);
			this->selectComputer->Name = L"selectComputer";
			this->selectComputer->Size = System::Drawing::Size(103, 21);
			this->selectComputer->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(573, 350);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Start:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(573, 394);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Computer:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 495);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->selectComputer);
			this->Controls->Add(this->Turno);
			this->Controls->Add(this->blackone);
			this->Controls->Add(this->whiteone);
			this->Controls->Add(this->newgame);
			this->Controls->Add(this->panel1);
			this->MaximumSize = System::Drawing::Size(800, 533);
			this->MinimumSize = System::Drawing::Size(800, 533);
			this->Name = L"Form1";
			this->Text = L"Yavalath";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	//evento quando alguma posição eh clicada
	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
				 if(this->minimax->newGame == false)
					 return;

				 Ponto p;
				 
				 if(this->board->hexagonoClicadoEhValido(e->X, e->Y, &p))
				 {
					System::Drawing::SolidBrush^ myBrush;
				 
					if (board->GetTurn()==2) //se o turno é das pretas
					{
						myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
						board->NextTurn();
						this->Turno->Text = L"Turn: White";//Muda de turno
						this->estadoAtualBoard->Text=gcnew String(board->PrintBoard().c_str());
						
					}
					else // se o turno é das brancas
					{
						myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
						board->NextTurn();
						this->Turno->Text = L"Turn: Black";//muda de turno
						this->estadoAtualBoard->Text=gcnew String(board->PrintBoard().c_str());
						
					}
				 
								
						if(board->horizontal()=='1')
							this->Turno->Text = L"BRANCAS GANHOOOO";
						if(board->horizontal()=='2')
							this->Turno->Text = L"PRETAS GANHOOOO";
						if(board->diagonal1()=='1')
							this->Turno->Text = L"BRANCAS GANHOOOO";
						if(board->diagonal1()=='2')
							this->Turno->Text = L"PRETAS GANHOOOO";
					

					this->panel1->CreateGraphics()->FillEllipse(myBrush, p.X - 20, p.Y - 20, 42, 42);
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 this->board->Initialize();
				 this->panel1->BackgroundImage = Image::FromFile("fundo.jpg");
				 this->minimax->newGame = false;
				 //recomeça jogo

				 
				 if(this->whiteone->Checked)
				 {
					this->board->SetTurn(1);
					 if(this->selectComputer->SelectedIndex == 1)
					 {
						 this->minimax->ourColor = 1;
						 this->minimax->enemyColor =2;
						 this->minimax->newGame = true;
						 this->minimax->Play(); // chama a ia (minimax...)
					 }
					 else if(this->selectComputer->SelectedIndex == 0)
					 {
						 this->minimax->ourColor = 2;
						 this->minimax->enemyColor = 1;
						 this->minimax->newGame = true;
					 }
				 }
				 else
				 {
					 this->board->SetTurn(2);
					 if(this->selectComputer->SelectedIndex == 1)
					 {
						 this->minimax->ourColor = 1;
						 this->minimax->enemyColor = 2;
						 this->minimax->newGame = true;
					 }
					 else 
					 {
						 if(this->selectComputer->SelectedIndex == 0)
						 {
							 this->minimax->ourColor = 2;
							 this->minimax->enemyColor =1;
							 this->minimax->newGame = true;
							 this->minimax->Play(); // chama a ia (minimax...)
						 }
					 }
				 }
				 
			 }
private: System::Void whiteone_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }


};
}

