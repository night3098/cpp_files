/*
Полиморфизм
*/

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>
# include <iterator>

using namespace std;

class Base {
	public:
		virtual void who() {
			cout << "Base class" << endl;
		}
};

class First: public Base {
	void who() {
		cout << "First child class" << endl;
	}
};

class Second: public Base {
	void who() {
		cout << "Second child class" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	Base b;
	
	Base *p;
	
	First f;
	
	Second s;
	
	p = &b;
	
	p -> who();
	
	p = &f;
	
	p -> who();
	
	p = &s;
	
	p -> who();
	
	return 0;
}
