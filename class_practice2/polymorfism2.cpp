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

class Figure {
	protected:
		double x, y;
	public:
		void setter(double _x, double _y) {
			x = _x;
			y = _y;
		}
		
		virtual void area() = 0; // pure virtual function - abstract class
		
};

class Triangle: public Figure {
	void area() {
		cout << "Area triangles with height and base" << endl;
		cout << " is " << x * 0.5 * y << endl;
	}
};

class Rectangle: public Figure {
	void area() {
		cout << "Area rectangle with height and weight" << endl;
		cout << " is " << x * y << endl;
	}
};

class Circle: public Figure {
	void area() {
		cout << "Area circle with radius" << endl;
		cout << " is " << 2 * 3.14 * x << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	Figure *p;
	Triangle t;
	
	p = &t;
	p -> setter(10.5,  6.3);
	p -> area();
	
	cout << "===============================" << endl;
	
	Figure *r;
	Rectangle rec;
	
	r = &rec;
	r -> setter(20.5, 10.5);
	r -> area();
	
	cout << "===============================" << endl;
	
	Figure *c;
	Circle cr;
	
	c = &cr;
	c -> setter(10.0, 1);
	c -> area();
	
	cout << "===============================" << endl;
	
	return 0;
}
