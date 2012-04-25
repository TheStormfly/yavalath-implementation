#pragma once
#include "stdafx.h"

Hexagon::Hexagon(int x, int y)
{
	this->centerPoint.X = x;
	this->centerPoint.Y = y;

	InitializeVertexs();
}

Hexagon::~Hexagon()
{
}

void Hexagon::InitializeVertexs()
{
#define l 34
#define d 30

	vertex[0].X = centerPoint.X;
	vertex[0].Y = centerPoint.Y - l;
	
	vertex[1].X = centerPoint.X + d;
	vertex[1].Y = centerPoint.Y - l/2;

	vertex[2].X = centerPoint.X + d;
	vertex[2].Y = centerPoint.Y + l/2;

	vertex[3].X = centerPoint.X;
	vertex[3].Y = centerPoint.Y + l;
	
	vertex[4].X = centerPoint.X - d;
	vertex[4].Y = centerPoint.Y + l/2;
	
	vertex[5].X = centerPoint.X - d;
	vertex[5].Y = centerPoint.Y - l/2;
}

bool Hexagon::isInsideHexagon(int x, int y)
{
	if ( x >= centerPoint.X )
	{
		if( x <= vertex[1].X )
		{
			if(y <= centerPoint.Y)
			{
				if(testaDiagonal(x, y, 0, 1))
					return true;
				else
					return false;
			}
			else
			{
				if(testaDiagonal(x, y, 2, 3))
					return true;
				else
					return false;
			}
		}
		else
			return false;
	}
	else
	{
		if( x >= vertex[5].X )
		{
			if(y <= centerPoint.Y)
			{
				if(testaDiagonal(x, y, 5, 0))
					return true;
				else
					return false;
			}
			else
			{
				if(testaDiagonal(x, y, 3, 4))
					return true;
				else
					return false;
			}
		}
		else
			return false;
	}
}

bool Hexagon::testaDiagonal(int x, int y, int v1, int v2)
{
	return ( ((vertex[v2].X - vertex[v1].X) * (y - vertex[v2].Y) - (x - vertex[v2].X) * (vertex[v2].Y - vertex[v1].Y)) >=0 ) ? true : false;
}