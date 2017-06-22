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
	
	const int RED = -101;		//Vad ä bäst bool här? för då behövs 2 guess
	const int BLACK = -102;
	const int pathNUMBER = 1;
	const int pathCOLOUR = 2;
	const int STARTINGBALANCE = 1000;
	const int NUMBERMULT = 10;
	const int COLOURMULT = 2;
	
	int balance = STARTINGBALANCE;				// The starting balnce is to be 1000 money
	int stake;									// The amount of money which is invested
	int winningNum;								// The number which the roulette ball lands on. Note that the colour can be calculated
	int winningColour;
	//bool betOnNum;								// Is the player betting on a number or a colour? true -> number; false -> colour
	int guess;
	int tempNum;
	bool gameWon = true;
	bool gameOver = false;


	string input;

	// Welcome to the casino
	cout << "Welcome to the wacky tacky macky Casino. You will start with a plesent gift of " << STARTINGBALANCE << "Wacky money. Todays game is .... ROULETTE!!!! \a" << endl;
	
		while (! gameOver) {
				// The loop will run untill a godtagbart input is given, which will (later) be used to assigne a value to stake.
				// Exwptible values: 1 - 3
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
				cout << "Well " << stake << " money it is :) \n\n";

				// The loop will run until an exeptible input is given which (later) will be used to assigne a value to guess
				// Exeptible value: 1 - 2
				while (true) {
					cout << "Do you want to bet on colour or a number?\n"
						<< "1. Colour \n2. Number\n"
						<< "The multiplication thing is " << NUMBERMULT << " for numbers and " << COLOURMULT << " for colours.\n";
					cin >> input;
					tempNum = inputHandler(input);
					if (1 <= tempNum && tempNum <= 2) break;
					cout << "Please select a value within the range!\n";
				}

				// Guess is assiged a value based on the input. guess =(1 - 36, RED OR BLACK)
				switch (tempNum)
				{
				case 1:						// Player will bet on colour
					while (true) {
						// The loop will run until an exeptible input is given which (later) will be used to assigne a value to guess
						// Exeptible value: 1 - 2
						cout << "OKEY... so do you want to bet on red or black?\n1.Red\n2.Black\n";
						cin >> input;
						tempNum = inputHandler(input);
						if (1 <= tempNum && tempNum <= 2) break;
						cout << "Please select a value within the range!\n";
					}
					// Guess is assigned black or red
					switch (tempNum)
					{
					case 1:
						guess = RED;
						break;
					case 2:
						guess = BLACK;
						break;
					}
					tempNum = 1;	// Reset tempNum to its value in the outher switch.  Was this a good idea?
					break;
				case 2:			//The player is betting on a number
					while (true) {
						cout << "OKEY... so bet on a number between 1 and 36: ";
						cin >> input;
						tempNum = inputHandler(input);
						if (1 <= tempNum && tempNum <= 36) break;
						cout << "Please select a value within the range!\n";
					}
					guess = tempNum;
					tempNum = 2;
					break;
				}

				cout << "Then we will go with ";
				if (guess == RED) cout << "red!!!!!\n\n";
				else if (guess == BLACK) cout << "Black!!!!\n\n";
				else cout << guess << "!!!!\n\n";

				cout << "Let's spin that wheel!!!!!";
				
				//Create the winning number and the colour of which
				winningNum = rand() % 36 + 1;
				winningColour = (winningNum % 2 == 0) ? BLACK : RED;
				cout << "THE WINNING NUMBER IS " << ((winningColour == BLACK) ? "BLACK " : "RED ") << winningNum << "\n\n";

				//See if the player won
				if (guess == ((guess > 0) ? winningNum : winningColour)) gameWon = true;
				else gameWon = false;

				// Change the value of balance and gameWon
				if (guess > 0) {
					if (guess == winningNum) {
						gameWon = true;
						balance += NUMBERMULT*stake;
					}
					else {
						gameWon = false;
						balance -= stake;
					}
				}
				else {
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
					cout << "OMG you won!!!! You won " << stake << ". That is ammazing.\n";
				}
				else {
					cout << "It is ammazing... mavelous... you... you lost! " << stake << "\n";
				}
				cout << "This brings you balance to " << balance << "\n";

				//Chack if you have positive balance
				if (balance <= 0) {
					gameOver = true;
				}
				else {
					while (true) {
						cout << "Do you want to play again?\n1. Yes\n2. No\n: ";
						cin >> input;
						tempNum = inputHandler(input);
						if (1 <= tempNum && tempNum <= 2) break;
						cout << "Please select a value within the range!\n";
					}

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



			} // End of gameOver loop

			if (balance > 0) {
				cout << "So sorry to see you leaving, but well played.\nYou will be walking home with " << balance << "That is not ashame\n";
			}
			else {
				cout << "Get out of here you know body and come back when you have money you rat!\n";
			}

			
	cin.ignore();
	cin.get();
}