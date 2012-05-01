#pragma once
#include "stdafx.h"

class Minimax
{
	public:
		Board *empDoBoard;
		
		short int bestMove;
		short int ourColor;
		short int enemyColor;
		bool newGame;
		Minimax(void);
		~Minimax(void);
		void Play(structBoard board);
		void JogadasPossiveis(structBoard game, vector<short int> *filhos, char ourColor);
		double Negamax(structBoard game, double alpha, double beta, int depth, short int color);
		double Minimax::Evaluate(unsigned char board[],int OurColor);
		

};

