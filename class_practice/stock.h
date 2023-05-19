#ifndef STOCK_H_
#define STOCK_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

class STOCK {
	private:
		string company;
		long shares;
		double share_val;
		double total_val;

		void set_total() {
			total_val = shares*share_val;
		}

	public:
		void acquire(const string c, long n, double pr); // c - company, n - number, pr - price
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show();
};


#endif
