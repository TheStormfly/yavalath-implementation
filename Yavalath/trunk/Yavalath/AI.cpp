#pragma once
#include "stdafx.h"




struct jogada {
    
	int nJogada; 
	unsigned char board[61];
    int avaliado;
    
};


AI::AI(void)
{
	this->newGame = false;
}

//aqui faz a chamada do negascout com os primeiros filhos do board
void AI::Play()
{
	//Minimax *minimax = new Minimax();
	////a[0] = (Rec *)malloc(sizeof(Rec));
	//ArrayList^ filhosIniciais = gcnew ArrayList;
	//for(int i=0; i<filhosIniciais->Count; i++)
	//{
	// minimax->Negascout(filhosIniciais[i], *bestMove, -9999, 9999, 2, enemyColor);
	//}
}

int Avaliacao(jogada)
{
	
	return(rand() % 10 + 1);

}

////retorna quantas jogadas existe para fazer
ArrayList^ AI::JogadasPossiveis(unsigned char boardOrig[61], char ourCor)
{
	
	//jogada nJogada;
	ArrayList^ jogadasIniciais = gcnew ArrayList;
	
	return jogadasIniciais;
}




