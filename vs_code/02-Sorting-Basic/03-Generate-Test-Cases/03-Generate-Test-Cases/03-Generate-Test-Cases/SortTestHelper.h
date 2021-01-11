#pragma once
#include "stdafx.h"
#ifndef INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
#define INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;


// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
int* generateRandomArray(int n, int rangeL, int rangeR);

// 打印arr数组的所有内容
template<typename T>
void printArray(T *arr, int n) {

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return;
}



#endif //INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H