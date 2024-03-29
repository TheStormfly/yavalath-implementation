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
		Board* boardCopy;
		Minimax* minimax;

	public:
		Form1(void)

		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			board = new Board();
			boardCopy = new Board();
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
			this->newgame = (gcnew System::Windows::Forms::Button());
			this->whiteone = (gcnew System::Windows::Forms::RadioButton());
			this->blackone = (gcnew System::Windows::Forms::RadioButton());
			this->Turno = (gcnew System::Windows::Forms::Label());
			this->selectComputer = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Location = System::Drawing::Point(-1, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(568, 504);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
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
			this->whiteone->Location = System::Drawing::Point(627, 350);
			this->whiteone->Name = L"whiteone";
			this->whiteone->Size = System::Drawing::Size(85, 17);
			this->whiteone->TabIndex = 0;
			this->whiteone->TabStop = true;
			this->whiteone->Text = L"Brancas";
			this->whiteone->UseVisualStyleBackColor = true;
			this->whiteone->CheckedChanged += gcnew System::EventHandler(this, &Form1::whiteone_CheckedChanged);
			// 
			// blackone
			// 
			this->blackone->Location = System::Drawing::Point(687, 350);
			this->blackone->Name = L"blackone";
			this->blackone->Size = System::Drawing::Size(85, 17);
			this->blackone->TabIndex = 2;
			this->blackone->TabStop = true;
			this->blackone->Text = L"Pretas";
			this->blackone->UseVisualStyleBackColor = true;
			// 
			// Turno
			// 
			this->Turno->AutoSize = true;
			this->Turno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Turno->Location = System::Drawing::Point(573, 135);
			this->Turno->Name = L"Turno";
			this->Turno->Size = System::Drawing::Size(65, 17);
			this->Turno->TabIndex = 7;
			this->Turno->Text = L"Tetralath";
			// 
			// selectComputer
			// 
			this->selectComputer->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) {L"White", L"Black"});
			this->selectComputer->FormattingEnabled = true;
			this->selectComputer->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Pretas", L"Brancas"});
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
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Come�ar:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(573, 394);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Computador:";
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
			this->Text = L"Tetralath";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	//evento quando alguma posi��o eh clicada
	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
				 if(this->minimax->newGame == false)
					 return;

				 Ponto p;
				 System::Drawing::SolidBrush^ myBrush2;
				 myBrush2 = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray);
			
				 if(this->board->hexagonoClicadoEhValido(e->X, e->Y, &p, minimax->ourColor))
				 {
					System::Drawing::SolidBrush^ myBrush;
					
				 
					if (minimax->enemyColor==2) //se somos as pretas
					{
						
						myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
						
					}
					else // se somos as brancas
					{
					
						myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
						
					}
				 
							
						if(board->IsGameOver(board->board.b)=='1')
							this->Turno->Text = L"BRANCAS GANHARAM";
						if(board->IsGameOver(board->board.b)=='2')
							this->Turno->Text = L"PRETAS GANHARAM";
						
					

					this->panel1->CreateGraphics()->FillEllipse(myBrush, p.X - 20, p.Y - 20, 42, 42);

					//chama o computador
					
					this->minimax->Play(board->board); // chama a ia (minimax...)

					if(minimax->ourColor == 1)
					{
						myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
						board->board.b[minimax->bestMove]= '1';
						if(board->IsGameOver(board->board.b)=='1')
							this->Turno->Text = L"BRANCAS GANHARAM";
						if(board->IsGameOver(board->board.b)=='2')
							this->Turno->Text = L"PRETAS GANHARAM";
						
					}
					else 
					{
							myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
							board->board.b[minimax->bestMove]= '2';
							if(board->IsGameOver(board->board.b)=='1')
							this->Turno->Text = L"BRANCAS GANHARAM";
							if(board->IsGameOver(board->board.b)=='2')
							this->Turno->Text = L"PRETAS GANHARAM";
							
					}
					
					p = board->returnHexPonto(minimax->bestMove);
					
					//cria para o novo
					this->panel1->CreateGraphics()->FillEllipse(myBrush2, p.X - 20, p.Y - 20, 42, 42);
					_sleep(700);
					this->panel1->CreateGraphics()->FillEllipse(myBrush, p.X - 20, p.Y - 20, 42, 42);
					
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 System::Drawing::SolidBrush^ myBrush;
				 this->board->Initialize();
				 this->panel1->Enabled = false;
				 this->panel1->Enabled = true;
				 this->minimax->newGame = false;
				 //recome�a jogo
				// System::Drawing::SolidBrush^ myBrush2;
				// Ponto p;
				 
				 if(this->whiteone->Checked)
				 {
					//this->board->SetTurn(1);
					 if(this->selectComputer->SelectedIndex == 1)
					 {
						 this->minimax->ourColor = 1;
						 this->minimax->enemyColor =2;
						 this->minimax->newGame = true;
						 this->minimax->Play(board->board); // chama a ia (minimax...)
						 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
						 			 
						 
						 
						 Ponto p = board->returnHexPonto(minimax->bestMove);
						 board->board.b[minimax->bestMove]= '1';					
						 this->panel1->CreateGraphics()->FillEllipse(myBrush, p.X - 20, p.Y - 20, 42, 42);

												 
						 if(board->IsGameOver(board->board.b)=='1')
						 this->Turno->Text = L"BRANCAS GANHARAM";
						 if(board->IsGameOver(board->board.b)=='2')
						 this->Turno->Text = L"PRETAS GANHARAM";
					
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
					 //this->board->SetTurn(2);
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
							 this->minimax->Play(board->board); // chama a ia (minimax...)
							 
							 myBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
						
							 Ponto p = board->returnHexPonto(minimax->bestMove);
							 board->board.b[minimax->bestMove]= '2';							
							 this->panel1->CreateGraphics()->FillEllipse(myBrush, p.X - 20, p.Y - 20, 42, 42);
							
							 
							 if(board->IsGameOver(board->board.b)=='1')
							 this->Turno->Text = L"BRANCAS GANHARAM";
							 if(board->IsGameOver(board->board.b)=='2')
							 this->Turno->Text = L"PRETAS GANHARAM";

							
						 }
					 }
				 }
				 
			 }
private: System::Void whiteone_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }


};
}

