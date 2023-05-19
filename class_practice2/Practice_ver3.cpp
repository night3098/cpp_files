# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>
# include <iterator>

using namespace std;

class Worker {
	private:
		int w_time;
		int expirence;
		string name_lastname;
		
		
	public:
		Worker(int _w_time, int _expirence, string _name_lastname) {
			w_time = _w_time;
			expirence = _expirence;
			name_lastname = _name_lastname;
		}
		
		void getInfo() {
			cout << "Work time: " << w_time << endl;
			cout << "Expirence: " << expirence << endl;
			cout << "Name, lastname: " << name_lastname << endl;
		}
};

class Director: Worker  {
	private:
		
	public:
};

class Firma: Director, Worker {
	private:
		string name;
		string office_addres;
		int date;
		
	public:
		Firma(string _name, string _office_addres, int _date) {
			name = _name;
			office_addres = _office_addres;
			date = _date;
		}
		
		void info() {
			cout << "Name: " << name << endl;
			cout << "Addres: " << office_addres << endl;
			cout << "Date: " << date << endl;
		}
};

class HeadOfCompany {
	private:
		
	public:
		
};

class GosRuc: HeadOfCompany {
	private:
	
	public:
		
};

class RucOOO: HeadOfCompany {
	private:
	
	public:
		
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	return 0;
}
