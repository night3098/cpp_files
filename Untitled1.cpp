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
		void sravn();
};

void man::init() {
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
}

void man::info() {
	system("cls");
	
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

void man::sravn() {
	cout << "=====================================" << endl;
 	
	if (age < 18){
		cout << name << ", you are still quite young " << endl;
	}
	
	if (age > 18 && age < 90) {
		cout << name << ", you are quite old " << endl;
	}
	
	if (age > 90) {
		cout << name << ", you are very old" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	man m1;
	m1.init();
	m1.info();
	m1.sravn();
	
	return 0;
}
