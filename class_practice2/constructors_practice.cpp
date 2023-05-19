# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>
# include <iterator>

using namespace std;

class Critter {
	private:
		int m_Hunger;
		int m_Boredom;

	public:
		// prototype of constructor
		Critter(int hunger = 0, int bredom = 0);

		void Talk();
		void Eat(int food = 10);
		void Play(int fun = 10);
		void PassTime(int time = 1);
		int Get_Mood() const;
		
		void Greet();
};

Critter::Critter(int hunger, int boredom) {
	cout << "New critter was born \n[0_0]" << endl;
	m_Hunger = hunger;
	m_Boredom = boredom;
}

int Critter::Get_Mood() const{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time) {
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk() {
	cout << "I'm critter and i feel: ";

	int mood = Get_Mood();
	if(mood > 15) {
		cout << "mad.\n" << endl;
	}

	else if(mood > 10) {
		cout << "frustrated. \n" << endl;
	}

	else if(mood > 5) {
		cout << "ok.\n" << endl;
	}

	else {
		cout << "happy.\n" << endl;
	}

	PassTime();
}

void Critter::Eat(int food) {
	cout << "Nyam Nyam Nyam" << endl;
	m_Hunger -= food;
	if (m_Hunger < 0) {
		m_Hunger = 0;
	}
	PassTime();
}


void Critter::Play(int fun) {
	cout << "Weeeee" << endl;
	m_Boredom -= fun;
	if (m_Boredom < 0) {
		m_Boredom = 0;
	}
	PassTime();
}

/*
void Critter::Greet() {
	cout << "Hi!, I'm a critter" << endl;
	cout << "My hunger status is " << m_Hunger << endl;
}
*/

int main() {
	setlocale(LC_ALL, "Russian");
	
	Critter Felix;
	Felix.Talk();
	
	int choice;
	do {
		cout << "0 - quit\n1 - talk\n2 - feed\n3 - play\nchoice: ";
		cin >> choice;

		switch(choice) {
			case 0:
				cout << "Bye" << endl;
				break;
			case 1:
				Felix.Talk();
				break;
			case 2:
				Felix.Eat();
				break;
			case 3:
				Felix.Play();
				break;
			default:
				cout << "err" << endl;
		}
		
	}
	
	while(choice != 0);

	return 0;
}
