# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>
# include <iterator>

using namespace std;

class Enemy {
	protected:
		double hp;
		double damage;
		double height;
		double weight;
		
	public:
		void setter(double _hp, double _damage, double _height, double _weight) {
			hp = _hp;
			damage = _damage;
			height = _height;
			weight = _weight;
		}
		
		virtual void cr_damage() = 0;
		
};

class Goblin: public Enemy {
	public:
		void cr_damage() {
			cout << "Damage: " << damage + hp / height << endl;
		}
};

class Elf: public Enemy {
	public:
		void cr_damage() {

		}
};

class Orc: public Enemy {
	public:
		void cr_damage() {

		}
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	Figure *p;
	Triangle t;
	
	p = &t;
	p -> setter(10.5,  6.3);
	p -> area();
	
	return 0;
}
