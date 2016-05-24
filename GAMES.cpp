#include <iostream>
#include "tictactoe.h"

using namespace std;

int main() {
	int row,column;
	tictactoe board;
	while (!board.isGameOver()) {
		cout << "Player 1: X, Player 2: O";
		if (board.getTurn() % 2 == 0) {
			cout << "\nPlayer 1";
			cout << "\nRow: ";
			cin >> row;
			cout << "\nColumn: ";
			cin >> column;
			board.place(row, column);
		}
		else {
			cout << "\nPlayer 2";
			cout << "\nRow: ";
			cin >> row;
			cout << "\nColumn: ";
			cin >> column;
			board.place(row, column);
		}
	}

}