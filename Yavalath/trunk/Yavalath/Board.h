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
		int Board::GetTurn();
		void Board::NextTurn();
		void Board::SetTurn(int color);
		bool EmptyPosition(int pos);


		bool hexagonoClicadoEhValido(int x, int y, Ponto *p);
};