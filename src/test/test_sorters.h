#pragma once

#include <vector>

using namespace std;

void testBubbleSort(vector<int> vec, int n);
void testSelectionSort(vector<int> vec, int n);
void testInsertionSort(vector<int> vec, int n);
void testMergeSort(vector<int> vec, int n);
void testQuickSort(vector<int> vec, int n);

bool check(const vector<int> &vec);

vector<int> createVector(int n, bool same = true);
