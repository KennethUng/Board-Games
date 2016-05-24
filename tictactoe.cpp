#include "tictactoe.h"
#include <iostream>

using namespace std;
const char tictactoe::player1 = 'X';
const char tictactoe::player2 = 'O';
tictactoe::tictactoe() {
	gameBoard = new char*[3];

	for (int i = 0; i < 3; i++) {

		*(gameBoard + i) = new char[3];

	}
	gameOver = false;
	restart();
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
void tictactoe::place(int row, int column) {
	if (counter % 2 == 0) {
		if (row < 3 && column < 3 && *(*(gameBoard + row) + column) != 'X' && *(*(gameBoard + row) + column) != 'O') {
			*(*(gameBoard + row) + column) = player1;
			display();
			counter++;
			check(row, column);
		}
		else {
			int choice1, choice2;
			cout << "\nNot a valid location, try again.";
			cout << "\nRow:";
			cin >> choice1;
			cout << "\nColumn:";
			cin >> choice2;
			place(choice1, choice2);
		}
	}
	else if (counter % 2 != 0){
		if (row < 3 && column < 3 && *(*(gameBoard + row) + column) != 'X' && *(*(gameBoard + row) + column) != 'O') {
			*(*(gameBoard + row) + column) = player2;
			display();
			counter++;
			check(row, column);
		}
		else {
			int choice1, choice2;
			cout << "\nNot a valid location, try again.";
			cout << "\nRow:";
			cin >> choice1;
			cout << "\nColumn:";
			cin >> choice2;
			place(choice1, choice2);
		}
	}
}
void tictactoe::restart() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(gameBoard + i) + j) = ' ';
		}
	}
	gameOver = false;
	display();
}
bool tictactoe::isGameOver() {
	return gameOver;
}
int tictactoe::getTurn() {
	return counter;
}
bool tictactoe::checkRow(int x) {
	char check = *(*(gameBoard + x) + 0);
	for (int i = 0; i < 3; i++) {
		if (*(*(gameBoard + x) + i) == ' ' || *(*(gameBoard + x)+ i) != check) {
			return false;
		}
	}
	winner = check;
	return true;
}
bool tictactoe::checkColumn(int y) {
	char check = *(*(gameBoard + 0) + y);
	for (int i = 0; i < 3; i++) {
		if (*(*(gameBoard + y) + i) == ' ' || *(*(gameBoard + y) + i) != check) {
			return false;
		}
	}
	winner = check;
	return true;
}
bool tictactoe::checkDiagonal(int diagonal) {
	char check = *(*(gameBoard + 0) + diagonal);
	if (diagonal == 0) {
		int x = 0;
		for (int i = diagonal; i < 3; i++) {
			if (*(*(gameBoard + i) + x) == ' ' || *(*(gameBoard + i) + x) != check) {
				return false;
			}
			x++;
		}
		winner = check;
		return true;
	}
	else {
		int x = 0;
		for (int i = diagonal; i > 0; i--) {
			if (*(*(gameBoard + x) + i) == ' ' || *(*(gameBoard + x) + i) != check) {
				return false;
			}
			x++;
		}
		winner = check;
		return true;
	}
}
bool tictactoe::checkDraw() {
	if (counter > 9) {
		return true;
	}
	else {
		return false;
	}
}
void tictactoe::check(int x,int y) {
	if (checkRow(y))
		gameOver = true;
	if (checkColumn(x))
		gameOver = true;
	if (checkDiagonal(0))
		gameOver = true;
	if (checkDiagonal(2))
		gameOver = true;
	if (checkDraw())
		gameOver = true;
	whoWon();
}
void tictactoe::whoWon() {
	if (winner != player1 && winner != player2 && counter == 10) {
		cout << "Draw!";
	}
	else if (winner == player1) {
		cout << "Player 1 won !";
	}
	else if(winner == player2){
		cout << "Player 2 won !";
	}
	if (gameOver) {
		int choice;
		cout << "\nDo you want to Restart?\n(1)Yes\n(2)No";
		cin >> choice;
		if (choice == 1) {
			restart();
		}
	}
}
