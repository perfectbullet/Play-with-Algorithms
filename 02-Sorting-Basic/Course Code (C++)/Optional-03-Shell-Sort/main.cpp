#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include <iostream>
#include <vector>

using namespace std;


// template<typename T>
// void shellSort(T arr[], int n){

//     // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
//     int h = 1;
//     while( h < n/3 )
//         h = 3 * h + 1;

//     while( h >= 1 ){

//         // h-sort the array
//         for( int i = h ; i < n ; i ++ ){

//             // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
//             T e = arr[i];
//             int j;
//             for( j = i ; j >= h && e < arr[j-h] ; j -= h )
//                 arr[j] = arr[j-h];
//             arr[j] = e;
//         }

//         h /= 3;
//     }
// }
template<typename T>
void shellSort(T *arr, int n){
    std::vector<int> hvector;
    for(int h = n/2; h >= 1; h = h/2){
        // 先得到步长序列 [h1, h2, h3, .... hn]，每次在做插入排序时， 
        // 插入排序的元素和他前面的第 h 个元素做比较 
        // hvector.push_back(h);
        for(int i = h; i < n; i++){
            // 从 arr[0+h] 开始， 和 arr[0] 比较
            // arr[1+h] 和 arr[1]
            // arr[2+h] 和 arr[2]
            // arr[i+h]  和 arr[i]
            int j;
            T e = arr[i];
            for(j = i; j > 0 && e < arr[j-h]; j -= h){
                // 考察 arr[i+h] 即 arr[j] 应该插入的位置
                arr[j] = arr[j-h];
            }
            arr[j] = e;
        }
    }
    
}
// 比较SelectionSort, InsertionSort和BubbleSort和ShellSort四种排序算法的性能效率
// ShellSort是这四种排序算法中性能最优的排序算法
int main() {

    int n = 200;

    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;

    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;

    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;

    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}