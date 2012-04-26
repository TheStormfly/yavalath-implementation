#pragma once

class Board
{
	private:
		int Turn;
		vector<Hexagon*> hexagonVector;
		unsigned char board[61];
		void Initialize();

	public:
		Board(void);
		~Board(void);
		int GetTurn();
		void NextTurn();
		void Board::SetTurn(int color);

		bool hexagonoClicadoEhValido(int x, int y, Ponto *p);
};