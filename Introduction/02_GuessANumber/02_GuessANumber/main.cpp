#include <iostream>
using namespace std;

int main() {

	int num = 4;
	int guess =2;
	while (true) {
		cout << "Guess a number: ";
		cin >> guess;
		if (guess == num) break;
		cout << "WRONG WRONG WRON \a" << endl;
	}
	cout << "You did it!!";
}

