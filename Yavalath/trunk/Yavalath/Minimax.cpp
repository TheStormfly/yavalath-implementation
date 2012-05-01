﻿#include "StdAfx.h"
#include "Minimax.h"


Minimax::Minimax(void)
{
	this->newGame = false;
}


Minimax::~Minimax(void)
{
}


// beta é valor maior, e alpha menor
// enemy
double Minimax::Negamax(structBoard game, double alpha, double beta, int depth, short int color)
{
		double t;

		 if(depth == 0)
			return (Evaluate(game.b,color));//evaluate(board, color);



		//color = 3 - color; // inverte cor para passar
		vector<short int> filhos;
		this->JogadasPossiveis(game, &filhos, color);

		for(int i=0; i <(int)filhos.size(); i++) // para cada filho, chama o negamax 
		{
			game.b[filhos[i]]=color;
            t = - Negamax(game, -beta, -alpha, depth-1,  3-color);
            
            if (t >= beta)
                return t;

            if (t > alpha)
				alpha = t;
		}
	    return alpha;
}


double AreaValiosa(unsigned char board[],unsigned char copia[],unsigned char copia1[], char C)
{
	double evaluate=0;
	for(int i=18;i<=42;i++)
	{
		if(board[i]==C )
		{
			evaluate +5;//mais cores no meio melhor
		}
		if(i>=26 && i<=34)
		{
			evaluate +5;//mais no meio melhor ainda
		}
	}

	for(int i=18;i<=42;i++)
	{
		if(copia[i]==C )
		{
			evaluate +5;//mais cores no meio melhor
		}
		if(i>=26 && i<=34)
		{
			evaluate +5;//mais no meio melhor ainda
		}
	}

	for(int i=18;i<=42;i++)
	{
		if(copia1[i]==C )
		{
			evaluate +5;//mais cores no meio melhor
		}
		if(i>=26 && i<=34)
		{
			evaluate +5;//mais no meio melhor ainda
		}
	}
	return evaluate;

}

double PeçaInimigaSozinha(unsigned char board[],unsigned char copia[],unsigned char copia1[], char C)
{
	//for(int i=18;i<=42;i++)
	//if(
	return (2);
}

double Minimax::Evaluate(unsigned char board[],int OurColor)
{
	double evaluate=0;
			
	char buffer[10];
	char OurC;
	char OurE;
	char vazio='0';
	
	//transforma int to char
	_itoa_s (OurColor,buffer,10);
	OurC=buffer[0];	
	//ve qm eh nosso oponente
	_itoa_s (3-OurColor,buffer,10);
	OurE=buffer[0];

	//copia para avaliar diagonal '/'
	unsigned char copia[61];	
	copia[0]=board[0];   copia[1]=board[5];   copia[2]=board[11];   copia[3]=board[18];   copia[4]=board[26];
	copia[5]=board[1];   copia[6]=board[6];   copia[7]=board[12];   copia[8]=board[19];   copia[9]=board[27];   copia[10]=board[35];
	copia[11]=board[2];   copia[12]=board[7];   copia[13]=board[13];   copia[14]=board[20];   copia[15]=board[28];   copia[16]=board[36];   copia[17]=board[43];
	copia[18]=board[3];   copia[19]=board[8];   copia[20]=board[14];   copia[21]=board[21];   copia[22]=board[29];   copia[23]=board[37];   copia[24]=board[44];   copia[25]=board[50];
	copia[26]=board[4];   copia[27]=board[9];   copia[28]=board[15];   copia[29]=board[22];   copia[30]=board[30];   copia[31]=board[38];   copia[32]=board[45];   copia[33]=board[51];   copia[34]=board[56];
	copia[35]=board[10];   copia[36]=board[16];   copia[37]=board[23];   copia[38]=board[31];   copia[39]=board[39];   copia[40]=board[46];   copia[41]=board[52];   copia[42]=board[57];
	copia[43]=board[17];   copia[44]=board[24];   copia[45]=board[32];   copia[46]=board[40];   copia[47]=board[47];   copia[48]=board[53];   copia[49]=board[58];
	copia[50]=board[25];   copia[51]=board[33];   copia[52]=board[41];   copia[53]=board[48];   copia[54]=board[54];   copia[55]=board[59];
	copia[56]=board[34];   copia[57]=board[42];   copia[58]=board[49];   copia[59]=board[55];   copia[60]=board[60];
	
	//copia para avaliar diagonal '\'
	unsigned char copia1[61];
	copia1[0]=board[4];   copia1[1]=board[10];   copia1[2]=board[17];   copia1[3]=board[25];   copia1[4]=board[34];
	copia1[5]=board[3];   copia1[6]=board[9];   copia1[7]=board[16];   copia1[8]=board[24];   copia1[9]=board[33];   copia1[10]=board[42];
	copia1[11]=board[2];   copia1[12]=board[8];   copia1[13]=board[15];   copia1[14]=board[23];   copia1[15]=board[32];   copia1[16]=board[41];   copia1[17]=board[49];
	copia1[18]=board[1];   copia1[19]=board[7];   copia1[20]=board[14];   copia1[21]=board[22];   copia1[22]=board[31];   copia1[23]=board[40];   copia1[24]=board[48];   copia1[25]=board[55];
	copia1[26]=board[0];   copia1[27]=board[6];   copia1[28]=board[13];   copia1[29]=board[21];   copia1[30]=board[30];   copia1[31]=board[39];   copia1[32]=board[47];   copia1[33]=board[54];   copia1[34]=board[60];
	copia1[35]=board[5];   copia1[36]=board[12];   copia1[37]=board[20];   copia1[38]=board[29];   copia1[39]=board[38];   copia1[40]=board[46];   copia1[41]=board[53];   copia1[42]=board[59];
	copia1[43]=board[11];   copia1[44]=board[19];   copia1[45]=board[28];   copia1[46]=board[37];   copia1[47]=board[45];   copia1[48]=board[52];   copia1[49]=board[58];
	copia1[50]=board[18];   copia1[51]=board[27];   copia1[52]=board[36];   copia1[53]=board[44];   copia1[54]=board[51];   copia1[55]=board[57];
	copia1[56]=board[26];   copia1[57]=board[35];   copia1[58]=board[43];   copia1[59]=board[50];   copia1[60]=board[56];

	//ganhar ou perder
	if(empDoBoard->IsGameOver(board)==OurC)
		return 9999999999999;
	else if (empDoBoard->IsGameOver(board)==OurE)
		return -9999999999999;
	
	evaluate=evaluate+AreaValiosa(board,copia,copia1,OurC);
	
	if(board[31]='2');
	evaluate=99999;
	return(evaluate);
}



//aqui faz a chamada do negascout com os primeiros filhos do board
void Minimax::Play(structBoard board)
{

	vector<short int> filhos;
	this->JogadasPossiveis(board, &filhos, enemyColor);
	double g, bestValue = -99999;

	for(short int i=0; i <(short int)filhos.size(); i++) // para cada filho, chama o negascout 
	{
		board.b[filhos[i]]= ourColor;
		g= -Negamax(board, -9999, 9999, 3, enemyColor);

		if(g > bestValue)
		{
			bestValue = g;
			this->bestMove = filhos[i];
		}

	} 

}


////retorna quantas jogadas existe para fazer
void Minimax::JogadasPossiveis(structBoard game, vector<short int> *filhos, char ourColor)
{
	for(int i=0;i<61;i++)
	{
		if(game.b[i]=='0')
		{
			(*filhos).push_back(i);
		}
	}
	
}
	