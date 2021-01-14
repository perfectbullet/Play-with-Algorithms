// 02-06-Insertion-Sort-Advance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T *arr, int n) {
	for (int i = 1; i < n; i++) {
		// 寻找元素arr[i]合适的插入位置
		// 写法1
		//        for( int j = i ; j > 0 ; j-- )
		//            if( arr[j] < arr[j-1] )
		//                swap( arr[j] , arr[j-1] );
		//            else
		//                break;

		// 写法2
		//        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
		//            swap( arr[j] , arr[j-1] );

		// 写法3
		T e = arr[i];
		int j;    // j 保存元素e应该插入的位置, 默认初始化 j为0；
		for (j = i; j > 0 && arr[j-1] > e; j--) {	// arr[j-1] > e 可能使得内层循环提前终止掉
			arr[j] = arr[j - 1];
		}
		arr[j] = e;

	}
	
	return;
}

int main()
{
	int n = 20000;
	cout << "Test for random arry, size is " << n << "range is [0, 2000]" << endl;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	SortTestHelper::testSort("insertionSort", insertionSort, arr, n);
	SortTestHelper::testSort("selectionSort", selectionSort, arr2, n);
	delete[] arr;
	delete[] arr2;
	cout << endl;

	// 测试更加有序的的
	cout << "Test for more ordered random array, size = " << n << ", random range [0, 3]" << endl;
	arr = SortTestHelper::generateRandomArray(n, 0, 3);
	arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("insertionSort", insertionSort, arr, n);
	SortTestHelper::testSort("selectionSort", selectionSort, arr2, n);
	delete[] arr;
	delete[] arr2;
	cout << endl;

	// 测试几乎有序的的
	cout << "Test for nearly ordered random array, size = " << n << ", random range [0, 3]" << endl;
	arr = SortTestHelper::generateNearlyOrderedArray(n, 300);
	arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("insertionSort", insertionSort, arr, n);
	SortTestHelper::testSort("selectionSort", selectionSort, arr2, n);
	delete[] arr;
	delete[] arr2;
	cout << endl;
    return 0;
}

