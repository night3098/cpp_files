# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>
# include <iterator>

using namespace std;

class Rectangle {
	private:
		int a;
		int b;
		int corner;
	public:
		Rectangle(int _a, int _b, int _corner) {
			a = _a;
			b = _b;
			corner = _corner;
		}
		
		void isSet() {
			if(corner != 90) {
				cout << "False" << endl;
			}
			
			if(corner == 90) {
				cout << "True" << endl;
			}
		}
		
		void perimeter() {
			int p;
			int pp;
			pp = a + b;
			p = pp*2;
			cout << p << endl;
		}
		
		void s_square() {
			int s;
			s = a * b;
			cout << s << endl;
		}
		
		void sides() {
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
			cout << "corner = " << corner << endl;
		}
		
};

class Square: Rectangle {
	private:
	
	public:
		Rectangle(int _a, int _b, int _corner) {
			a = _a;
			b = _b;
			corner = _corner;
		}
		
		void isSet() {
			if(a == b) {
				cout << "True" << endl;
			}
			if(a != b) {
				cout << "False" << endl;
			}
		}
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	Rectangle rec(13, 57, 90);
	rec.isSet();
	rec.perimeter();
	rec.sides();
	rec.s_square();

	Rectangle rec2(97, 37, 90);
	rec2.isSet();
	rec2.perimeter();
	rec2.sides();
	rec2.s_square();
		
	return 0;
}
