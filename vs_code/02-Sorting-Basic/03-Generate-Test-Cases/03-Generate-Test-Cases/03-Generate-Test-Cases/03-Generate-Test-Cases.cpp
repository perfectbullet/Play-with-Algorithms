// 03-Generate-Test-Cases.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T* arr, int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i; j < n; j++) {
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}


int main()
{
	int N = 2000;
	int *arr = generateRandomArray(N, 0, N);
	selectionSort(arr, N);
	printArray(arr, N);
	delete[] arr;
    return 0;
}

