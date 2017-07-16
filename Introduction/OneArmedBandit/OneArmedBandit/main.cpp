#include <iostream>
#include <string>
using namespace std;

const int ROW = 3;
const int COLUMN = 3;
const int RANGE = 3;

int inputHandler(string str);
void printArray(int a[ROW][COLUMN]);
void setArray(int(&a)[ROW][COLUMN]);

int main() {

	const int NUMSIGN = 3;
	const int MAXROW = ROW * 2 + 2;

	int balance;
	int stake;
	int rowCount;

	int factors[MAXROW];
	int board[ROW][COLUMN];

	bool gameOver = false;

	string input;

	cout << "Hello my friend! Welcome back, we have missed you.\n"
		<< "Today we will play One-Armed-Bandit!\nMay the odds be ever in your favour.\n";

	// Asks the user to enter there starting balance and assignes it to balance.
	while (true) {
		cout << "How much do you want to put in? We don't allow any more then 1000, and we only accept Astrids: ";
		cin >> input;
		balance = inputHandler(input);
		if (0 < balance && balance <= 1000 && (balance % 20 == 0)) break;
		cout << "Please select a value within the range!\n";
	}

	do {
		// Asks the player to place a bet and assignes it to stake
		while (true) {
			cout << "How much do you want to bet? Everything from 1-50 kr is ok:  ";
			cin >> input;
			stake = inputHandler(input);
			if (1 <= stake && stake <= 50 && stake <= balance) break;
			cout << "Please select a value within the range!\n";
		}

		//Start the game and colculate all the scores

		setArray(board);


	} while (gameOver);

	printArray(board);

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