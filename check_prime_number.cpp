/*	practice	*/
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

// prototype
int checkPrimeNumber(int x);
void emoji(int n, std::string em);

int checkPrimeNumber(int x) {
	bool Flag = true;

	for (int i = 2; i <= x/2; ++i){
		if (x % i == 0) {
			Flag = false;
			break;
		}
	}
	return Flag;
}

void emoji(int long n, std::string em) {
	for (int z = 0; 0 < n; ++z) {
		std::cout << em; // << std::endl;
	}
}


void reverse(std::string str) {
	int numOfSymbols = str.size();
	if (numOfSymbols == 1) {
		std::cout << str << std::endl;
	}
	else {
		std::cout << str[numOfSymbols - 1];
		reverse(str.substr(0, numOfSymbols - 1));
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	/*
	std::cout << "Enter a number to check: _____________\b\b\b\b\b\b\b\b\b\b\b\b\b";
	int long number;
	std::cin >> number;

	checkPrimeNumber(number);

	if ( checkPrimeNumber(number) == true) {
		std::cout << number << " - prime number" << std::endl;
	}

	else std::cout << number << " - not prime number" << std::endl;
	*/
	
	/*
	std::cout << "Num:__________\b\b\b\b\b\b\b\b\b\b";
	int long num = 0;
	std::cin >> num;

	std::cout << "Emoji: ";
	std::string s;
	std::cin >> s;

	emoji(num, s);
	*/

	std::string str;
	std::cout << "Enter string: ____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	getline(std::cin, str);
	reverse(str);

	return 0;
}
