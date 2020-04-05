//
// Created by DubLBo on 2020/2/15.
//

#ifndef SORT_ALGORITHM_HEAP_SORT_H
#define SORT_ALGORITHM_HEAP_SORT_H

#include <iostream>
#include<ctime>
#include "MaxHeap.h"


using namespace std;

//将n个元素逐个插入到一个空堆中，算法复杂度是O(nlogn)
template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i)
        maxHeap.insert(arr[i]);

    for (int i = n - 1; i >= 0; --i)
        arr[i] = maxHeap.extractMax();
}

// heapify 过程，算法复杂度是O(n)
template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);

    for (int i = n - 1; i >= 0; --i)
        arr[i] = maxHeap.extractMax();
}

//原地堆排序

// n : 需调整的数组arr的元素个数
template<typename T>
void __shiftDown(T arr[], int n, int k) {
    while (2 * k + 1 < n) {  //只要有左孩子，就是有孩子
        int j = 2 * k + 1;  //在此轮循环中，arr[k]和arr[j]可能交换位置
        if (j + 1 < n && arr[j + 1] > arr[j])
            ++j;


        if (arr[k] >= arr[j])
            break;
        std::swap(arr[k], arr[j]);
        k = j;
    }
}
template<typename T>
void heapSort3(T arr[], int n) {
    // heapify
    for (int i = (n - 2) / 2; i >= 0; --i)
        __shiftDown(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

#endif //SORT_ALGORITHM_HEAP_SORT_H
