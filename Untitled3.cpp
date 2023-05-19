# include <iostream>
# include <cstdlib>
# include <ctime>

void func(int num);
void fc_one();
void fc_two();
void months(int n);
void light_years(double c);
void clock(int h, int m);

void random() {
	double r = 51*50*49*48*47*46/6*5*4*3*2*1;
	std::cout << r << std::endl;
}

void clock(int h, int m){
	std::cout << "Time: " << h << ":" << m << std::endl;
}

void light_years(double c){
	int d = 63240;
	
	std::cout << c << " light years = " << c*d << " astronomical units" << std::endl;
}

void func(int num) {
	int x = 220;
	
	std::cout << "In yards> " << x*num << std::endl;
}

void fahrenheit(int v) {
	std::cout << v <<" degrees Celsius is " << v*1.8+32 << std::endl;
}

void months(int n) {
	int y = 12;
	
	std::cout << "Your age in months is " << n*y << std::endl;
}

void fc_one() {
	std::cout << "Three blind mice" << std::endl;
}

void fc_two() {
	std::cout << "See how they run" << std::endl;
}

int main(){	
	std::string name = "Semenov Artem";
	std::string addres = "B.Bogatkova 219";
	
	std::cout << name << std::endl;
	std::cout << addres << std::endl;
	
	
	
	std::cout << "Enter distance> " << std::endl;
	
	int num;
	std::cin >> num;
	func(num);
	
	
	
	fc_one();
	fc_one();
	fc_two();
	fc_two();
	
	
	
	std::cout << "Enter your age" << std::endl;
	int age;
	std::cin >> age;
	months(age);

	
	
	std::cout << "Please enter a Celsius value: " << std::endl;
	int cels;
	std::cin >> cels;
	fahrenheit(cels);
	


	std::cout << "Enter the number of light years: " << std::endl;
	double light;
	std::cin >> light;
	light_years(light);



	std::cout << "Enter the number of hours: " << std::endl;
	int hours;
	std::cin >> hours;
	std::cout << "Enter the number of minutes: " << std::endl;
	int minutes;
	std::cin >> minutes;
	clock(hours, minutes);
	
	return 0;
}
