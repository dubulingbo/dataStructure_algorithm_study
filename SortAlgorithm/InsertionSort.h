#pragma once
//
// Created by DubLBo on 2020/2/7.
//

#ifndef SORT_ALGORITHM_INSERTION_SORT_H
#define SORT_ALGORITHM_INSERTION_SORT_H
#include<algorithm>

template<typename T>
void insertionSort(T arr[], int n) {

    for (int i = 1; i < n; ++i) {

        //寻找元素arr[i]合适的插入位置
//        for(int j=i;j>0 && arr[j] < arr[j-1];--j) {
//            swap(arr[j], arr[j-1]);
//        }

        //改进算法，主要时将交换操作换成了赋值操作（一个交换操作相等于进行了三次赋值操作）
        T e = arr[i];
        int j;
        for (j = i; j > 0 && e < arr[j - 1]; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;

    }

}

//对arr[left,right]范围的数组进行插入排序
template<typename T>
void insertionSort(T arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > left&& arr[j - 1] > e; --j)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
    return;
}

#endif //SORT_ALGORITHM_INSERTION_SORT_H
