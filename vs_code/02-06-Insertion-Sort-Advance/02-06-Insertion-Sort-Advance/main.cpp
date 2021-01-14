// 02-06-Insertion-Sort-Advance.cpp : �������̨Ӧ�ó������ڵ㡣
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
		// Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		// д��1
		//        for( int j = i ; j > 0 ; j-- )
		//            if( arr[j] < arr[j-1] )
		//                swap( arr[j] , arr[j-1] );
		//            else
		//                break;

		// д��2
		//        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
		//            swap( arr[j] , arr[j-1] );

		// д��3
		T e = arr[i];
		int j;    // j ����Ԫ��eӦ�ò����λ��, Ĭ�ϳ�ʼ�� jΪ0��
		for (j = i; j > 0 && arr[j-1] > e; j--) {	// arr[j-1] > e ����ʹ���ڲ�ѭ����ǰ��ֹ��
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

	// ���Ը�������ĵ�
	cout << "Test for more ordered random array, size = " << n << ", random range [0, 3]" << endl;
	arr = SortTestHelper::generateRandomArray(n, 0, 3);
	arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("insertionSort", insertionSort, arr, n);
	SortTestHelper::testSort("selectionSort", selectionSort, arr2, n);
	delete[] arr;
	delete[] arr2;
	cout << endl;

	// ���Լ�������ĵ�
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

