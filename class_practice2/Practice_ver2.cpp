# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>
# include <iterator>

using namespace std;

class Triangle {
	private:

	
	public:
		int a;
		int b;
		int c;
		int h;
		
		Triangle(int _a, int _b, int _c, int _h) {
			a = _a;
			b = _b;
			c = _c;
			h = _h;
		}
		
		int getter_a() {
			return a;
		}
		int getter_b() {
			return b;
		}
		int getter_c() {
			return c;
		}
		int getter_h() {
			return h;
		}
		
		void isSet() {
			if(a+b > c && b+c > a && c+a > b) {
				cout << "True" << endl;
			}
			
			else{
				cout << "False" << endl;
			}
		}
		
		void perimeter() {
			int p;
			p = a + b + c;
			cout << p << endl;
		}
		
		void t_square() {
			int s;
			s = 0.5 * a * h;
			cout << s << endl;
		}
		
		void sides() {
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
			cout << "c = " << c << endl;
			cout << "h = " << h << endl;
		}
		
};


class eTriangle: public Triangle {
	private:
	
	public:
		eTriangle(int _a, int _b, int _c, int _h) {
			a = _a;
			b = _b;
			c = _c;
			h = _h;
		}
		
		void isSet2() {
			if(a == b && b == c && c == a) {
				cout << "True" << endl;
			}
			
			else{
				cout << "False" << endl;
			}
		}
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	Triangle tr(10, 20, 50, 33);
	tr.isSet();
	tr.perimeter();
	tr.sides();
	tr.t_square();

	Triangle tr2(30, 40, 60, 28);
	tr2.isSet();
	tr2.perimeter();
	tr2.sides();
	tr2.t_square();

	cout << "===========================================" << endl;
	
	eTriangle etr1(10, 10, 10, 8);
	etr1.isSet2();
	etr1.perimeter();
	etr1.sides();
	etr1.t_square();

	eTriangle etr2(20, 11, 10, 10);
	etr2.isSet2();
	etr2.perimeter();
	etr2.sides();
	etr2.t_square();
	
	return 0;
}
