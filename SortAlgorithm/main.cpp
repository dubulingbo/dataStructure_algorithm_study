#include <iostream>
#include <algorithm>
#include <string>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;

int main() {
    // int n = 100000;

    // // ����1 һ�����
    // cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
    // int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    // int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    // int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    // SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    // SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
    // SortTestHelper::testSort("Quick Sort rand", quickSort_rand, arr3, n);

    // delete[] arr1;
    // delete[] arr2;
    // delete[] arr3;

    // // ����2 ���Խ������������
    // int swapTimes = 10;
    // cout << endl
    //      << "Test for Random Nearly Ordered Array, size = " << n
    //      << ", swap time = " << swapTimes << endl;
    // arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    // arr2 = SortTestHelper::copyIntArray(arr1, n);

    // SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    // SortTestHelper::testSort("Quick Sort Rand", quickSort_rand, arr2, n);
    // delete[] arr1;
    // delete[] arr2;

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

    int n = 1000000;
    int swapTimes = 100;

    // ����1 һ�����
    cout << "Test for Random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort3, arr3, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;

    // ����2 ���Խ������������

    cout << "Test for Nearly Ordered array, size = " << n
         << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort3, arr3, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;

    // ����3 �����д����ظ�Ԫ�ص�����
    cout << "Test for Random array, size = " << n << ", random range [0,10]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort3, arr3, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;

    MaxHeap<int> mh = MaxHeap<int>(100);
    int arr[] = {43, 53, 72, 39, 10, 18, 62, 63, 66, 29};
    for (int i = 0; i < 10; ++i) {
        mh.insert(arr[i]);
    }
    cout << endl;
    mh.print();

    system("pause");

    return 0;
}
