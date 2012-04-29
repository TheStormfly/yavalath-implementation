#include "StdAfx.h"
#include "Minimax.h"


Minimax::Minimax(void)
{
}


Minimax::~Minimax(void)
{
}



//passar cor invertida?
//float Minimax::Negascout(unsigned char board[],  short int  *bestMove, float alpha, float beta, int depth, short int color)
//{
//		float a, b, t, i;
//        this->miniMaxCount++;
//
//		 //if(depth ==0)
//			//return evaluate(nodo);
//
//		a = alpha;
//		b = beta;
//
//		color = 3 - color; // inverte cor para passar
//		ArrayList^ filhos = this->ai->JogadasPossiveis(this->board->board, color);
//
//		for(int i=0; i<filhos->Count; i++) // para cada filho, chama o negascout 
//		{
//		  t = - Negascout( filhos[i], *bestMove, -b, -a, depth-1, color);
//		  if ( (t > a) && (t < beta) && (i > 0) && (depth < maxDepth-1) )
//			 a = - Negascout( filhos[i], *bestMove, -beta, -t, depth-1, color);    /* re-search */
//		  a = max( a, t );
//		  if ( a >= beta )
//			 return a;                                /* cut-off */
//		  b = a + 1;                      /* set new null window */
//	    }
//	    return a;
//}
    