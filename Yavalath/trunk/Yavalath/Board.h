#pragma once

class Board
{
	private:
		vector<Hexagon*> hexagonVector;
		unsigned char board[61];
		void Initialize();

	public:
		Board(void);
		~Board(void);

		bool hexagonoClicadoEhValido(int x, int y, Ponto *p);
};