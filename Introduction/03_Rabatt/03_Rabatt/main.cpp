#include <iostream>
// NOTE: no using namespace std
void shoppingList() {
	std::cout << "ShoppingList\n 1. Shirt \t 20.50 Pound \n 2. Jeans \t 43.95 Pound \n 3. Shorts\t 30.10 Pound \n 4. Socks \t 4.30 Pound \n 5. Quit \n";
}

int main() {
	const double shirtPrice = 20.50;
	const double jeansPrice = 43.95;
	const double shortsPrice = 30.10;
	const double sockPrice = 4.30;
	double totPrice = 0;
	int chooseItem = -1;
	bool buyMore = true;

	while (buyMore) {
		std::cout << "You pay: " << totPrice << std::endl;		// endl is part of the iostream library
		shoppingList();
		std::cout << "What do you want to buy: ";
		std::cin >> chooseItem;
		if (chooseItem == 1) totPrice += shirtPrice;
		if (chooseItem == 2) totPrice += jeansPrice;
		if (chooseItem == 3) totPrice += shortsPrice;
		if (chooseItem == 4) totPrice += sockPrice;
		if (chooseItem == 5) buyMore = false;
	}
	std::cout << "BYE!!!";
}