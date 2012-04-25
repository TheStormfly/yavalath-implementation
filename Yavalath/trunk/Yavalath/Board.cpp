#include "stdafx.h"

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

	this->hexagonVector.push_back(new Hexagon(157, 38));
	//this->hexagonVector.push_back(new Hexagon(6125, 222));
}

bool Board::hexagonoClicadoEhValido(int x, int y, Ponto *p)
{
	for(int i=0; i<61; i++)
	{
		if(this->hexagonVector[i]->isInsideHexagon(x, y))
		{
			*p = hexagonVector[i]->getCenter();
			return true;
		}
	}

	return false;
}