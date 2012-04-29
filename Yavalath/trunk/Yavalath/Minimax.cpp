#include "StdAfx.h"
#include "Minimax.h"


Minimax::Minimax(void)
{
}


Minimax::~Minimax(void)
{
}



//public Grid MakeMove(Grid g)
//{
//    GridCells move;
//    this->miniMaxCount = 0;
//    Minimax(g, out move, float.MinValue, float.MaxValue);
//    Console.WriteLine("Minimax method calls: {0}", miniMaxCount);
//    return g.MakeMove(move);
//}

void Minimax::AlphaBetaMinimax(Board board,  short int  *bestMove, float alpha, float beta, int depth = 1)
{
        this->miniMaxCount++;

 

  //      if (board->IsWinner)
  //          //return 1f / depth;

  //      if (board->IsLoser)
  //          //return -1f / depth;

		//for (int i=0; i<

  //      foreach (var move in g.GetMoves())
  //      {
  //          var other = g.MakeMove(move);
  //          alpha = -Minimax(other, out garbage, -beta, -alpha, depth + 1);

  //          if (beta <= alpha)
  //              return alpha;

  //          if (alpha > bestResult)
  //          {
  //              best = move;
  //              bestResult = alpha;
  //          }
  //      }
  //      return bestResult;
}
    