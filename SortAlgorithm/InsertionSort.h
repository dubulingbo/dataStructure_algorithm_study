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

        //Ѱ��Ԫ��arr[i]���ʵĲ���λ��
//        for(int j=i;j>0 && arr[j] < arr[j-1];--j) {
//            swap(arr[j], arr[j-1]);
//        }

        //�Ľ��㷨����Ҫʱ���������������˸�ֵ������һ��������������ڽ��������θ�ֵ������
        T e = arr[i];
        int j;
        for (j = i; j > 0 && e < arr[j - 1]; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;

    }

}

//��arr[left,right]��Χ��������в�������
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
