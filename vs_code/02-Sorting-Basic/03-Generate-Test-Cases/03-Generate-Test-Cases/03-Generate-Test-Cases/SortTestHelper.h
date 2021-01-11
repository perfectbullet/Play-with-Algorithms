#pragma once
#include "stdafx.h"
#ifndef INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
#define INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;


// ������n��Ԫ�ص��������,ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
int* generateRandomArray(int n, int rangeL, int rangeR);

// ��ӡarr�������������
template<typename T>
void printArray(T *arr, int n) {

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return;
}



#endif //INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H