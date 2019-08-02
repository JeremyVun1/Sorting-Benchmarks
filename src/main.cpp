#include <vector>
#include <iostream>
#include <string>

#include "test\test_sorters.h"

using namespace std;

int main(int argc, char* argv[]) {
	int size = 10000;
	int runs = 2;

	//parse args
	if (argc > 1) {
		string s(argv[1]);
		try {
			size = stoi(s);
		}
		catch (exception e) {
			size = 1000;
		}
	}
	if (argc > 2) {
		string s(argv[2]);
		try {
			runs = stoi(s);
		}
		catch (exception e) {
			runs = 1;
		}
	}

	vector<int> vec = createVector(size);

	cout << "Vector size: " << size << endl;
	cout << "Runs: " << runs << endl;

	testQuickSort(vec, runs);
	testMergeSort(vec, runs);
	testInsertionSort(vec, runs);
	testSelectionSort(vec, runs);
	testBubbleSort(vec, runs);
}