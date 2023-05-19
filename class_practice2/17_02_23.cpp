/*
cunstructor and destructor
*/

# include <iostream>
# include <string>
# include <clocale>

using namespace std;

/*
class Men {
	private:
		int age;
		string name;
		string lastname;

	public:
		void setInfo(int _age, string _name, string _lastname) {
			age = _age;
			name = _name;
			lastname = _lastname;
		}
		void dr() {
			age++;
			cout << "Happy Birthday, " << lastname << " " << name << " - " << age << endl;
		}

};
*/

class Men {
	private:
		int age;
		string name;
		string lastname;

	public:
		// constructor
		Men(int _age, string _name, string _lastname) {
			age = _age;
			name = _name;
			lastname = _lastname;
			cout << "[LOG]: Constructor is working" << endl;
		}
		
		//destructor
		~Men() {
			cout << "[LOG]: Destructor is working" << endl;
		}

		// func
		void dr() {
			age++;
			cout << "Happy Birthday, " << lastname << " " << name << " - " << age << endl;
		}

};

int main() {
	setlocale(LC_ALL, "Russian");

 	/*
	Men m1;
	m1.setInfo(14, "Ivanov", "Robert");
	m1.dr();
	*/

	Men men1(16, "Ivanov", "Robert");
	men1.dr();

	return 0;
}
