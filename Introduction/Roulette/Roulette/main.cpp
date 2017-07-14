#include <iostream>
#include <string>
#include "windows.h"			// inculdes Sleep function
using namespace std;

//	Requests input until an integer is inserted which then is returned
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

int main() {

	// Initialization
		// Odd numbers are red and even numbers are black
	const int RED = -101;
	const int BLACK = -102;
	const int STARTINGBALANCE = 1000;
	const int NUMBERMULT = 10;
	const int COLOURMULT = 2;
	
	int balance = STARTINGBALANCE;				// The courrent amount of money
	int stake;									// The amount of money which is invested
	int winningNum;								// The number which the roulette ball lands on.
	int winningColour;							// The colour which the roulette ball lands on
	int guess;									// The number or colour that the player betted on
	int tempNum;								// Used to handle input
	bool gameWon = true;						// If player won the game
	bool gameOver = false;						// If the game is over (Choosen or forced)
	string input;								// Input from the player will be sent here

	// Welcome to the casino
	cout << "Welcome to the Casino. You will start with a plesent gift of " << STARTINGBALANCE << " Wacky money. Todays game is ROULETTE!!!! \a" << endl;
	
	// Game loop starts
	do {
		// Handling of input to stake
		do {
			while (true) {
				cout << "How much do you want to bet? \n1. 100 \n2. 300 \n3. 500 \nYou choose: ";
				cin >> input;
				tempNum = inputHandler(input);
				if (1 <= tempNum && tempNum <= 3) break;
				cout << "Please select a value within the range!\n";
			}
			// Stake will be assigned a value based on the input.
			switch (tempNum)
			{
			case 1:
				stake = 100;
				break;
			case 2:
				stake = 300;
				break;
			case 3:
				stake = 500;
				break;
			}
			if (stake > balance) cout << "Please select something you can afford.\n";
		} while (stake > balance);
		cout << "You have betted " << stake << ".\n\n";

		//Handling input to decide if player will bet on colour or number
		while (true) {
			cout << "Do you want to bet on colour or a number?\n"
				<< "1. Colour \n2. Number\n"
				<< "We will multiply you bet by " << NUMBERMULT << " for a winning number and " << COLOURMULT << " for a colour.\n";
			cin >> input;
			tempNum = inputHandler(input);
			if (1 <= tempNum && tempNum <= 2) break;
			cout << "Please select a value within the range!\n";
		}
		// Guess is assiged a value based on the input. guess =(1, ..., 36, RED, BLACK)
		switch (tempNum)
		{
		case 1:						// Player bets on colour
			while (true) {
				//Handling input to guess
				cout << "Then we will go with colour. But is it going to be red or black?\n1.Red\n2.Black\n";
				cin >> input;
				tempNum = inputHandler(input);
				if (1 <= tempNum && tempNum <= 2) break;
				cout << "Please select a value within the range!\n";
			}
			// guess is assigned black or red
			switch (tempNum)
			{
			case 1:
				guess = RED;
				break;
			case 2:
				guess = BLACK;
				break;
			}
			tempNum = 1;	// Reset tempNum to its value in the outer switch.
			break;
		case 2:			// Player betts on a number
			while (true) {
				//Handling input to guess
				cout << "Let's go with a number. Pick a number between 1 and 36: ";
				cin >> input;
				tempNum = inputHandler(input);
				if (1 <= tempNum && tempNum <= 36) break;
				cout << "Please select a value within the range!\n";
			}
			// Guess is assigned a value based on input
			guess = tempNum;
			tempNum = 2;
			break;
		}

		// Tell player what they betted on
		cout << "Then we will go with ";
		if (guess == RED) cout << "Red!!!\n\n";
		else if (guess == BLACK) cout << "Black!!!!\n\n";
		else cout << guess << "!!!!\n\n";
		cout << "Let's spin that wheel!!!!!";
		Sleep(2000);

		//Create the winning number and the colour of which
		winningNum = rand() % 36 + 1;
		winningColour = (winningNum % 2 == 0) ? BLACK : RED;
		cout << "THE WINNING NUMBER IS " << ((winningColour == BLACK) ? "BLACK " : "RED ") << winningNum << "\n\n";

		// Check if the player won
		if (guess == ((guess > 0) ? winningNum : winningColour)) gameWon = true;
		else gameWon = false;

		// Adjust the value of balance and gameWon
		if (guess > 0) {		// If player betted on number
			if (guess == winningNum) {
				gameWon = true;
				balance += NUMBERMULT*stake;
			}
			else {
				gameWon = false;
				balance -= stake;
			}
		}
		else {					// If player betted on colour
			if (guess == winningColour) {
				gameWon = true;
				balance += COLOURMULT*stake;
			}
			else {
				gameWon = false;
				balance -= stake;
			}
		}

		//Give the player the results
		if (gameWon) {
			cout << "OMG you won!!!! You won " << ((guess > 0) ? NUMBERMULT*stake : COLOURMULT*stake) << ". I meen congratulations sir...\n";
		}
		else {
			cout << "LOL You lost " << stake << "\n";
		}
		cout << "This brings you balance to " << balance << "\n";

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

	}  while (!gameOver); // End of gameOver loop

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