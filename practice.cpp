/*	PRACTICE	*/

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>

using namespace std;

void num1(double data) {
	const double fut = 30.48;
	const double duim = 2.54;
	
	cout << data << " = " << data*fut << " ft." << endl;
	cout << data << " = " << data*duim << " dm." << endl;
}

void app(double x, double y) {
	const double duim = 12;
	const double metres = 0.0254;
	const double kilo = 2.2;
	
	double duim_data = x*duim;
	double metres_data = duim_data*metres;
	
	double kilo_data = y/kilo;
	
	double one = metres_data*metres_data;
	
	double bmi = kilo_data/one;
	
	cout << "BMI: " << bmi << endl;
	
}

void geo(double deg, double min, double sec){
	// a + b/60 + c/3600
	
	double data_out = deg+min/60+sec/3600;
	
	cout << data_out << " degrees" <<  endl;
	
}

void clendar(long long t) {
	const int day_in_year = 365;
	const int hour_in_day = 24;
	const int min_in_hour = 60;
	const int sec_in_sec = 60;
	
	int days = 0, hour = 0, min = 0, sec = 0;
	int ost;

    days = t / (hour_in_day * min_in_hour * sec_in_sec);
    hour = (t % (hour_in_day * min_in_hour * sec_in_sec)) / (min_in_hour * sec_in_sec);
    min = (t % (hour_in_day * min_in_hour * sec_in_sec)) % (min_in_hour * sec_in_sec) / sec_in_sec;
    sec = (t % (hour_in_day * min_in_hour * sec_in_sec)) % (min_in_hour * sec_in_sec) % sec_in_sec;
	
	
	cout << t << " seconds = " << days << " days, " << hour << " hours, " << min << " minutes, " << sec << " secundes" << endl;
}

void car(double km, double lt) {
	double lt_km = double(lt)*100/km;
	
	cout << "Consuption: " << lt_km << " litres / 100 km" << endl;
}

void europe(double e_km, double e_lt) {
	const double mil = 1.61;
	const double gal = 3.875;
	
	double m = e_km*mil;
	double g =e_lt*gal;
	
	double e_out = m/g;
	
	cout << "Consuption: " << e_out << " miles / 1 galones" << endl;
}

int main() {

	/*
	cout << "Enter a height in centimeters: ________\b\b\b\b\b\b\b\b";
	double sm;
	cin >> sm;
	num1(sm);
	*/
	
	/*
	cout << "Enter a height in fots: _____\b\b\b\b\b";
	double fots_data;
	cin >> fots_data;
	
	cout << "Enter a weight in funts: _____\b\b\b\b\b";
	double funts_data;
	cin >> funts_data;
	
	app(funts_data, fots_data);
	*/
	
	/*
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First, enter the degrees:____\b\b\b\b";
	double degrees;
	cin >> degrees;
	
	cout << "Next, enter the minutes of arc:____\b\b\b\b";
	double minutes;
	cin >> minutes;
	
	cout << "Finally, enter the seconds of arc:____\b\b\b\b";
	double seconds;
	cin >> seconds;
	
	geo(degrees, minutes, seconds);
	*/
	
	/*
	cout  << "Enter the number of seconds: ";
	long long time;
	cin >> time;
	calendar(time);
	*/
	
	/*
	cout << "Enter the number of kilometres: ";
	double kilometres;
	cin >> kilometres;
	
	cout << "Enter the number of litres: ";
	double litres;
	cin >> litres;
	
	car(kilometres, litres);
	*/
	
	
	/*
	cout << "Enter the number of kilometres: ";
	double kilometres;
	cin >> kilometres;
	
	cout << "Enter the number of litres: ";
	double litres;
	cin >> litres;
	
	europe(kilometres, litres);
	*/
	return 0;
}
