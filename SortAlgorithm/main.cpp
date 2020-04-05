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

    // ����1 һ�����
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

    // ����2 ���Խ������������
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

    //// ����3 ������ȫ���������
    //// ������ȫ��������飬ð������Ҳ����ΪO(n)������㷨
    // swapTimes = 0;
    // n = 10000000;    //
    // ���ڲ������򷨺�ð����������ȫ���������¶�����ΪO(n)�㷨
    //// �������ǵĲ������ݹ�ģ���Ϊ1000,0000
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

