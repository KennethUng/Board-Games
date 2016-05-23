#ifndef TICTACTOE_H
#define TICTACTOE_H

class tictactoe {
private:
	char** gameBoard;
	bool gameOver;
public:
	tictactoe();
	void display();
	void place(char,int, int);
};
#endif