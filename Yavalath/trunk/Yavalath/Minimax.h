#pragma once
#include "stdafx.h"

class Minimax
{
	public:
		short int bestMove;
		short int ourColor;
		short int enemyColor;
		bool newGame;
		Minimax(void);
		~Minimax(void);
		void Play(structBoard board);
		void JogadasPossiveis(structBoard game, vector<short int> *filhos, char ourColor);
		int maxDepth;
		int miniMaxCount;
		double Negamax(structBoard game, double alpha, double beta, int depth, short int color);
		double Minimax::Evaluate(unsigned char board[], int pos,int OurColor);
		char Minimax::AvaliaVitoriaDiagonal(int posIni, int avaliar,unsigned char board[]);
		char Minimax::AvaliaVitoriaDiagonal2(int posIni, int avaliar,unsigned char board[]);
		char Minimax::AvaliaVitoriaHorizontal(int posIni, int avaliar, unsigned char board[]);

};

