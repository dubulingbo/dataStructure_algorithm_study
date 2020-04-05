/**
 * Created by DubLBo on 2020/4/5
 */

#ifndef SORT_ALGORITHM_QUICK_SORT_H
#define SORT_ALGORITHM_QUICK_SORT_H

#include<iostream>
#include<algorithm>
#include<ctime>
// 分区函数，使得arr[left,p-1]<v，arr[p+1,i)>v
template<typename T>
int __partition(T arr[], int left, int right) {
    
    //使得arr[left+1,j]<v， arr[j+1,i)>v
    T v = arr[left];
    int j = left;
    for (int i = left + 1; i <= right; ++i) {
        if (arr[i] < v) {
            std::swap(arr[j+1] , arr[i]);
            ++j;
        }
    }
    std::swap(arr[left], arr[j]);
    return j;
}

//对数组中范围 [left,right] 的元素进行快速排序
template<typename T>
void __quickSort(T arr[], int left, int right) {
    if (left >= right)
        return;
    int p = __partition(arr, left, right);

    __quickSort(arr, left, p-1);
    __quickSort(arr, p + 1, right);
}

template<typename T>
void quickSort(T arr[], int n) {

    __quickSort(arr, 0, n - 1);
}

template<typename T>
void __quickSort_rand(T arr[], int left, int right) {
    if (left >= right)
        return;

    std::swap(arr[left], arr[rand() % (right - left + 1) + left]);

    int p = __partition(arr, left, right);
    
    __quickSort(arr, left, p - 1);
    __quickSort(arr, p + 1, right);
}

template<typename T>
void quickSort_rand(T arr[], int n) {
    srand((unsigned int)time(NULL));
    __quickSort_rand(arr, 0, n - 1);
}

#endif //SORT_ALGORITHM_QUICK_SORT_H