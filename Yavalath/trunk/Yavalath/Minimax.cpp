#include "StdAfx.h"
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
			return 1;//evaluate(board, color);



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



    

double Minimax::Evaluate(unsigned char board[],int OurColor)
{
	double evaluate=0.5;
	int winOrLose[3];
	double pontos=0;
	
	//caso ja nao esteja colocado a nova jogada no tabuleiro
//	board[pos]=OurColor;
	
	char buffer[10];
	char OurC;
	char OurE;
	
	//transforma int to char
	_itoa_s (OurColor,buffer,10);
	OurC=buffer[0];
	
	//ve qm eh nosso oponente
	OurE=3-OurC;


    // ve se a jogada nos leva a derrota ou vitoria
	//winOrLose[0]=AvaliaVitoriaHorizontal(pos, OurColor, board);
	//winOrLose[1]=AvaliaVitoriaDiagonal(pos, OurColor, board);
	//winOrLose[2]=AvaliaVitoriaDiagonal2(pos, OurColor, board);
	//
	//if(winOrLose[0]==OurC || winOrLose[1]==OurC || winOrLose[2]==OurC)
	//{
	//	return(1);//caso de vitória
	//}
	//if(winOrLose[0]==OurE || winOrLose[1]==OurE || winOrLose[2]==OurE)
	//{
	//	return(0);//caso de derrota
	//}

	//***********outras heuristicas******************


	//horizontais importantes
	//if(pos>=26 && pos<35)
	//{
	//	//puntuação da linha do meio vale mais
	//	if(pos>=28 && pos<32)
	//	{
	//		pontos=0.2;
	//		evaluate=pontos+(pontos*evaluate);
	//	}
	//    pontos=0.5;
	//	evaluate=pontos+(pontos*evaluate);
	//}	
	//
	////diagonais importantes "/"
	//if(pos==4 || pos==9 || pos==15 || pos==22 || pos==30 || pos==38 || pos==45 || pos==51 || pos==56)
	//{
	//	//puntuação mais do meio vale mais
	//	if(pos==22 || pos==30 || pos==38)
	//	{
	//		pontos=0.2;
	//		evaluate=pontos+(pontos*evaluate);
	//	}
	//    pontos=0.5;
	//	evaluate=pontos+(pontos*evaluate);
	//}

	////diagonais importantes "\"
	//if(pos==0 || pos==6 || pos==13 || pos==21 || pos==30 || pos==39 || pos==47 || pos==54 || pos==60)
	//{
	//	//puntuação mais do meio vale mais
	//	if(pos==21 || pos==30 || pos==39)
	//	{
	//		pontos=0.2;
	//		evaluate=pontos+(pontos*evaluate);
	//	}
	//    pontos=0.5;
	//	evaluate=pontos+(pontos*evaluate);
	//}
	


	return (evaluate);
}


//char Minimax::AvaliaVitoriaHorizontal(int posIni, int avaliar, unsigned char board[])
//{
//
//	char buffer[10];
//	_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
//	char avaliando=buffer[0];
//	int posFin;
//
//	//definições feitas olhando o tabuleiro
//	
//	if(posIni>=0 && posIni<5){ posFin=2;posIni=0;}
//	else if(posIni>=5 && posIni<11){ posFin=8;posIni=5;}
//	else if(posIni>=11 && posIni<18){ posFin=15;posIni=11;}
//	else if(posIni>=18 && posIni<26){ posFin=23;posIni=18;}
//	else if(posIni>=26 && posIni<35){ posFin=32;posIni=26;}
//	else if(posIni>=35 && posIni<43){ posFin=40;posIni=35;}
//	else if(posIni>=43 && posIni<50){ posFin=47;posIni=43;}
//	else if(posIni>=50 && posIni<56){ posFin=53;posIni=50;}
//	else if(posIni>=56 && posIni<61){ posFin=58;posIni=56;}
//	else return('0');//espero nao cair aki
//	
//	for(int i=posIni; i<=posFin;i++)
//	{
//		if(board[i]==avaliando && board[i+1]==avaliando && board[i+2]==avaliando)
//		{
//			if(i!=posFin && board[i+3]==avaliando)//ganhou
//				return(avaliando);
//			else//oponente ganhou
//				return(Enemy(avaliando));
//		}
//		else{}	//nothing
//		
//	}
//
//	return('0');
//}
//
//
//char Minimax::AvaliaVitoriaDiagonal(int posIni, int avaliar,unsigned char board[]) //    "/"
//	{
//	
//	char buffer[10];
//	_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
//	char avaliando=buffer[0];
//
//	int salto[4];
//	int listaPulo[8]={5,6,7,8,8,7,6,5};
//	int posFin=0;	
//	int primeiroPulo=0;
//	int fimInt=0;
//
//	//definições feitas olhando o tabuleiro
//	
//	if(posIni==0 || posIni==5 || posIni==11 || posIni==18 || posIni==26){ posFin=26;primeiroPulo=0;fimInt=2;posIni=0;}
//	else if(posIni==1 || posIni==6 || posIni==12 || posIni==19 || posIni==27 || posIni==35){ posFin=35;primeiroPulo=0;fimInt=3;posIni=1;}
//	else if(posIni==2 || posIni==7 || posIni==13 || posIni==20 || posIni==28 || posIni==36 || posIni==43){ posFin=43;primeiroPulo=0;fimInt=4;posIni=2;}
//	else if(posIni==3 || posIni==8 || posIni==14 || posIni==21 || posIni==29 || posIni==37 || posIni==44 || posIni==50){ posFin=50;primeiroPulo=0;fimInt=5;posIni=3;}
//	else if(posIni==4 || posIni==9 || posIni==15 || posIni==22 || posIni==30 || posIni==38 || posIni==45 || posIni==51 || posIni==56){ posFin=56;primeiroPulo=0;fimInt=6;posIni=4;}
//	else if(posIni==10 || posIni==16 || posIni==23 || posIni==31 || posIni==39 || posIni==46 || posIni==52 || posIni==57){ posFin=57;primeiroPulo=1;fimInt=6;posIni=10;}
//	else if(posIni==17 || posIni==24 || posIni==32 || posIni==40 || posIni==47 || posIni==53 || posIni==58){ posFin=58;primeiroPulo=2;fimInt=6;posIni=17;}
//	else if(posIni==25 || posIni==33 || posIni==41 || posIni==48 || posIni==54 || posIni==59){ posFin=59;primeiroPulo=3;fimInt=6;posIni=25;}
//	else if(posIni==34 || posIni==42 || posIni==49 || posIni==55 || posIni==60){ posFin=60;primeiroPulo=4;fimInt=6;posIni=34;}
//	else return('0');//espero nao cair aki
//	
//	//verifica diagonal
//	
//	
//	for(int i=primeiroPulo; i<=fimInt;i++)
//	{
//				
//			salto[0]=posIni;
//			salto[1]=salto[0]+listaPulo[i];
//			salto[2]=salto[1]+listaPulo[i+1];
//			salto[3]=salto[2]+listaPulo[i+2];
//				
//			if(board[salto[0]]==avaliando && board[salto[1]]==avaliando && board[salto[2]]==avaliando)
//			{
//				if((i!=fimInt) && board[salto[3]] ==avaliando)//ganhou, se nao eh a ultima celula (pois o salto avaliado ali sai do tabueliro) 
//					return(avaliando);
//				else//oponente ganhou
//					return(Enemy(avaliando));
//			}
//			else{}//nothing
//		posIni=posIni+listaPulo[i];			
//
//		
//		
//	}
//	return('0');
//
//
//}
//
//char Minimax::AvaliaVitoriaDiagonal2(int posIni, int avaliar,unsigned char board[]) //    "\"
//{
//	
//	char buffer[10];
//	_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
//	char avaliando=buffer[0];
//
//	int salto[4];
//	int listaPulo[9]={5,6,7,8,9,9,8,7,6};
//	int posFin=0;	
//	int primeiroPulo=0;
//	int fimInt=0;
//
//	//definições feitas olhando o tabuleiro
//	
//	if(posIni==4 || posIni==10 || posIni==17 || posIni==25 || posIni==34){ posFin=34;primeiroPulo=1;fimInt=3;posIni=4;}
//	else if(posIni==3 || posIni==9 || posIni==16 || posIni==24 || posIni==33 || posIni==42){ posFin=42;primeiroPulo=1;fimInt=4;posIni=3;}
//	else if(posIni==2 || posIni==8 || posIni==15 || posIni==23 || posIni==32 || posIni==41 || posIni==49){ posFin=49;primeiroPulo=1;fimInt=5;posIni=2;}
//	else if(posIni==1 || posIni==7 || posIni==14 || posIni==22 || posIni==31 || posIni==40 || posIni==48 || posIni==55){ posFin=55;primeiroPulo=1;fimInt=6;posIni=1;}
//	else if(posIni==0 || posIni==6 || posIni==13 || posIni==21 || posIni==30 || posIni==39 || posIni==47 || posIni==54 || posIni==60){ posFin=60;primeiroPulo=1;fimInt=6;posIni=0;}
//	else if(posIni==5 || posIni==12 || posIni==20 || posIni==29 || posIni==38 || posIni==46 || posIni==53 || posIni==59){ posFin=59;primeiroPulo=2;fimInt=6;posIni=5;}
//	else if(posIni==11 || posIni==19 || posIni==28 || posIni==37 || posIni==45 || posIni==52 || posIni==58){ posFin=58;primeiroPulo=3;fimInt=7;posIni=11;}
//	else if(posIni==18 || posIni==27 || posIni==36 || posIni==44 || posIni==51 || posIni==57){ posFin=57;primeiroPulo=4;fimInt=7;posIni=18;}
//	else if(posIni==26 || posIni==35 || posIni==43 || posIni==50 || posIni==56){ posFin=56;primeiroPulo=5;fimInt=6;posIni=26;}
//	else return('0');//espero nao cair aki
//	
//	//verifica diagonal
//	
//	
//	for(int i=primeiroPulo; i<=fimInt;i++)
//	{
//				
//			salto[0]=posIni;
//			salto[1]=salto[0]+listaPulo[i];
//			salto[2]=salto[1]+listaPulo[i+1];
//			salto[3]=salto[2]+listaPulo[i+2];
//				
//			if(board[salto[0]]==avaliando && board[salto[1]]==avaliando && board[salto[2]]==avaliando)
//			{
//				if((i!=fimInt) && board[salto[3]] ==avaliando)//ganhou, se nao eh a ultima celula (pois o salto avaliado ali sai do tabueliro) 
//					return(avaliando);
//				else//oponente ganhou
//					return(Enemy(avaliando));
//			}
//			else{}//nothing
//		posIni=posIni+listaPulo[i];			
//
//		
//		
//	}
//	return('0');
//
//
//}



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
	