#include <iostream>
#include <algorithm>
#include <string>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main() {
    int n = 100000;

    // 测试1 一般测试
    cout << "Test for Random Array, size = " << n << ", random range [0, " <<
    n << "]" << endl; 
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
    SortTestHelper::testSort("Quick Sort rand", quickSort_rand, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    // 测试2 测试近乎有序的数组
    int swapTimes = 10;
    cout << endl
         << "Test for Random Nearly Ordered Array, size = " << n
         << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort Rand", quickSort_rand, arr2, n);
    delete[] arr1;
    delete[] arr2;

    //// 测试3 测试完全有序的数组
    //// 对于完全有序的数组，冒泡排序法也将成为O(n)级别的算法
    // swapTimes = 0;
    // n = 10000000;    //
    // 由于插入排序法和冒泡排序法在完全有序的情况下都将成为O(n)算法
    //// 所以我们的测试数据规模变大，为1000,0000
    // cout << endl << "Test for ordered array, size = " << n << endl;
    // arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    // arr2 = SortTestHelper::copyIntArray(arr1, n);
    // arr3 = SortTestHelper::copyIntArray(arr1, n);
    // SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    // SortTestHelper::testSort("Bubble Sort 1", bubbleSort1, arr2, n);
    // SortTestHelper::testSort("Bubble Sort 2", bubbleSort2, arr3, n);
    // delete[] arr1;
    // delete[] arr2;
    // delete[] arr3;

    return 0;
}

