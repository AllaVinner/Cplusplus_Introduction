#include <iostream>
using namespace std;

int main() {

	// Initialization
		// Odd is red and even numbers are black
		const bool red = false;
		const bool black = true;
		const int startingBalance = 1000;
		const int numberMult = 10;
		const int colourMult = 2;

		int balance = startingBalance;				// The starting balnce is to be 1000 money
		int stake;
		int winningNum;
		int guess;
		bool colour;
		bool gamOver = false;

	// Welcome to the casino
		cout << "Welcome to the wacky tacky macky Casino. You will start with a plesent gift of " << startingBalance
			<< "Wacky money. Todays game is .... ROULETTE!!!! \a" << endl;
		
	// Stake this will be the loop
		cout << "How much do you want to bet? \n1. 100 \n2. 300 \n3. 500 \nYou choose: ";
		cin >> guess;
		cout << "Well " << guess << " money it is :) \n Do you want to bet on colour or a number? \n"
			 << "1. Colour \n2. Number"
			 << "The multiplication thing is " << numberMult << " for numbers and " << colourMult << " for colours.\n";


	
		cin.ignore();
		cin.get();
}	// end main