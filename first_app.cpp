/*
test app
*/
# include <iostream>
# include <cstdlib>
# include <ctime>

/*
using namespace std;
*/
int main() {
	
	std::cout << "First app" << std::endl;
	
	int x = 8;
	int y = 2;
	
	/*  output  */
	
	std::cout << "Summ " << x << " and " << y << " = " << x+y << std::endl;
	
	/*  input  */
	/*
	std::cout << "Whats your name?" << std::endl;
	
	std::string str;
	
	std::cin >> str;
	
	std::cout << "Hello, " << str << " !" << std::endl;
	*/
	/*  reset point  */
	srand(static_cast<unsigned int>(time(0)));
	
	/*  cycles  */
	int i = 0;
	while(i < 10) {	
		int r = rand();
		/* 6 is added to a random number 1 to 20 */
		int rnd = r % 2000000 + 6;
		std::cout << "Random num: " << rnd << std::endl;
		//i++;
	}	
	return 0;
}

/*
end
*/
