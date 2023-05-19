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

#define MAXARRAY 100

using namespace std;

void quicksort(int arr[], int low, int high);

void quicksort(int arr[], int low, int high) {
	int i = low;
	int j = high;
	int y = 0;

	int z = arr[(low + high) / 2 ];

	do {
		while ( arr[i] < z) { // find element to the left
			i++;
		}
		while ( arr[j] > z) { // find element to the right
			j--;
		}

		if (i <= j) {
			y = arr[i];
			arr[i] = arr[j];
			arr[j] = y;

			i++;
			j++;

		}
	}
	while ( i <= j);
	if(low < j){
		quicksort(arr, low, high);
	}
	if(i < high) {
		quicksort(arr, low, high);
	}
}


int main() {
	int nums[] = {155656, 4532, 764521, 63441, 543541, 651241, 75466, 875241, 654235, 15452};
	int i = 0;
	int z = 0;
	
	srand(time(NULL));

	int array[MAXARRAY] = {0};

	for(z; z < MAXARRAY; z++) {
		int rnd = rand();
		array[z] = rand() % 100;
	}
	
	quicksort(array, 0, (MAXARRAY - 1));

	for(i; i < MAXARRAY; i++) {
		cout << array[i] << " ";
	}

	return 0;
}
