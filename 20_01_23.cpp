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
	
	// �������
	
	// �������� ��������
	while(iter != vec.end()) { // ���� ��  ����� �� �����
		cout << *iter << endl; // ������� 
		++iter; // ���������� �� ���� ������
	}
	
	
	
	while(iter != vec.end()) {
		*iter = (*iter)*(*iter); // �������� � �������
		cout << *iter << endl;                      //      ^_^
		iter++;
	}
	
	
	for(iter = vec.begin(); iter!=vec.end(); ++iter) {
		cout << *iter << endl;
	}
	
	return 0;
}

