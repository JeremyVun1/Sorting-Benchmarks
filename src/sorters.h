#pragma once

#include <vector>

using namespace std;

namespace sorters {
	void bubbleSort(vector<int> &vec);
	void selectionSort(vector<int> &vec);
	void insertionSort(vector<int> &vec);
	void mergeSort(vector<int> &vec, int a, int b);
	void quickSort(vector<int> &vec, int a, int b);
}
