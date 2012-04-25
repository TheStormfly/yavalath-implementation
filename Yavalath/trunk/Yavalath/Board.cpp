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
	this->hexagonVector.push_back(new Hexagon(37, 242));
	this->hexagonVector.push_back(new Hexagon(97, 242));
	this->hexagonVector.push_back(new Hexagon(157, 242));
	this->hexagonVector.push_back(new Hexagon(217, 242));
	this->hexagonVector.push_back(new Hexagon(277, 242));
	this->hexagonVector.push_back(new Hexagon(337, 242));
	this->hexagonVector.push_back(new Hexagon(397, 242));
	this->hexagonVector.push_back(new Hexagon(457, 242));
	this->hexagonVector.push_back(new Hexagon(517, 242));
	//
	this->hexagonVector.push_back(new Hexagon(67, 293));
	this->hexagonVector.push_back(new Hexagon(127, 293));
	this->hexagonVector.push_back(new Hexagon(187, 293));
	this->hexagonVector.push_back(new Hexagon(247, 293));
	this->hexagonVector.push_back(new Hexagon(307, 293));
	this->hexagonVector.push_back(new Hexagon(367, 293));
	this->hexagonVector.push_back(new Hexagon(427, 293));
	this->hexagonVector.push_back(new Hexagon(487, 293));
	//
	this->hexagonVector.push_back(new Hexagon(97, 344));
	this->hexagonVector.push_back(new Hexagon(157, 344));
	this->hexagonVector.push_back(new Hexagon(217, 344));
	this->hexagonVector.push_back(new Hexagon(277, 344));
	this->hexagonVector.push_back(new Hexagon(337, 344));
	this->hexagonVector.push_back(new Hexagon(397, 344));
	this->hexagonVector.push_back(new Hexagon(457, 344));
	//
	this->hexagonVector.push_back(new Hexagon(127, 395));
	this->hexagonVector.push_back(new Hexagon(187, 395));
	this->hexagonVector.push_back(new Hexagon(247, 395));
	this->hexagonVector.push_back(new Hexagon(307, 395));
	this->hexagonVector.push_back(new Hexagon(367, 395));
	this->hexagonVector.push_back(new Hexagon(427, 395));
	//
	this->hexagonVector.push_back(new Hexagon(157, 446));
	this->hexagonVector.push_back(new Hexagon(217, 446));
	this->hexagonVector.push_back(new Hexagon(277, 446));
	this->hexagonVector.push_back(new Hexagon(337, 446));
	this->hexagonVector.push_back(new Hexagon(397, 446));


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