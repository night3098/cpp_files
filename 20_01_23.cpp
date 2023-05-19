#include <clocale>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	
	vector<int> vec;

	vec.push_back(0);
	vec.insert(vec.end(), 1);
	vec.insert(vec.end(), 2);
	vec.insert(vec.end(), 3);
	vec.insert(vec.end(), 4);
	vec.insert(vec.end(), 5);
	
	// iteration - one round of cycle
	vector<int>::iterator iter = vec.begin();
	
	// перебор
	
	// получаем итератор
	while(iter != vec.end()) { // пока не  дойдёт до конца
		cout << *iter << endl; // выводим 
		++iter; // перемещаем на блок дальше
	}
	
	
	
	while(iter != vec.end()) {
		*iter = (*iter)*(*iter); // возводим в квадрат
		cout << *iter << endl;                      //      ^_^
		iter++;
	}
	
	
	for(iter = vec.begin(); iter!=vec.end(); ++iter) {
		cout << *iter << endl;
	}
	
	return 0;
}

