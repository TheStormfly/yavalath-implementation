#pragma once
#include "stdafx.h"
class Minimax
{
	public:
		int miniMaxCount;
		Minimax(void);
		~Minimax(void);
		void AlphaBetaMinimax(Board board, short int *bestMove, float alpha, float beta, int depth);
};

