#include "StdAfx.h"
#include "Minimax.h"


Minimax::Minimax(void)
{
	this->newGame = false;
}


Minimax::~Minimax(void)
{
}

char CorToChar(int cor)
{

	char buffer[44];
	_itoa_s (cor,buffer,10);
	return (buffer[0]);	
}




double AreaValiosa(unsigned char board[],unsigned char copia[],unsigned char copia1[], char OurC,char OurE)
{
	double evaluate=0;
	for(int i=18;i<=42;i++)
	{
		if(board[i]==OurC )
		{
			evaluate=evaluate +5;;//mais cores no meio melhor
		}
		if(i>=26 && i<=34)
		{
			evaluate=evaluate +5;;//mais no meio melhor ainda
		}
	}

	for(int i=18;i<=42;i++)
	{
		if(copia[i]==OurC )
		{
			evaluate=evaluate +5;;//mais cores no meio melhor
		}
		if(i>=26 && i<=34)
		{
			evaluate=evaluate +5;;//mais no meio melhor ainda
		}
	}

	for(int i=18;i<=42;i++)
	{
		if(copia1[i]==OurC )
		{
			evaluate=evaluate +5;//mais cores no meio melhor
		}
		if(i>=26 && i<=34)
		{
			evaluate=evaluate +5;;//mais no meio melhor ainda
		}
	}
	return evaluate;

}

double JogadaAQuatro(unsigned char board[],unsigned char copia[],unsigned char copia1[], char OurC,char OurE)
{
	double evaluate=0;

	///****horizontal
	for(int i=0;i<2;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=5;i<8;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=11;i<15;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=18;i<23;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=26;i<=32;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=35;i<=40;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=43;i<=47;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=50;i<=53;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=56;i<=58;i++)
	{
		if(board[i]==OurC && board[i+1]=='0' && board[i+2]=='0' && board[i+3]==OurC)
		evaluate=evaluate+50;
	}
	///****diagonal1
	for(int i=0;i<2;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=5;i<8;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=11;i<15;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=18;i<23;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=26;i<=32;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=35;i<=40;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=43;i<=47;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=50;i<=53;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=56;i<=58;i++)
	{
		if(copia[i]==OurC && copia[i+1]=='0' && copia[i+2]=='0' && copia[i+3]==OurC)
		evaluate=evaluate+50;
	}
	///****diagonal2
	for(int i=0;i<2;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=5;i<8;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=11;i<15;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=18;i<23;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=26;i<=32;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=35;i<=40;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=43;i<=47;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=50;i<=53;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	for(int i=56;i<=58;i++)
	{
		if(copia1[i]==OurC && copia1[i+1]=='0' && copia1[i+2]=='0' && copia1[i+3]==OurC)
		evaluate=evaluate+50;
	}
	return(evaluate);

}



double PeçaInimigaSozinha(unsigned char board[],unsigned char copia[],unsigned char copia1[], char OurC,char OurE)
{
	
	
	double evaluate=0;
	bool resolvido[59];//caso ele veja q em outra diagonal isso ja foi resolvido ele desiste de colocar ali
	
	for(int i=0;i<59;i++)
	{
		resolvido[i]=false;
	}
		
	for(int i=2;i<59;i=i++)
	{
		if(board[i]==OurE && board[i+1]==OurE && ((board[i-1]==OurC) ^ (board[i-2]==OurC)))
		{
			evaluate=evaluate+20;
			resolvido[i]=true;
		}
	}
	for(int i=2;i<59;i++)
	{
		if(copia[i]==OurE && copia[i+1]==OurE && ((board[i-1]==OurC) ^ (board[i-2]==OurC)))
		{
			if(resolvido[i]==false)
			{
				evaluate=evaluate+20; //
				resolvido[i]=true;
			}
		}
	}
	for(int i=2;i<59;i++)
	{
		if(copia[i]==OurE && copia[i+1]==OurE && ((board[i-1]==OurC) ^ (board[i-2]==OurC)))
		{
			if(resolvido[i]==false)
			evaluate=evaluate+20; //
		}
	}
	
	return (evaluate);
}

double Minimax::Evaluate(unsigned char board[],int OurColor)
{
	double evaluate=0;
			
	char OurC;
	char OurE;
	char vazio='0';
	
	//transforma int to char
	 OurC=CorToChar(OurColor);
	//ve qm eh nosso oponente
	 OurE=CorToChar(3-OurColor);
	

	//copia para avaliar diagonal '/'
	unsigned char copia[61];	
	//copia[0]=board[0];   copia[1]=board[5];   copia[2]=board[11];   copia[3]=board[18];   copia[4]=board[26];
	//copia[5]=board[1];   copia[6]=board[6];   copia[7]=board[12];   copia[8]=board[19];   copia[9]=board[27];   copia[10]=board[35];
	//copia[11]=board[2];   copia[12]=board[7];   copia[13]=board[13];   copia[14]=board[20];   copia[15]=board[28];   copia[16]=board[36];   copia[17]=board[43];
	//copia[18]=board[3];   copia[19]=board[8];   copia[20]=board[14];   copia[21]=board[21];   copia[22]=board[29];   copia[23]=board[37];   copia[24]=board[44];   copia[25]=board[50];
	//copia[26]=board[4];   copia[27]=board[9];   copia[28]=board[15];   copia[29]=board[22];   copia[30]=board[30];   copia[31]=board[38];   copia[32]=board[45];   copia[33]=board[51];   copia[34]=board[56];
	//copia[35]=board[10];   copia[36]=board[16];   copia[37]=board[23];   copia[38]=board[31];   copia[39]=board[39];   copia[40]=board[46];   copia[41]=board[52];   copia[42]=board[57];
	//copia[43]=board[17];   copia[44]=board[24];   copia[45]=board[32];   copia[46]=board[40];   copia[47]=board[47];   copia[48]=board[53];   copia[49]=board[58];
	//copia[50]=board[25];   copia[51]=board[33];   copia[52]=board[41];   copia[53]=board[48];   copia[54]=board[54];   copia[55]=board[59];
	//copia[56]=board[34];   copia[57]=board[42];   copia[58]=board[49];   copia[59]=board[55];   copia[60]=board[60];
	//
	////copia para avaliar diagonal '\'
	//unsigned char copia1[61];
	//copia1[0]=board[4];   copia1[1]=board[10];   copia1[2]=board[17];   copia1[3]=board[25];   copia1[4]=board[34];
	//copia1[5]=board[3];   copia1[6]=board[9];   copia1[7]=board[16];   copia1[8]=board[24];   copia1[9]=board[33];   copia1[10]=board[42];
	//copia1[11]=board[2];   copia1[12]=board[8];   copia1[13]=board[15];   copia1[14]=board[23];   copia1[15]=board[32];   copia1[16]=board[41];   copia1[17]=board[49];
	//copia1[18]=board[1];   copia1[19]=board[7];   copia1[20]=board[14];   copia1[21]=board[22];   copia1[22]=board[31];   copia1[23]=board[40];   copia1[24]=board[48];   copia1[25]=board[55];
	//copia1[26]=board[0];   copia1[27]=board[6];   copia1[28]=board[13];   copia1[29]=board[21];   copia1[30]=board[30];   copia1[31]=board[39];   copia1[32]=board[47];   copia1[33]=board[54];   copia1[34]=board[60];
	//copia1[35]=board[5];   copia1[36]=board[12];   copia1[37]=board[20];   copia1[38]=board[29];   copia1[39]=board[38];   copia1[40]=board[46];   copia1[41]=board[53];   copia1[42]=board[59];
	//copia1[43]=board[11];   copia1[44]=board[19];   copia1[45]=board[28];   copia1[46]=board[37];   copia1[47]=board[45];   copia1[48]=board[52];   copia1[49]=board[58];
	//copia1[50]=board[18];   copia1[51]=board[27];   copia1[52]=board[36];   copia1[53]=board[44];   copia1[54]=board[51];   copia1[55]=board[57];
	//copia1[56]=board[26];   copia1[57]=board[35];   copia1[58]=board[43];   copia1[59]=board[50];   copia1[60]=board[56];

	//ganhar ou perder
	if(empDoBoard->IsGameOver(board)==OurC)
		return 9999999999999;
	else if (empDoBoard->IsGameOver(board)==OurE)
		return -9999999999999;
	
	//evaluate=evaluate+AreaValiosa(board,copia,copia1,OurC,OurE);
	//evaluate=evaluate+PeçaInimigaSozinha(board,copia,copia1,OurC,OurE);
	//evaluate=evaluate+JogadaAQuatro(board,copia,copia1,OurC,OurE);
	return(evaluate);
}

// beta é valor maior, e alpha menor
// enemy
double Minimax::Negamax(structBoard game, double alpha, double beta, int depth, short int color)
{
		double max = -99999;
		char OurC=CorToChar(color);
		char OurE=CorToChar(3-color);
		//structBoard b;
		//for(int i=0;i<61;i++)
		//b.b[i]=game.b[i];

		if(depth == 0)
		{
			double j=Evaluate(game.b,color);
			return (j);
		}
		else
		{
			if(empDoBoard->IsGameOver(game.b)==OurE)//ve se é derrota
			{
				return beta;	
			}
			else
			{
				//color = 3 - color; // inverte cor para passar
				vector<short int> child;
				this->JogadasPossiveis(game, &child,OurC);

				for(int i=0; i <(int)child.size(); i++) // para cada filho, chama o negamax 
				{
					if(clock() >= this->endTime)
						break;

					b.b[child[i]]=OurC;
				   double x = - Negamax(b, -beta, -alpha, depth-1,(3-color));
					b.b[child[i]]='0';

					if (x>max) 
						max = x;
					if (x>alpha) 
						alpha = x;
					if (alpha>=beta) 
						return alpha;
				}
				return max;
			}

		}
		return max;
}

//aqui faz a chamada do negascout com os primeiros filhos do board
void Minimax::Play(structBoard board1)
{
	this->endTime = clock() + (5 * CLOCKS_PER_SEC);

	char OurC=CorToChar(ourColor);
	char OurE=CorToChar(enemyColor);
	structBoard b;
	
	for(int i=0;i<61;i++)
    b.b[i]=board1.b[i];

	vector<short int> filhos;
	this->JogadasPossiveis(b, &filhos, OurC);
	double g, bestValue = -99999;

	for(short int i=0; i <(short int)filhos.size(); i++) // para cada filho, chama o negascout 
	{
		b.b[filhos[i]]= OurC;
		g= -Negamax(b, -9999, 9999, 3, enemyColor);
		b.b[filhos[i]]= '0';
		if(g > bestValue)
		{
			bestValue = g;
			this->bestMove = filhos[i];
		}
		
		if(clock() >= this->endTime)
			return;

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
	