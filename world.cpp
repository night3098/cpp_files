/*	Practice	*/

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>

void math(long int x, long int y);
void math(long int x, long int y) {
	std::cout << "answer: " << std::endl;
	float answer = float(x)/float(y)*100;
	std::cout << answer << "%" << std::endl;
}

int main(){
	std::cout << "world's population" << std::endl;
	long int world = 0;
	std::cin >> world;
	
	std::cout << "Russia's population" << std::endl;
	long int Russia = 0;
	std::cin >> Russia;
	
	math(Russia, world);
	
	return 0;
}
