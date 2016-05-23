#include <iostream>
#include "tictactoe.h"

using namespace std;

int main() {
	int choice;
	tictactoe board;
	board.display();
	cout << "\nWould you like to restart?\n(1)Yes\n(2)No\n";
	cin >> choice;
	if (choice == 1) {
		board.restart();
	}
	else {
		exit(0);
	}

}