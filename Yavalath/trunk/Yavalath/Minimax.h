#pragma once
#include "stdafx.h"

class Minimax
{
	public:
		AI ai;
		int maxDepth;
		int miniMaxCount;
		Minimax(void);
		~Minimax(void);
		float Negascout(unsigned char board[], short int *bestMove, float alpha, float beta, int depth, short int color);
		float Minimax::Evaluate(unsigned char board[], int pos,int OurColor);
		char Minimax::AvaliaVitoriaDiagonal(int posIni, int avaliar,unsigned char board[]);
		char Minimax::AvaliaVitoriaDiagonal2(int posIni, int avaliar,unsigned char board[]);
		char Minimax::AvaliaVitoriaHorizontal(int posIni, int avaliar, unsigned char board[]);

};

