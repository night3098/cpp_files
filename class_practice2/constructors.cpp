/*
cunstructor and destructor
*/

# include <iostream>
# include <string>
# include <clocale>

using namespace std;

//global variable
int student_counter = 0;

class Student {
	private:
		int age;
		string name;
		string lastname;

	public:
		int foo();
		
		// constructor
		Student(int _age, string _name, string _lastname) {
			age = _age;
			name = _name;
			lastname = _lastname;
			cout << "[LOG]: Constructor is working" << endl;

			student_counter++;
		}
		
		//destructor
		~Student() {
			cout << "[LOG]: Destructor is working" << endl;
			student_counter--;
		}
};


int Student::foo() {
	Student s(24, "Ivanov", "Robert");
	cout  << "[LOG_MAIN]: total student_counter = " << student_counter << endl;
}


int main() {
	setlocale(LC_ALL, "Russian");

	cout  << "[LOG_MAIN]: total student_counter = " << student_counter << endl; // 0
	Student s2(24, "Ivanov", "Robert");
	cout  << "[LOG_MAIN]: total student_counter = " << student_counter << endl; // 1
	s2.foo();                                                                   // 2
	cout  << "[LOG_MAIN]: total student_counter = " << student_counter << endl; // 1
	
	return 0;
}
