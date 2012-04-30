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
	this->newgame = false;// variável de controle de newgame

	for(int i=0; i<61;i++)
		board[i]='0';

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

bool Board::hexagonoClicadoEhValido(int x, int y, Ponto *p)
{
	for(int i=0; i<61; i++)
	{
		if(this->hexagonVector[i]->isInsideHexagon(x, y))
		{
			if(this->board[i]=='0')//ve se ta desocupado
			{
				if(this->GetTurn()==2) //se o turno é das pretas
					this->board[i] = '2';
				else this->board[i] = '1';

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
	
	buffer << this->board;
	string final(buffer.str());
	return(final);
}


void Board::NextTurn(void)
{
	if(Turn==2){
	Turn=1;
	}
	else{
	Turn=2;
	}
}

int Board::GetTurn()
{
	return(Turn);
}

void Board::SetTurn(int color)
{
	if(color==1 || color==2)
	Turn=color;
}





//operaçoes para verificar ganhador
char Oponente(char avaliando)
{
	if(avaliando=='1')
		return('2');
	else
		return('1');
}



char Board::horizontal()
{

	char resultados[18];
	
		resultados[0]=AvaliaHorizontal(0,1);
		resultados[1]=AvaliaHorizontal(5,1);
		resultados[2]=AvaliaHorizontal(11,1);
		resultados[3]=AvaliaHorizontal(18,1);
		resultados[4]=AvaliaHorizontal(26,1);
		resultados[5]=AvaliaHorizontal(35,1);
		resultados[6]=AvaliaHorizontal(43,1);
		resultados[7]=AvaliaHorizontal(50,1);
		resultados[8]=AvaliaHorizontal(56,1);
	
	
		resultados[9]=AvaliaHorizontal(0,2);
		resultados[10]=AvaliaHorizontal(5,2);
		resultados[11]=AvaliaHorizontal(11,2);
		resultados[12]=AvaliaHorizontal(18,2);
		resultados[13]=AvaliaHorizontal(26,2);
		resultados[14]=AvaliaHorizontal(35,2);
		resultados[15]=AvaliaHorizontal(43,2);
		resultados[16]=AvaliaHorizontal(50,2);
		resultados[17]=AvaliaHorizontal(56,2);
	

	for(int i=0;i<18;i++)
	{
		if(resultados[i]!='0')
			return(resultados[i]);
	}
	return('0');
	
}

char Board::AvaliaHorizontal(int posIni, int avaliar)
{

	char buffer[10];
	_itoa_s (avaliar,buffer,10);//coloca o int avaliar em um array
	char avaliando=buffer[0];
	int posFin;

	//definições feitas olhando o tabuleiro
	
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
		if(this->board[i]==avaliando && this->board[i+1]==avaliando && this->board[i+2]==avaliando)
		{
			if(i!=posFin && this->board[i+3]==avaliando)//ganhou
				return(avaliando);
			else//oponente ganhou
				return(Oponente(avaliando));
		}
		else{}	//nothing
		
	}

	return('0');
}



char Board::diagonal1() //   
{
	char resultados[18];
		//"/"
		resultados[0]=AvaliaDiagonal(0,1);
		resultados[1]=AvaliaDiagonal(1,1);
		resultados[2]=AvaliaDiagonal(2,1);
		resultados[3]=AvaliaDiagonal(3,1);
		resultados[4]=AvaliaDiagonal(4,1);
		resultados[5]=AvaliaDiagonal(10,1);
		resultados[6]=AvaliaDiagonal(17,1);
		resultados[7]=AvaliaDiagonal(25,1);
		resultados[8]=AvaliaDiagonal(34,1);
	
	
		resultados[9]=AvaliaDiagonal(0,2);
		resultados[10]=AvaliaDiagonal(1,2);
		resultados[11]=AvaliaDiagonal(2,2);
		resultados[12]=AvaliaDiagonal(3,2);
		resultados[13]=AvaliaDiagonal(4,2);
		resultados[14]=AvaliaDiagonal(10,2);
		resultados[15]=AvaliaDiagonal(17,2);
		resultados[16]=AvaliaDiagonal(25,2);
		resultados[17]=AvaliaDiagonal(34,2);
	

	int resultados2[18];//"\"
	
		resultados2[0]=AvaliaDiagonal2(4,1);
		resultados2[1]=AvaliaDiagonal2(3,1);
		resultados2[2]=AvaliaDiagonal2(2,1);
		resultados2[3]=AvaliaDiagonal2(1,1);
		resultados2[4]=AvaliaDiagonal2(0,1);
		resultados2[5]=AvaliaDiagonal2(5,1);
		resultados2[6]=AvaliaDiagonal2(11,1);
		resultados2[7]=AvaliaDiagonal2(18,1);
		resultados2[8]=AvaliaDiagonal2(26,1);
	
		resultados2[9]=AvaliaDiagonal2(4,2);
		resultados2[10]=AvaliaDiagonal2(3,2);
		resultados2[11]=AvaliaDiagonal2(2,2);
		resultados2[12]=AvaliaDiagonal2(1,2);
		resultados2[13]=AvaliaDiagonal2(0,2);
		resultados2[14]=AvaliaDiagonal2(5,2);
		resultados2[15]=AvaliaDiagonal2(11,2);
		resultados2[16]=AvaliaDiagonal2(18,2);
		resultados2[17]=AvaliaDiagonal2(26,2);
	

	for(int i=0;i<18;i++)
	{
		if(resultados[i]!='0')
			return(resultados[i]);
	}
	
	
	for(int i=0;i<18;i++)
	{
		if(resultados2[i]!='0')
			return(resultados2[i]);
	}
			
	return('0');
}




char Board::AvaliaDiagonal(int posIni, int avaliar) //    "/"
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
	
	if(posIni==0){ posFin=26;primeiroPulo=0;fimInt=2;}
	else if(posIni==1){ posFin=35;primeiroPulo=0;fimInt=3;}
	else if(posIni==2){ posFin=43;primeiroPulo=0;fimInt=4;}
	else if(posIni==3){ posFin=50;primeiroPulo=0;fimInt=5;}
	else if(posIni==4){ posFin=56;primeiroPulo=0;fimInt=6;}
	else if(posIni==10){ posFin=57;primeiroPulo=1;fimInt=6;}
	else if(posIni==17){ posFin=58;primeiroPulo=2;fimInt=6;}
	else if(posIni==25){ posFin=59;primeiroPulo=3;fimInt=6;}
	else if(posIni==34){ posFin=60;primeiroPulo=4;fimInt=6;}
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
					return(Oponente(avaliando));
			}
			else{}//nothing
		posIni=posIni+listaPulo[i];			

		
		
	}
	return('0');


}

char Board::AvaliaDiagonal2(int posIni, int avaliar) //    "\"
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
	
	if(posIni==4){ posFin=34;primeiroPulo=1;fimInt=3;}
	else if(posIni==3){ posFin=42;primeiroPulo=1;fimInt=4;}
	else if(posIni==2){ posFin=49;primeiroPulo=1;fimInt=5;}
	else if(posIni==1){ posFin=55;primeiroPulo=1;fimInt=6;}
	else if(posIni==0){ posFin=60;primeiroPulo=1;fimInt=6;}
	else if(posIni==5){ posFin=59;primeiroPulo=2;fimInt=6;}
	else if(posIni==11){ posFin=58;primeiroPulo=3;fimInt=7;}
	else if(posIni==18){ posFin=57;primeiroPulo=4;fimInt=7;}
	else if(posIni==26){ posFin=56;primeiroPulo=5;fimInt=6;}
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
					return(Oponente(avaliando));
			}
			else{}//nothing
		posIni=posIni+listaPulo[i];			

		
		
	}
	return('0');


}
	