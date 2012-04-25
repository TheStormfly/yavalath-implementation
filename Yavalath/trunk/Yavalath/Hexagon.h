#pragma once

typedef struct{
	int X;
	int Y;
}Ponto;

class Hexagon
{
	private:
		Ponto centerPoint;
		Ponto vertex[6];
		
		void InitializeVertexs();
		bool testaDiagonal(int x, int y, int v1, int v2);

	public:
		Hexagon(int x, int y);
		~Hexagon();

		Ponto getCenter() { return centerPoint; }
		bool isInsideHexagon(int x, int y);
};