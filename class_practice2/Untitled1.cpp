# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>
# include <iterator>


using namespace std;

class Parent {
	int x;
	
	public:
		void setx(int n) {
			x = n;
		}
		
		void showx() {
			cout << x << "\b" << endl;
		}
};

class Child: public Parent {
	int y;
	
	public:
		void sety(int n) {
			y = n;
		}
		
		void showy() {
			cout << y << "\b" << endl;
		}
};

int main() {
	setlocale(LC_ALL, "Russian");

	Child object;
	object.setx(100);
	object.sety(200);
	object.showx();
	object.showy();
	
	return 0;
}
