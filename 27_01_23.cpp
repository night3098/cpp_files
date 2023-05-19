/*	array sorting	*/
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

/* prototype */
int bubble_sort(int nums[], int size);

int bubble_sort(int nums[], int size) {
	int switched = 1;
	int hold = 0;

	int i = 0;
	int j = 0;
	size -=1;
	for (i; i < switched; i++) {
		switched = 0;
		for (j; j < size-i; j++) {
			if (nums[j] > nums[j+1]) {
				switched = 1;
				hold = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = hold;
			}
		}
	}
	
	return 0;
}


int main() {
	int nums[] = {946163, 211434, 93331545, 134541542, 543541, 651241, 75466, 875241, 1913546, 416410};
	int m = 0;
	int z = 0;
	int y = 0;
	
	srand(time(NULL));
	vector<int> numbers;
	
	for(m; m<10; m++) {
		int rnd = rand();
		numbers.insert(numbers.end(), rnd);
	}

	cout << "Before sort: " << endl;
	for(z; z < 10; z++) {
		cout << nums[z] << " " << endl;
	}

	bubble_sort(nums, 10);

	cout << "\n\nAfter sort:" << endl;
	for(y; y < 10; y++) {
		cout << nums[y] << " " << endl;
	}

	return 0;
}
