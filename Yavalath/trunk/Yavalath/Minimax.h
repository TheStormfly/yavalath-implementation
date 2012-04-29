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
		void Negascout(unsigned char board[], short int *bestMove, float alpha, float beta, int depth, short int color);
};

