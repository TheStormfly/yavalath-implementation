#include "stdafx.h"
#include <sstream>
#include <string>
//***IMPORTANTE
//cor preto = 2
//cor branca = 1
//cor amarela = 0



Board::Board(void)
{
	Initialize();
	
}

Board::~Board()
{
	for(int i=0; i<61; i++)
		delete hexagonVector[i];
}




void Board::Initialize()
{
	this->newgame = false;// vari�vel de controle de newgame

	for(int i=0; i<61;i++)
		board.b[i]='0';

	//First line
	this->hexagonVector.push_back(new Hexagon(157, 38));
	this->hexagonVector.push_back(new Hexagon(217, 38));
	this->hexagonVector.push_back(new Hexagon(277, 38));
	this->hexagonVector.push_back(new Hexagon(337, 38));
	this->hexagonVector.push_back(new Hexagon(397, 38));
	//Second Line
	this->hexagonVector.push_back(new Hexagon(127, 89));
	this->hexagonVector.push_back(new Hexagon(187, 89));
	this->hexagonVector.push_back(new Hexagon(247, 89));
	this->hexagonVector.push_back(new Hexagon(307, 89));
	this->hexagonVector.push_back(new Hexagon(367, 89));
	this->hexagonVector.push_back(new Hexagon(427, 89));
	//Third Line
	this->hexagonVector.push_back(new Hexagon(97, 140));
	this->hexagonVector.push_back(new Hexagon(157, 140));
	this->hexagonVector.push_back(new Hexagon(217, 140));
	this->hexagonVector.push_back(new Hexagon(277, 140));
	this->hexagonVector.push_back(new Hexagon(337, 140));
	this->hexagonVector.push_back(new Hexagon(397, 140));
	this->hexagonVector.push_back(new Hexagon(457, 140));
	//4th Line
	this->hexagonVector.push_back(new Hexagon(67, 191));
	this->hexagonVector.push_back(new Hexagon(127, 191));
	this->hexagonVector.push_back(new Hexagon(187, 191));
	this->hexagonVector.push_back(new Hexagon(247, 191));
	this->hexagonVector.push_back(new Hexagon(307, 191));
	this->hexagonVector.push_back(new Hexagon(367, 191));
	this->hexagonVector.push_back(new Hexagon(427, 191));
	this->hexagonVector.push_back(new Hexagon(487, 191));
	//Main Line
	this->hexagonVector.push_back(new Hexagon(37, 246));
	this->hexagonVector.push_back(new Hexagon(97, 246));
	this->hexagonVector.push_back(new Hexagon(157, 246));
	this->hexagonVector.push_back(new Hexagon(217, 246));
	this->hexagonVector.push_back(new Hexagon(277, 246));
	this->hexagonVector.push_back(new Hexagon(337, 246));
	this->hexagonVector.push_back(new Hexagon(397, 246));
	this->hexagonVector.push_back(new Hexagon(457, 246));
	this->hexagonVector.push_back(new Hexagon(517, 246));
	//
	this->hexagonVector.push_back(new Hexagon(67, 297));
	this->hexagonVector.push_back(new Hexagon(127, 297));
	this->hexagonVector.push_back(new Hexagon(187, 297));
	this->hexagonVector.push_back(new Hexagon(247, 297));
	this->hexagonVector.push_back(new Hexagon(307, 297));
	this->hexagonVector.push_back(new Hexagon(367, 297));
	this->hexagonVector.push_back(new Hexagon(427, 297));
	this->hexagonVector.push_back(new Hexagon(487, 297));
	//
	this->hexagonVector.push_back(new Hexagon(97, 350));
	this->hexagonVector.push_back(new Hexagon(157, 350));
	this->hexagonVector.push_back(new Hexagon(217, 350));
	this->hexagonVector.push_back(new Hexagon(277, 350));
	this->hexagonVector.push_back(new Hexagon(337, 350));
	this->hexagonVector.push_back(new Hexagon(397, 350));
	this->hexagonVector.push_back(new Hexagon(457, 350));
	//
	this->hexagonVector.push_back(new Hexagon(127, 403));
	this->hexagonVector.push_back(new Hexagon(187, 403));
	this->hexagonVector.push_back(new Hexagon(247, 403));
	this->hexagonVector.push_back(new Hexagon(307, 403));
	this->hexagonVector.push_back(new Hexagon(367, 403));
	this->hexagonVector.push_back(new Hexagon(427, 403));
	//
	this->hexagonVector.push_back(new Hexagon(157, 454));
	this->hexagonVector.push_back(new Hexagon(217, 454));
	this->hexagonVector.push_back(new Hexagon(277, 454));
	this->hexagonVector.push_back(new Hexagon(337, 454));
	this->hexagonVector.push_back(new Hexagon(397, 454));


}

Ponto Board::returnHexPonto(short int bestMove)
{

	return hexagonVector[bestMove]->getCenter();
	
}

bool Board::hexagonoClicadoEhValido(int x, int y, Ponto *p, short int ourColor)
{
	for(int i=0; i<61; i++)
	{
		if(this->hexagonVector[i]->isInsideHexagon(x, y))
		{
			if(this->board.b[i]=='0')//ve se ta desocupado
			{
				if(ourColor == 1)
				this->board.b[i] = '2';
				else this->board.b[i] = '1';

				*p = hexagonVector[i]->getCenter();
				return true;
			}
		}

	}

	return false;
}

string Board::PrintBoard()
{
	unsigned char teste[61] = "unsigned char array";
	stringstream buffer;
	
	buffer << this->board.b;
	string final(buffer.str());
	return(final);
}



//opera�oes para verificar ganhador

char Board::IsGameOver(unsigned char board[])
{

	char resultados[18];
	
	resultados[0]=AvaliaHorizontal(0,1,board);
	resultados[1]=AvaliaHorizontal(5,1,board);
	resultados[2]=AvaliaHorizontal(11,1,board);
	resultados[3]=AvaliaHorizontal(18,1,board);
	resultados[4]=AvaliaHorizontal(26,1,board);
	resultados[5]=AvaliaHorizontal(35,1,board);
	resultados[6]=AvaliaHorizontal(43,1,board);
	resultados[7]=AvaliaHorizontal(50,1,board);
	resultados[8]=AvaliaHorizontal(56,1,board);	
	
	resultados[9]=AvaliaHorizontal(0,2,board);
	resultados[10]=AvaliaHorizontal(5,2,board);
	resultados[11]=AvaliaHorizontal(11,2,board);
	resultados[12]=AvaliaHorizontal(18,2,board);
	resultados[13]=AvaliaHorizontal(26,2,board);
	resultados[14]=AvaliaHorizontal(35,2,board);
	resultados[15]=AvaliaHorizontal(43,2,board);
	resultados[16]=AvaliaHorizontal(50,2,board);
	resultados[17]=AvaliaHorizontal(56,2,board);
	
	char resultados1[18];
		//"/"
	resultados1[0]=AvaliaDiagonal1(0,1,board);
	resultados1[1]=AvaliaDiagonal1(5,1,board);
	resultados1[2]=AvaliaDiagonal1(11,1,board);
	resultados1[3]=AvaliaDiagonal1(18,1,board);
	resultados1[4]=AvaliaDiagonal1(26,1,board);
	resultados1[5]=AvaliaDiagonal1(35,1,board);
	resultados1[6]=AvaliaDiagonal1(43,1,board);
	resultados1[7]=AvaliaDiagonal1(50,1,board);
	resultados1[8]=AvaliaDiagonal1(56,1,board);	
	
	resultados1[9]=AvaliaDiagonal1(0,2,board);
	resultados1[10]=AvaliaDiagonal1(5,2,board);
	resultados1[11]=AvaliaDiagonal1(11,2,board);
	resultados1[12]=AvaliaDiagonal1(18,2,board);
	resultados1[13]=AvaliaDiagonal1(26,2,board);
	resultados1[14]=AvaliaDiagonal1(35,2,board);
	resultados1[15]=AvaliaDiagonal1(43,2,board);
	resultados1[16]=AvaliaDiagonal1(50,2,board);
	resultados1[17]=AvaliaDiagonal1(56,2,board);
	

	int resultados2[18];//"\"
	
	resultados2[0]=AvaliaDiagonal2(0,1,board);
	resultados2[1]=AvaliaDiagonal2(5,1,board);
	resultados2[2]=AvaliaDiagonal2(11,1,board);
	resultados2[3]=AvaliaDiagonal2(18,1,board);
	resultados2[4]=AvaliaDiagonal2(26,1,board);
	resultados2[5]=AvaliaDiagonal2(35,1,board);
	resultados2[6]=AvaliaDiagonal2(43,1,board);
	resultados2[7]=AvaliaDiagonal2(50,1,board);
	resultados2[8]=AvaliaDiagonal2(56,1,board);	
	
	resultados2[9]=AvaliaDiagonal2(0,2,board);
	resultados2[10]=AvaliaDiagonal2(5,2,board);
	resultados2[11]=AvaliaDiagonal2(11,2,board);
	resultados2[12]=AvaliaDiagonal2(18,2,board);
	resultados2[13]=AvaliaDiagonal2(26,2,board);
	resultados2[14]=AvaliaDiagonal2(35,2,board);
	resultados2[15]=AvaliaDiagonal2(43,2,board);
	resultados2[16]=AvaliaDiagonal2(50,2,board);
	resultados2[17]=AvaliaDiagonal2(56,2,board);
	//

	for(int i=0;i<18;i++)
	{
		if(resultados[i]!='0')
		return(resultados[i]);
	}
	
	
	for(int i=0;i<18;i++)
	{
		if(resultados1[i]!='0')
		return(resultados1[i]);
	}
	
	for(int i=0;i<18;i++)
	{
		if(resultados2[i]!='0')
			return(resultados2[i]);
	}
	return('0');
			
	
}

char Board::AvaliaGame(int posIni, int avaliar, unsigned char board[])
{

	char buffer[10];
	_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
	char avaliando=buffer[0];
	_itoa_s ((3-avaliar),buffer,10);
	char oponente=buffer[0];
	int posFin;
	
	

	//defini��es feitas olhando o tabuleiro
	
	if(posIni==0){ posFin=2;}
	else if(posIni==5){ posFin=8;}
	else if(posIni==11){ posFin=15;}
	else if(posIni==18){ posFin=23;}
	else if(posIni==26){ posFin=32;}
	else if(posIni==35){ posFin=40;}
	else if(posIni==43){ posFin=47;}
	else if(posIni==50){ posFin=53;}
	else if(posIni==56){ posFin=58;}
	else return('0');//espero nao cair aki
	
	for(int i=posIni; i<=posFin;i++)
	{
		if(board[i]==avaliando && board[i+1]==avaliando && board[i+2]==avaliando)
		{
			if(i!=posFin && board[i+3]==avaliando)//ganhou
				return(avaliando);
			else//oponente ganhou
				return(oponente);
		}
		else{}	//nothing
		
	}

	return('0');
}

char Board::AvaliaHorizontal(int posIni, int avaliar, unsigned char board[]) //    "/"
{

	return(AvaliaGame(posIni,avaliar,board));
	return('0');
}


char Board::AvaliaDiagonal1(int posIni, int avaliar, unsigned char board[]) //    "/"
{
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
	
	return(AvaliaGame(posIni,avaliar,copia));
	return('0');
}

//char Board::AvaliaDiagonal1(int posIni, int avaliar) //    "/"
//{
//	unsigned char copia[61];
//	
//	
//	for(int i=0;i<61;i++)
//	{
//		copia[i]=board.b[i];
//	}
//
//	return(AvaliaGame(posIni,avaliar,board.b));
//
//
//	//char buffer[10];
//	//_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
//	//char avaliando=buffer[0];
//
//	//int salto[4];
//	//int listaPulo[8]={5,6,7,8,8,7,6,5};
//	//int posFin=0;	
//	//int primeiroPulo=0;
//	//int fimInt=0;
//
//	////defini��es feitas olhando o tabuleiro
//	//
//	//if(posIni==0){ posFin=26;primeiroPulo=0;fimInt=2;}
//	//else if(posIni==1){ posFin=35;primeiroPulo=0;fimInt=3;}
//	//else if(posIni==2){ posFin=43;primeiroPulo=0;fimInt=4;}
//	//else if(posIni==3){ posFin=50;primeiroPulo=0;fimInt=5;}
//	//else if(posIni==4){ posFin=56;primeiroPulo=0;fimInt=6;}
//	//else if(posIni==10){ posFin=57;primeiroPulo=1;fimInt=6;}
//	//else if(posIni==17){ posFin=58;primeiroPulo=2;fimInt=6;}
//	//else if(posIni==25){ posFin=59;primeiroPulo=3;fimInt=6;}
//	//else if(posIni==34){ posFin=60;primeiroPulo=4;fimInt=6;}
//	//else return('0');//espero nao cair aki
//	//
//	////verifica diagonal
//	//
//	//
//	//for(int i=primeiroPulo; i<=fimInt;i++)
//	//{
//	//			
//	//		salto[0]=posIni;
//	//		salto[1]=salto[0]+listaPulo[i];
//	//		salto[2]=salto[1]+listaPulo[i+1];
//	//		salto[3]=salto[2]+listaPulo[i+2];
//	//			
//	//		if(board.b[salto[0]]==avaliando && board.b[salto[1]]==avaliando && board.b[salto[2]]==avaliando)
//	//		{
//	//			if((i!=fimInt) && board.b[salto[3]] ==avaliando)//ganhou, se nao eh a ultima celula (pois o salto avaliado ali sai do tabueliro) 
//	//				return(avaliando);
//	//			else//oponente ganhou
//	//				return(Oponente(avaliando));
//	//		}
//	//		else{}//nothing
//	//	posIni=posIni+listaPulo[i];			
//
//	//	
//	//	
//	//}
//	//return('0');
//
//
//}

char Board::AvaliaDiagonal2(int posIni, int avaliar, unsigned char board[]) //    "\"
{
	unsigned char copia[61];
	copia[0]=board[4];   copia[1]=board[10];   copia[2]=board[17];   copia[3]=board[25];   copia[4]=board[34];
	copia[5]=board[3];   copia[6]=board[9];   copia[7]=board[16];   copia[8]=board[24];   copia[9]=board[33];   copia[10]=board[42];
	copia[11]=board[2];   copia[12]=board[8];   copia[13]=board[15];   copia[14]=board[23];   copia[15]=board[32];   copia[16]=board[41];   copia[17]=board[49];
	copia[18]=board[1];   copia[19]=board[7];   copia[20]=board[14];   copia[21]=board[22];   copia[22]=board[31];   copia[23]=board[40];   copia[24]=board[48];   copia[25]=board[55];
	copia[26]=board[0];   copia[27]=board[6];   copia[28]=board[13];   copia[29]=board[21];   copia[30]=board[30];   copia[31]=board[39];   copia[32]=board[47];   copia[33]=board[54];   copia[34]=board[60];
	copia[35]=board[5];   copia[36]=board[12];   copia[37]=board[20];   copia[38]=board[29];   copia[39]=board[38];   copia[40]=board[46];   copia[41]=board[53];   copia[42]=board[59];
	copia[43]=board[11];   copia[44]=board[19];   copia[45]=board[28];   copia[46]=board[37];   copia[47]=board[45];   copia[48]=board[52];   copia[49]=board[58];
	copia[50]=board[18];   copia[51]=board[27];   copia[52]=board[36];   copia[53]=board[44];   copia[54]=board[51];   copia[55]=board[57];
	copia[56]=board[26];   copia[57]=board[35];   copia[58]=board[43];   copia[59]=board[50];   copia[60]=board[56];
	
	return(AvaliaGame(posIni,avaliar,copia));
	return('0');
	

}
	