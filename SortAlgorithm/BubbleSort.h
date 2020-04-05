#pragma once
//
// Created by DubLBo on 2020/2/8.
//

#ifndef SORT_ALGORITHM_BUBBLE_SORT_H
#define SORT_ALGORITHM_BUBBLE_SORT_H

#include <algorithm>

template<typename T>
void bubbleSort1(T arr[], int n) {

    //版本一
    bool swapped;
    do {
        swapped = false;
        for (int j = 1; j < n; ++j) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);

}

template<typename T>
void bubbleSort2(T arr[], int n) {
    //版本二：优化之后的
    int new_n;
    do {
        new_n = 0;
        for (int j = 1; j < n; ++j) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                new_n = j;
            }
        }
        n = new_n;
    } while (new_n > 0);
}



template<typename T>
void bubbleSort_my(T arr[], int n) {
    for (int i = 1; i < n; ++i) {  //循环n-1次
        bool flag = true;  //标记已经有序
        // 每一趟都能使当前最小的元素往上冒，最大的元素往下沉
        for (int j = n - 1; j >= i; --j) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                flag = false;
            }
        }
        if (flag) //已经有序，终止循环
            break;
    }
}


#endif //SORT_ALGORITHM_BUBBLE_SORT_H
