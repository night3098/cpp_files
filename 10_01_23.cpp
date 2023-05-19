/*	working with data types	*/

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cstring>

//using nmaespace std;

int main() {
	
	std::cout << "===================== [ int ]=====================" << std::endl;
	
	/*	init a constant		*/
	const int Year = 2023;
	std::cout << Year << std::endl;
	
	bool is_ready = true;
	std::cout << "True: " << is_ready << std::endl;
	
	bool not_ready = false;
	std::cout << "False: " << not_ready << std::endl;
	
	std::cout << "===================== [ int ]=====================" << std::endl;
	
	/*	int to float	*/
	
	int x = 4;
	int y = 3;
	
	int wheels = 4/3;
	
	std::cout << float(x)/float(y) << std::endl;
	
	std::cout << wheels << std::endl;
	
	std::cout << "===================== [ int ]=====================" << std::endl;
	
	int s = 7892045182671097;
	
	if(s % 2 == 0) {
		std::cout << "these number are even" << std::endl;
	}
	
	else {
		std::cout << "there number are not even" << std::endl;
	}
	
	std::cout << "===================== [ char ]=====================" << std::endl;
	
	char m[8] = "Kat";
	std::cout << "Cat name: " << m << std::endl;
	std::cout << "Number or letters: " << strlen(m) << std::endl;
	std::cout << "Size memory: " << sizeof(m) << std::endl;  /*  col memory  */
	
	std::cout << "===================== [ PRACTICE ]=====================" << std::endl;
	
	/*	end symbol	*/
	char cat[10] = "Nikas";
	int end = strlen(cat)-1;
	std::cout << "End: " << cat[end] << std::endl;
	
	std::cout << "===================== [ string ]=====================" << std::endl;
	
	/*	string	*/
	
	std::string str1 = "Hello ";
	std::string str3 = "user ";
	std::string str2 = ", ";
	
	std::cout << str1 + str2 + str3 << std::endl;
	
	int size_str = str1.size() + str2.size() + str3.size();
	std::cout << size_str << std::endl;
	
	std::cout << "===================== [ string ]=====================" << std::endl;
	
	std::string text1 = "Hello User";
	std::string text2 = "Hello Admin";
	
	if(text1 < text2) {
		std::cout << "text 1 < text 2" << std::endl;
	}
	
	else if(text1 > text2) {
		std::cout << "text 1 > text 2" << std::endl;
	}
	
	else {
		std::cout << "text 1 = text 2" << std::endl;
	}
	
	return 0;
}
