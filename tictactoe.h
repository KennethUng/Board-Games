#ifndef TICTACTOE_H
#define TICTACTOE_H

class tictactoe {
private:
	char** gameBoard;
	bool gameOver;
public:
	void restart();
	bool endGame();
	tictactoe();
	void display();
	void place(char,int, int);
};
#endif