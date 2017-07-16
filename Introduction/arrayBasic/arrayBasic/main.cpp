#include <iostream>
#include "..\..\..\..\MathObjects\Function\Function\main.h"

// Prints the array as avector with text
void printArray(int a[], int length);


int main() {
	const int row = 11;
	int a [row];
	for (int i = 0; i < row; i++) {
		a[i] = i;
	}

	printArray(a, row);
	reverse(a, row);
	std::cout << std::endl;
	printArray(a, row);

	std::cin.ignore();
	std::cin.get();
	return 0;
}

void printArray(int a[], int length) {
	for (int i = 0; i < length; i++) {
		std::cout << "The value of index " << i << " : ";
		std::cout << a[i] << ' ' << std::endl;
	}
}



