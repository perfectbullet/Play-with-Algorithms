// 02-04-Selection-Sort-Performance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SortTestHelper.h"

using namespace std;
 
template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int mindIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[mindIndex])
				mindIndex = j;
		}
		swap(arr[i], arr[mindIndex]);
	}
}

int main()
{
	int n = 20000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	// selectionSort(arr, n);
	// SortTestHelper::printArray(arr, n);
	SortTestHelper::testSort("Selection sort", selectionSort, arr, n);
	delete[] arr;
    return 0;
}

