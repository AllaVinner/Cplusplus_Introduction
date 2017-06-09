#include <iostream>  			// Includes the library "iostream" - input and 
#include <string>
using namespace std;			// Is a standard on how to do the syntax from the library

int main() {
	string a = "Hay hay";
	cout << a << endl;			
	cin >> a;
	cout << a;
	cin.ignore();
	cin.get();
}