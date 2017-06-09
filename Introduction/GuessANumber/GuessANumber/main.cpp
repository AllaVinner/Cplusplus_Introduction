#include <iostream>
using namespace std;

int main() {
	int theNum = 4;
	int guess = -1;
	bool correct = false;
	while(! correct){
		cout << "Guess a number between 1 - 10: " << endl;
		cin >> guess;
		correct = (guess == theNum); 
		if (correct) break;
		cout << "WRONG WRONG \a";
	}
	cout << "YOU GOT IT RIGHT!!!!";
	return 0;
}