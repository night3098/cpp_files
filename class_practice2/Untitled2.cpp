# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>
# include <clocale>
# include <iterator>

using namespace std;

class User {
	string login;
	int age;
	
	public:
		void SetInfo(string log, int a) {
			login = log;
			age = a;
		}
		
		void GetInfo() {
			cout << login << endl;
			cout << age << endl;
		}
		
};

class Admin: public User {
	string password;
	
	public:
		void SetInfoAdmin(string pass) {
			password = pass;
		}
		
		void GetInfoAdmin() {
			cout  << password << endl;
		}
};

class Moder:public Admin {
	bool ban;
	int work_time;
	
	public:	
		Moder(bool _ban, int _work_time) {
			ban = _ban;
			work_time = _work_time;
		}
		void GetInfoModer() {
			cout << ban << endl;
			cout << work_time << endl;
		}
	
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	User grisha;
	grisha.SetInfo("Grisha", 15);
	grisha.GetInfo();
	
	Admin misha;
	misha.SetInfo("Misha", 16);
	misha.SetInfoAdmin("super_mega_secret_password");
	misha.GetInfo();
	misha.GetInfoAdmin();
	
	Moder artem(true, 10);
	artem.SetInfo("Artem", 16);
	artem.SetInfoAdmin("764321784608237562534");
	artem.GetInfo();
	artem.GetInfoAdmin();
	artem.GetInfoModer();
	
	return 0;
}
