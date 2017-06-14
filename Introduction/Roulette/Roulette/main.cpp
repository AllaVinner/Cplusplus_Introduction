#include <iostream>
using namespace std;

int main() {

	// Initialization
		// Odd is red and even numbers are black
		const bool red = false;
		const bool black = true;
		const int startingBalance = 1000;

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
		cout << "How much do you want to bet? \n 1. 100 \n 2. 300 \n 3. 500 \n You choose: ";
		cin >> guess;

}	// end main