#include "tictactoe.h"
#include <iostream>

using namespace std;

tictactoe::tictactoe() {
	gameBoard = new char*[3];

	for (int i = 0; i < 3; i++) {

		*(gameBoard + i) = new char[3];

	}
}
/*This function displays the tictactoe board*/
void tictactoe::display() {
	cout << "-------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			cout << *(*(gameBoard + i) + j) << " | ";
		}
		cout << endl;
		cout << "-------------" << endl;
	}
}
void tictactoe::place(char player,int row, int column) {
	if (*(*(gameBoard + row) + column) != 'X' && *(*(gameBoard + row) + column) != 'O') {
		*(*(gameBoard + row) + column) = player;
	}
	else {
		int choice1, choice2;
		cout << "\nNot a valid location, try again.";
		cout << "\nRow:";
		cin >> choice1;
		cout << "\nColumn:";
		cin >> choice2;
		place(player, choice1, choice2);
	}
	display();
}
void tictactoe::restart() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(gameBoard + i) + j) = ' ';
		}
	}
	display();
}
bool tictactoe::endGame() {

}