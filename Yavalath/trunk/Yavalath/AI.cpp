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

void AI::Play()
{
	//a[0] = (Rec *)malloc(sizeof(Rec));
}

int Avaliacao(jogada)
{
	
	return(rand() % 10 + 1);

}

//////retorna quantas jogadas existe para fazer
//ArrayList JogadasPossiveis(unsigned char boardOrig[61], char ourCor)
//{
//	
//	//jogada nJogada;
//	ArrayList jogadasIniciais;
//
//	
//	
//	return (jogadasIniciais);
//}




