#include "sorters.h"
#include <vector>
#include <algorithm>

using namespace std;

namespace sorters {

	void swap(int *a, int *b) {
		if (*a != *b) {
			*a ^= *b;
			*b ^= *a;
			*a ^= *b;
		}
	}

	////////////
	//INSERTION SORT
	////////////
	void insertionSort(vector<int> &vec) {
		for (int i = 1; i < vec.size(); i++) {
			for (int j = i; j > 0; j--) {
				if (vec[j] < vec[j - 1])
					swap(&vec[j], &vec[j - 1]);
			}
		}
	}

	////////////
	//BUBBLE SORT
	////////////
	void bubbleSort(vector<int> &vec) {
		if (vec.size() == 1)
			return;

		for (int i = vec.size() - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (vec[j] > vec[j + 1])
					swap(&vec[j], &vec[j + 1]);
			}
		}
	}

	////////////
	//SELECTION SORT
	////////////
	void selectionSort(vector<int> &vec) {
		if (vec.size() == 1)
			return;

		int minIndex;

		for (int i = 0; i < vec.size() - 1; i++) {
			int minIndex = i;

			for (int j = i+1; j < vec.size(); j++) {
				if (vec[j] < vec[minIndex])
					minIndex = j;
			}

			swap(&vec[i], &vec[minIndex]);
		}
	}

	////////////
	//MERGE SORT
	////////////
	void mergeSort(vector<int> &vec, int a, int b) {
		if (a == b)
			return;

		int mid = ((b - a) / 2) + a;

		mergeSort(vec, a, mid); //left
		mergeSort(vec, mid + 1, b); //right

		//merge a to b
		vector<int> temp;
		temp.reserve(b - a + 1);

		int i = a, j = mid + 1;
		while (i <= mid || j <= b) {
			if (i <= mid && j <= b) {
				if (vec[i] < vec[j])
					temp.emplace_back(vec[i++]);
				else
					temp.emplace_back(vec[j++]);
			}
			else if (i <= mid)
				temp.emplace_back(vec[i++]);
			else
				temp.emplace_back(vec[j++]);
		}

		for (int &i : temp)
			vec[a++] = i;
	}

	////////////
	//QUICK SORT
	////////////
	int partition(vector<int> &vec, int a, int b) {
		int pivot = vec[b];
		int k = a;

		for (int i = a; i <= b; i++) {
			if (vec[i] <= pivot) {
				swap(&vec[i], &vec[k]);
				k++;
			}
		}

		return k - 1;
	}

	void quickSort(vector<int> &vec, int a, int b) {
		if (a >= b)
			return;

		//pivot
		int pivot = partition(vec, a, b);

		//split
		quickSort(vec, a, pivot - 1);
		quickSort(vec, pivot + 1, b);
	}
}
