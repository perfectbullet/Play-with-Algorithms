#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

template<typename T>
void insertionSort(T *arr, int n){

    for(int i = 0 ; i < n ; i ++){
        for(int j = i + 1; j > 0 && arr[j] < arr[j-1]; j--){
            swap( arr[j] , arr[j - 1] );
        }
    }
    return;
}

int main() {

    int n = 20000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);

    SortTestHelper::testSort("insertion Sort", insertionSort, arr2, n);
    delete[] arr;
    delete[] arr2;

    return 0;
}