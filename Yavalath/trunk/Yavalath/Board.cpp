#include "stdafx.h"
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
	for(int i=0; i<61;i++)
		board[i]=0;

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
			if(this->GetTurn()==2) //se o turno é das pretas
				this->board[i] = 2;
			else this->board[i] = 1;

			*p = hexagonVector[i]->getCenter();
			return true;
		}
	}

	return false;
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

bool Board::EmptyPosition(int pos)
{
	if(pos<=61 && pos>=0)//se ta na posição valida
	{
		if(board[pos]=0)//se ta vazio
			return(true);
	}
	return(false);
}