# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>

using namespace std;

class Student {
	private:
		string name;
		string lastname;

		int grades[5];
		float average_mark;

		void average();

		void isTransfer();

	public:

		Student(string _name, string _lastname, int _grades[5]) {
			name = _name;
			lastname = _lastname;
			grades[5] = _grades[5];


			cout << "[LOG]: Constructor is working" << endl;

		}
		
		//destructor
		~Student() {
			cout << "[LOG]: Destructor is working" << endl;
		}

};

void Student::average() {
	int i = 0;
	int sum = 0;
	for(i; i < 5; i++) {
		sum += grades[i];
	}

	average_mark= sum / 5.0;

	cout << name << lastname << ": " << endl;
	cout << "Average mark: " << average_mark << endl;
}

void Student::isTransfer() {
	if(average_mark >= 4.0) {
		cout << "Transfer yes" << endl;
	}
	else {
		cout << "Transfer no" << endl;
	}
}



int main() {
	setlocale(LC_ALL, "Russian");

	Student st1("Ivanov", "Robert", {3, 5, 2, 4, 1});
	Student st2("Ivanov", "Peter", {5, 4, 3, 4, 1});
	Student st4("Peter", "Parker", {5, 4, 2, 4, 1});
	Student st5("Ivanov", "Ivan", {5, 2, 2, 4, 1});

	return 0;
}
