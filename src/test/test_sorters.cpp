#include "test_sorters.h"

#include "../stopwatch.h"
#include "../sorters.h"
#include "../average.h"

#include <iostream>
#include <string>
#include <thread>

using namespace std;

void testQuickSort(vector<int> vec, int n) {
	stopwatch sw;
	average ma;
	bool pass = false;

	for (int i = 0; i < n; i++) {
		vector<int> x(vec);

		sw.start();
		sorters::quickSort(x, 0, x.size() - 1);
		sw.stop();

		if (!pass) {
			if (check(x))
				pass = true;
			else break;
		}

		ma = ma + sw.ms();
	}

	cout << "[" << (pass ? "PASS" : "FAIL") << "]"
		<< "QuickSort (avg ms): " << ma.avg() << endl;
}

void testMergeSort(vector<int> vec, int n) {
	stopwatch sw;
	average ma;
	bool pass = false;

	for (int i = 0; i < n; i++) {
		vector<int> x(vec);

		sw.start();
		sorters::mergeSort(x, 0, x.size()-1);
		sw.stop();

		if (!pass) {
			if (check(x))
				pass = true;
			else break;
		}

		ma = ma + sw.ms();
	}

	cout << "[" << (pass ? "PASS" : "FAIL") << "]"
		<< "MergeSort (avg ms): " << ma.avg() << endl;
}

void testInsertionSort(vector<int> vec, int n) {
	stopwatch sw;
	average ma;
	bool pass = false;

	for (int i = 0; i < n; i++) {
		vector<int> x(vec);

		sw.start();
		sorters::insertionSort(x);
		sw.stop();

		if (!pass) {
			if (check(x))
				pass = true;
			else break;
		}

		ma = ma + sw.ms();
	}

	cout << "[" << (pass ? "PASS" : "FAIL") << "]"
		<< "InsertionSort (avg ms): " << ma.avg() << endl;
}

void testBubbleSort(vector<int> vec, int n) {
	stopwatch sw;
	average ma;
	bool pass = false;

	for (int i = 0; i < n; i++) {
		vector<int> x(vec);

		sw.start();
		sorters::bubbleSort(x);
		sw.stop();

		if (!pass) {
			if (check(x))
				pass = true;
			else break;
		}

		ma = ma + sw.ms();
	}

	cout << "[" << (pass ? "PASS" : "FAIL") << "]"
		<< "BubbleSort (avg ms): " << ma.avg() << endl;
}

void testSelectionSort(vector<int> vec, int n) {
	stopwatch sw;
	average ma;
	bool pass = false;

	for (int i = 0; i < n; i++) {
		vector<int> x(vec);

		sw.start();
		sorters::selectionSort(x);
		sw.stop();

		if (!pass) {
			if (check(x))
				pass = true;
			else break;
		}

		ma = ma + sw.ms();
	}

	cout << "[" << (pass ? "PASS" : "FAIL") << "]"
		<< "SelectionSort (avg ms): " << ma.avg() << endl;
}

bool check(const vector<int> &vec) {
	if (vec.size() == 1)
		return true;

	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i] > vec[i + 1])
			return false;
	}

	return true;
}

vector<int> createVector(int n, bool same) {
	vector<int> result;
	result.reserve(n);

	if (!same)
		srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++) {
		result.emplace_back(rand());
	}

	return result;
}