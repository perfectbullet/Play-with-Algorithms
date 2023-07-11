#pragma once
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper{
	// ������n��Ԫ�ص��������, ÿ��Ԫ�ص������ΧΪ [l, r]
	int *generateRandomArray(int n, int l, int r) {
		assert(l < r);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (r - l + 1) + l;
		return arr;
	}

	// ��������Ƿ��С��������
	template<typename T>
	bool isSorted(T *arr, int n) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}
		return true;
	}

	// ����sort�����㷨����arr�������õ��������ȷ�Ժ��㷨����ʱ��
	template<typename T>
	void testSort(const string &sortName, void (*sort)(T*, int), T *arr, int n) {

		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSorted(arr, n));
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds " << endl;
	}

	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n - 1; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};