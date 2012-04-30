#include "StdAfx.h"
#include "Minimax.h"


Minimax::Minimax(void)
{
}


Minimax::~Minimax(void)
{
}


// beta é valor maior, e alpha menor
//passar cor invertida?
//float Minimax::Negascout(unsigned char board[],  short int  *bestMove, float alpha, float beta, int depth, short int color)
//{
//		float a, b, t;
//        this->miniMaxCount++;
//
//		 //if(depth ==0)
//			//return evaluate(board, color);
//
//		a = alpha;
//		b = beta;
//
//		color = 3 - color; // inverte cor para passar
//		ArrayList^ filhos = gcnew ArrayList;
//		filhos = ai.JogadasPossiveis(board, color);
//
//		for(int i=0; i<filhos->Count; i++) // para cada filho, chama o negascout 
//		{
//		  //t = - Negascout( aux[i], bestMove, -b, -a, depth-1, color);
//
//		  if ( (t > a) && (t < beta) && (i > 0) && (depth < maxDepth-1) )
//		  {
//			 //a = - Negascout( filhos[i], bestMove, -beta, -t, depth-1, color);    /* re-search */
//		  }
//		  
//		  a = max( a, t );
//
//		  if ( a >= beta )
//			 return a;                                /* cut-off */
//		  
//		  b = a + 1;                      /* set new null window */
//	    }
//	    return a;
//}


char Enemy(char avaliando)
{
	if(avaliando=='1')
		return('2');
	else
		return('1');
}
    

float Minimax::Evaluate(unsigned char board[], int pos,int OurColor)
{
	float evaluate=0.5;
	int winOrLose[3];
	
	//caso ja nao esteja colocado a nova jogada no tabuleiro
	board[pos]=OurColor;
	
	char buffer[10];
	char OurC;
	char OurE;
	
	//transforma int to char
	_itoa_s (OurColor,buffer,10);
	OurC=buffer[0];
	//ve qm eh nosso oponente
	OurE=Enemy(OurC);	


    // ve se a jogada nos leva a derrota ou vitoria
	winOrLose[0]=AvaliaVitoriaHorizontal(pos, OurColor, board);
	winOrLose[1]=AvaliaVitoriaDiagonal(pos, OurColor, board);
	winOrLose[2]=AvaliaVitoriaDiagonal2(pos, OurColor, board);
	
	if(winOrLose[0]==OurC || winOrLose[1]==OurC || winOrLose[2]==OurC)
	{
		return(1);//caso de vitória
	}
	if(winOrLose[0]==OurE || winOrLose[1]==OurE || winOrLose[2]==OurE)
	{
		return(0);//caso de derrota
	}

	//outras heuristicas



	return (evaluate);
}


char Minimax::AvaliaVitoriaHorizontal(int posIni, int avaliar, unsigned char board[])
{

	char buffer[10];
	_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
	char avaliando=buffer[0];
	int posFin;

	//definições feitas olhando o tabuleiro
	
	if(posIni>=0 && posIni<5){ posFin=2;posIni=0;}
	else if(posIni>=5 && posIni<11){ posFin=8;posIni=5;}
	else if(posIni>=11 && posIni<18){ posFin=15;posIni=11;}
	else if(posIni>=18 && posIni<26){ posFin=23;posIni=18;}
	else if(posIni>=26 && posIni<35){ posFin=32;posIni=26;}
	else if(posIni>=35 && posIni<43){ posFin=40;posIni=35;}
	else if(posIni>=43 && posIni<50){ posFin=47;posIni=43;}
	else if(posIni>=50 && posIni<56){ posFin=53;posIni=50;}
	else if(posIni>=56 && posIni<61){ posFin=58;posIni=56;}
	else return('0');//espero nao cair aki
	
	for(int i=posIni; i<=posFin;i++)
	{
		if(board[i]==avaliando && board[i+1]==avaliando && board[i+2]==avaliando)
		{
			if(i!=posFin && board[i+3]==avaliando)//ganhou
				return(avaliando);
			else//oponente ganhou
				return(Enemy(avaliando));
		}
		else{}	//nothing
		
	}

	return('0');
}


char Minimax::AvaliaVitoriaDiagonal(int posIni, int avaliar,unsigned char board[]) //    "/"
	{
	
	char buffer[10];
	_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
	char avaliando=buffer[0];

	int salto[4];
	int listaPulo[8]={5,6,7,8,8,7,6,5};
	int posFin=0;	
	int primeiroPulo=0;
	int fimInt=0;

	//definições feitas olhando o tabuleiro
	
	if(posIni==0 || posIni==5 || posIni==11 || posIni==18 || posIni==26){ posFin=26;primeiroPulo=0;fimInt=2;posIni=0;}
	else if(posIni==1 || posIni==6 || posIni==12 || posIni==19 || posIni==27 || posIni==35){ posFin=35;primeiroPulo=0;fimInt=3;posIni=1;}
	else if(posIni==2 || posIni==7 || posIni==13 || posIni==20 || posIni==28 || posIni==36 || posIni==43){ posFin=43;primeiroPulo=0;fimInt=4;posIni=2;}
	else if(posIni==3 || posIni==8 || posIni==14 || posIni==21 || posIni==29 || posIni==37 || posIni==44 || posIni==50){ posFin=50;primeiroPulo=0;fimInt=5;posIni=3;}
	else if(posIni==4 || posIni==9 || posIni==15 || posIni==22 || posIni==30 || posIni==38 || posIni==45 || posIni==51 || posIni==56){ posFin=56;primeiroPulo=0;fimInt=6;posIni=4;}
	else if(posIni==10 || posIni==16 || posIni==23 || posIni==31 || posIni==39 || posIni==46 || posIni==52 || posIni==57){ posFin=57;primeiroPulo=1;fimInt=6;posIni=10;}
	else if(posIni==17 || posIni==24 || posIni==32 || posIni==40 || posIni==47 || posIni==53 || posIni==58){ posFin=58;primeiroPulo=2;fimInt=6;posIni=17;}
	else if(posIni==25 || posIni==33 || posIni==41 || posIni==48 || posIni==54 || posIni==59){ posFin=59;primeiroPulo=3;fimInt=6;posIni=25;}
	else if(posIni==34 || posIni==42 || posIni==49 || posIni==55 || posIni==60){ posFin=60;primeiroPulo=4;fimInt=6;posIni=34;}
	else return('0');//espero nao cair aki
	
	//verifica diagonal
	
	
	for(int i=primeiroPulo; i<=fimInt;i++)
	{
				
			salto[0]=posIni;
			salto[1]=salto[0]+listaPulo[i];
			salto[2]=salto[1]+listaPulo[i+1];
			salto[3]=salto[2]+listaPulo[i+2];
				
			if(board[salto[0]]==avaliando && board[salto[1]]==avaliando && board[salto[2]]==avaliando)
			{
				if((i!=fimInt) && board[salto[3]] ==avaliando)//ganhou, se nao eh a ultima celula (pois o salto avaliado ali sai do tabueliro) 
					return(avaliando);
				else//oponente ganhou
					return(Enemy(avaliando));
			}
			else{}//nothing
		posIni=posIni+listaPulo[i];			

		
		
	}
	return('0');


}

char Minimax::AvaliaVitoriaDiagonal2(int posIni, int avaliar,unsigned char board[]) //    "\"
{
	
	char buffer[10];
	_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
	char avaliando=buffer[0];

	int salto[4];
	int listaPulo[9]={5,6,7,8,9,9,8,7,6};
	int posFin=0;	
	int primeiroPulo=0;
	int fimInt=0;

	//definições feitas olhando o tabuleiro
	
	if(posIni==4 || posIni==10 || posIni==17 || posIni==25 || posIni==34){ posFin=34;primeiroPulo=1;fimInt=3;posIni=4;}
	else if(posIni==3 || posIni==9 || posIni==16 || posIni==24 || posIni==33 || posIni==42){ posFin=42;primeiroPulo=1;fimInt=4;posIni=3;}
	else if(posIni==2 || posIni==8 || posIni==15 || posIni==23 || posIni==32 || posIni==41 || posIni==49){ posFin=49;primeiroPulo=1;fimInt=5;posIni=2;}
	else if(posIni==1 || posIni==7 || posIni==14 || posIni==22 || posIni==31 || posIni==40 || posIni==48 || posIni==55){ posFin=55;primeiroPulo=1;fimInt=6;posIni=1;}
	else if(posIni==0 || posIni==6 || posIni==13 || posIni==21 || posIni==30 || posIni==39 || posIni==47 || posIni==54 || posIni==60){ posFin=60;primeiroPulo=1;fimInt=6;posIni=0;}
	else if(posIni==5 || posIni==12 || posIni==20 || posIni==29 || posIni==38 || posIni==46 || posIni==53 || posIni==59){ posFin=59;primeiroPulo=2;fimInt=6;posIni=5;}
	else if(posIni==11 || posIni==19 || posIni==28 || posIni==37 || posIni==45 || posIni==52 || posIni==58){ posFin=58;primeiroPulo=3;fimInt=7;posIni=11;}
	else if(posIni==18 || posIni==27 || posIni==36 || posIni==44 || posIni==51 || posIni==57){ posFin=57;primeiroPulo=4;fimInt=7;posIni=18;}
	else if(posIni==26 || posIni==35 || posIni==43 || posIni==50 || posIni==56){ posFin=56;primeiroPulo=5;fimInt=6;posIni=26;}
	else return('0');//espero nao cair aki
	
	//verifica diagonal
	
	
	for(int i=primeiroPulo; i<=fimInt;i++)
	{
				
			salto[0]=posIni;
			salto[1]=salto[0]+listaPulo[i];
			salto[2]=salto[1]+listaPulo[i+1];
			salto[3]=salto[2]+listaPulo[i+2];
				
			if(board[salto[0]]==avaliando && board[salto[1]]==avaliando && board[salto[2]]==avaliando)
			{
				if((i!=fimInt) && board[salto[3]] ==avaliando)//ganhou, se nao eh a ultima celula (pois o salto avaliado ali sai do tabueliro) 
					return(avaliando);
				else//oponente ganhou
					return(Enemy(avaliando));
			}
			else{}//nothing
		posIni=posIni+listaPulo[i];			

		
		
	}
	return('0');


}
	