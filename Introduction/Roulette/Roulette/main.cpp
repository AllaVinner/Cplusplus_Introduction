#include <iostream>
#include <string>
using namespace std;

/* Takes in a string and try if it it is possible to convert it into an integer.
   If "yes" the function returns that integer as an integer.
   If "No" it will ask for a new input which is assiged to str. Then it repites
   */
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
		// Odd is red and even numbers are black
		const int red = -404;		//Vad ä bäst bool här?
		const int black = -405;
		const int number = 1;
		const int colour = 2;
		const int startingBalance = 1000;
		const int numberMult = 10;
		const int colourMult = 2;
		
		int balance = startingBalance;				// The starting balnce is to be 1000 money
		int stake;
		int winningNum;
		int guess;
		int tempNum;
		bool gamOver = false;

		
		string input;
		
	// Welcome to the casino
		cout << "Welcome to the wacky tacky macky Casino. You will start with a plesent gift of " << startingBalance << "Wacky money. Todays game is .... ROULETTE!!!! \a" << endl;

	// Stake this will be the loop
		while (true) {
			cout << "How much do you want to bet? \n1. 100 \n2. 300 \n3. 500 \nYou choose: ";
			cin >> input;
			tempNum = inputHandler(input);
			if (1 <= tempNum && tempNum <= 3) break;
			cout << "Please select a value within the range!\n";
		}
		switch (tempNum)
		{
		case 1 : 
			stake = 100;
			break;
		case 2 : 
			stake = 300;
			break;
		case 3 :
			stake = 500;
			break;
		}
		cout << "Well " << stake << " money it is :) \n";

	// What will we play with numbee or colour
		while (true) {
			cout << "Do you want to bet on colour or a number?\n"
				<< "1. Colour \n2. Number\n"
				<< "The multiplication thing is " << numberMult << " for numbers and " << colourMult << " for colours.\n";
			cin >> input;
			tempNum = inputHandler(input);
			if (1 <= tempNum && tempNum <= 2) break;
			cout << "Please select a value within the range!\n";
		}

		switch (tempNum)
		{
		case 1:
			while (true) {
				cout << "OKEY... so do you want to bet on red or black?\n1.Red\n2.Black\n";
				cin >> input;
				tempNum = inputHandler(input);
				if (1 <= tempNum && tempNum <= 2) break;
				cout << "Please select a value within the range!\n";
			}
			switch (tempNum)
			{
			case 1 :
				guess = red;
			case 2:
				guess = black;
				break;
			}
			tempNum = 1;	// Reset tempNum to its value in the outher switch.  Was this a good idea?
			break;
		case 2:		
			while(true) {
				cout << "OKEY... so bet on a number between 1 and 36";
				cin >> input;
				tempNum = inputHandler(input);
				if (1 <= tempNum && tempNum <= 36) break;
				cout << "Please select a value within the range!\n";
			}
			guess = tempNum;
			tempNum = 2;
			break;
		}
		if (guess == red) cout << "Then we will go with red!!!!!\n";
		else if (guess == black) cout << "Then we will go with Black!!!!\n";
		else cout << "Then we will go with " << guess << "!!!!\n";

		cout << "Let's spin that wheel!!!!!";
		
		


		cin.ignore();
		cin.get();
}	// end main