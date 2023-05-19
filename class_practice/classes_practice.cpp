#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <string>
#include <windows.h>

using namespace std;


class Stock {
	private:
		string company;
		long shares;
		double share_val;
		double total_val;

		void set_total() {
			total_val = shares*share_val;
		}

	public:
		void acquire(const string co, long n, double pr); // co - company, n - number, pr - price
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
};



void Stock::buy(long num, double price) {
	if ( num <= 0 ) {
		cout << "Transaction is aborted.\n _(0_0)_/\n" << endl;
	}

	else {
		shares += num; // increase the total number of shares
		share_val = price; // set the share price
		set_total();
	}
}


void Stock::sell(long num, double price) {
	if (( num <= 0 ) || ( num > shares)) {
		cout << "Transaction is aborted.\n |_(0_0)_|\n" << endl;
	}

	else {
		shares -= num;
		share_val = price; // set the share price
		set_total();
	}
}

void Stock::acquire(const string co, long n, double pr) {
	company = co;

	if ( n < 0 ) {;
		cout << "Number of shares can't be negative; " << company << " shares set to 0. >(-_-)<\n" << endl;
		cout << "Loading...." << endl;
		shares = 0;
	}

	else {
		shares = n;
	}

	share_val = pr;
	set_total();
}

void Stock::update(double price) {
	share_val = price;
	set_total();
}

void Stock::show() {
	cout << "company: " << company << "\nshares: " << shares << "\nshare price: " << share_val << "\ntotal worth: " << total_val << "\n(0_0)" << endl;
}


int main() {
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
    Sleep(200);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
    Sleep(200);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
    Sleep(200);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
    Sleep(200);
	std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
	Sleep(200);
	std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
	Sleep(200);
	std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
	Sleep(200);
	std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
	Sleep(200);
	std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
	Sleep(200);
	std::cout << "\b\b\b\b\b\b\b\b\b\bLoading...\n" << std::flush;
	Sleep(200);

	Stock stock1;
	stock1.acquire("NanoSmart", 100, 90.50);
	stock1.show();
	stock1.buy(100, 18.90);
	stock1.show();
	stock1.sell(400, 20.00);
	stock1.show();

	return 0;
}
