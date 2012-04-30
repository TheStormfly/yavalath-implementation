#pragma once

class Board
{
	private:
		int Turn;
		vector<Hexagon*> hexagonVector;
		

	public:
		structBoard board;
		Ponto Board::returnHexPonto(short int bestMove);
		void Initialize();
		Board(void);
		~Board(void);
		
		bool EmptyPosition(int pos);
		string Board::PrintBoard();
		char Board::IsGameOver(unsigned char board[]);//o para ninguem ganho 1 para brancas 2 para pretas
		bool newgame;
		bool hexagonoClicadoEhValido(int x, int y, Ponto *p, short int ourColor);
		char Board::AvaliaHorizontal(int posIni, int avaliar, unsigned char board[]);
		char Board::AvaliaDiagonal1(int posIni, int avaliar, unsigned char board[]);
		char Board::AvaliaDiagonal2(int posIni, int avaliar, unsigned char board[]);
		char Board::AvaliaGame(int posIni, int avaliar, unsigned char board[]);
};