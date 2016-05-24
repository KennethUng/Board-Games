#ifndef TICTACTOE_H
#define TICTACTOE_H

class tictactoe {
private:
	int counter;
	char winner;
	static const char player1, player2;
	char** gameBoard;
	bool gameOver;
	bool checkRow(int);
	bool checkColumn(int);
	bool checkDiagonal(int);
	bool checkDraw();
	void check(int, int);
	void whoWon();
public:
	void restart();
	bool isGameOver();
	tictactoe();
	void display();
	void place(int, int);
	int getTurn();
};
#endif