#pragma once

class AI
{	
	public:
		short int bestMove;
		short int ourColor;
		short int enemyColor;
		bool newGame;
		AI(void);
		void Play();
		ArrayList^ JogadasPossiveis(unsigned char boardOrig[61], char ourCor);





	//int AI::Avaliacao(unsigned char board[]);
	

};