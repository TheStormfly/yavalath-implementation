#pragma once

class Board
{
	private:
		int Turn;
		vector<Hexagon*> hexagonVector;
		structBoard board;

	public:
		void Initialize();
		Board(void);
		~Board(void);
		int Board::GetTurn();
		void Board::NextTurn();
		void Board::SetTurn(int color);
		bool EmptyPosition(int pos);
		string Board::PrintBoard();
		char Board::horizontal();//o para ninguem ganho 1 para brancas 2 para pretas
		char Board::diagonal1();
		char Board::AvaliaDiagonal(int posIni, int avaliar);
		bool newgame;
		bool hexagonoClicadoEhValido(int x, int y, Ponto *p);
		char Board::AvaliaHorizontal(int posIni, int avaliar);
		char Board::AvaliaDiagonal1(int posIni, int avaliar);
		char Board::AvaliaDiagonal2(int posIni, int avaliar);
};