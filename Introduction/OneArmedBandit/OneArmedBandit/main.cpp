#include <iostream>
#include <string>
using namespace std;

const int ROW = 3;
const int COLUMN = 3;
const int RANGE = 3;

int inputHandler(string str);
void printArray(int a[ROW][COLUMN]);
void setArray(int(&a)[ROW][COLUMN]);
int numberOfWins(int board[ROW][COLUMN]);

int main() {

	const int NUMSIGN = 3;
	const int MAXROW = ROW * 2 + 2;


	int balance;
	int stake;
	int wins;
	int tempNum;

	int factors[MAXROW];
	int board[ROW][COLUMN];

	bool gameOver = false;

	string input;

	//Initialize factors
	for (int i = 0; i < MAXROW; i++) {
		factors[i] = 1;
	}
	factors[0] = -1;
	factors[1] = 1;
	factors[2] = 3;
	factors[3] = 7;
	factors[4] = 15;
	factors[8] = 127;

	cout << "Hello my friend! Welcome back, we have missed you.\n"
		<< "Today we will play One-Armed-Bandit!\nMay the odds be ever in your favour.\n";

	// Asks the user to enter there starting balance and assignes it to balance.
	while (true) {
		cout << "How much do you want to put in? We don't allow any more then 1000, and we only accept Astrids: ";
		cin >> input;
		balance = inputHandler(input);
		if (0 < balance && balance <= 1000 && (balance % 20 == 0)) break;
		cout << "Please select an appropriate value!\n";
	}

	do {
		// Asks the player to place a bet and assignes it to stake
		while (true) {
			cout << "How much do you want to bet? Everything from 1-50 kr is ok:  ";
			cin >> input;
			stake = inputHandler(input);
			if (1 <= stake && stake <= 50 && stake <= balance) break;
			cout << "Please select an appropriate value!\n";
		}

		//Start the game and colculate all the scores

		setArray(board);
		printArray(board);
		wins = numberOfWins(board);
		balance += factors[wins] * stake;

		// Give the player the results
		if (wins != 0) {
			cout << "Congrtulations, you got " << wins << " you won " << factors[wins] * stake << ". ";
		}
		else {
			cout << "Sorry you didn't get any rows. You lost " << stake << ". ";
		}
		cout << "This brings your balance to " << balance << ".\n";

		//Check if player has positive balance and wants/can play again
		if (balance <= 0) {
			gameOver = true;		// Player is forced to quit
		}
		else {
			while (true) {
				// Handling input to gameOver
				cout << "Do you want to play again?\n1. Yes\n2. No\n: ";
				cin >> input;
				tempNum = inputHandler(input);
				if (1 <= tempNum && tempNum <= 2) break;
				cout << "Please select a value within the range!\n";
			}

			// gameOver is assigned a value based on the input
			switch (tempNum)
			{
			case 1:
				gameOver = false;
				break;
			case 2:
				gameOver = true;
				break;
			} // End of switch
		} //End of if

	} while (! gameOver);

	//Casino saying godbye
	if (balance > 0) {
		cout << "So sorry to see you leaving, but well played.\nYou will be walking home with " << balance << ". That is not ashame\n";
	}
	else {
		cout << "Get out of here you know body and come back when you have money you rat!\n";
	}


	cin.ignore();
	cin.get();
	return 0;
}

int inputHandler(string str) {
	int i;
	while (true) {
		try
		{
			i = stoi(str);
			break;
		}
		catch (const std::exception&)
		{
			cout << "YOU PLUGED IN THE WRONG CARACHTER YOU MORON! \nPleas try again: ";
			cin >> str;
		}
	}
	return i;
}

void setArray(int (&a)[ROW][COLUMN]) {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COLUMN; col++) {
			a[row][col] = rand() % RANGE + 1;
		}
		cout << endl;
	}
}

void printArray(int a[ROW][COLUMN]) {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COLUMN; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
}

int numberOfWins(int board[ROW][COLUMN]) {
	int numberOfWins = 0;	 // Keeps track of how many winning rows have already been counted
	int tempCount = 0;		 // Keeps track of how many cells is equal to the first one in that row.

	// Check if there are wins in each row
	for (int row = 0; row < ROW; row++) {
		tempCount = 1;
		for (int col = 1; col < COLUMN; col++) {
			if (board[row][0] == board[row][col]) tempCount++;
		}	
		if (tempCount == COLUMN) numberOfWins++;
	}

	// Check if there are wins in each column
	for (int col = 0; col < COLUMN; col++) {
		tempCount = 1;
		for (int row = 1; row < ROW; row++) {
			if (board[0][col] == board[row][col]) tempCount++;
		}
		if (tempCount == ROW) numberOfWins++;
	}

	// Check diagonal from top-left to bot-right
	tempCount = 1;
	for (int d = 1; d < ROW; d++) {
		if (board[0][0] == board[d][d]) tempCount++;
	}
	if (tempCount == ROW) numberOfWins++;

	// Check diagonal from bot-right to top-left
	tempCount = 1;
	for (int d = 1; d < ROW; d++) {
		if (board[ROW-1][0] == board[ROW-1-d][d]) tempCount++;
	}
	if (tempCount == ROW) numberOfWins++;

	return numberOfWins;
}
