#include <iostream>
#include <iterator>
#include <string>
#include <clocale>

using namespace std;

class man {
	private:
		string name;
		int age;

	public:
		void init();
		void info();
};

void man::init() {
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
}

void man::info() {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Height: " << height << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	man m1;
	m1.init();
	m1.info();
	
	return 0;
}