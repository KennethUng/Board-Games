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
	winner = ' ';
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
/*Puts the users input onto the board*/
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
/*Responsible for restarting the game.*/
void tictactoe::restart() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(gameBoard + i) + j) = ' ';
		}
	}
	winner = ' ';
	gameOver = false;
	counter = 0;
	display();
}
/*Checks if the game is over*/
bool tictactoe::isGameOver() {
	return gameOver;
}
/*Gets the counter*/
int tictactoe::getTurn() {
	return counter;
}
/*Checks to see if anyone won horizontally*/
bool tictactoe::checkRow(int x) {
	/*Check = [row][0] <-- Should go through 0-2*/
	char check = *(*(gameBoard + x) + 0);
	for (int i = 0; i < 3; i++) {
		if (*(*(gameBoard + x) + i) == ' ' || *(*(gameBoard + x)+ i) != check) {
			return false;
		}
	}
	/*If the above doesn't return false, we know it's true and the winner will be equal to whoever check was on.*/
//	cout << "Row";
	winner = check;
	return true;
}
/*Checks to see if anyone won vertically*/
bool tictactoe::checkColumn(int y) {
	/*Should equal to [0][column] from 0-2*/
	char check = *(*(gameBoard + 0) + y);
	for (int i = 0; i < 3; i++) {
		if (*(*(gameBoard + i) + y) == ' ' || *(*(gameBoard + i) + y) != check) {
			return false;
		}
	}
//	cout << "Column";
	winner = check;
	return true;
}
/*Checking if anyone won diagonally*/
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
//		cout << "Right";
		winner = check;
		return true;
	}
	else {
		int x = 0;
		for (int i = diagonal; i >= 0; i--) {
			if (*(*(gameBoard + x) + i) == ' ' || *(*(gameBoard + x) + i) != check) {
				return false;
			}
			x++;
		}
//		cout << "Left";
		winner = check;
		return true;
	}
}
/*Checking for a Draw*/
bool tictactoe::checkDraw() {
	if (counter == 9) {
//		cout << counter << "<--Current Counter\n";
		return true;
	}
	else {
//		cout << counter << "<--Current Counter\n";
		return false;
	}
}
/*Checks to see if the game is over*/
void tictactoe::check(int x,int y) {
	if (checkRow(x))
		gameOver = true;
	if (checkColumn(y))
		gameOver = true;
	if (checkDiagonal(0))
		gameOver = true;
	if (checkDiagonal(2))
		gameOver = true;
	if (checkDraw())
		gameOver = true;
	whoWon();
}
/*Checks to see who's the winner if any*/
void tictactoe::whoWon() {
	if (winner != player1 && winner != player2) {
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
