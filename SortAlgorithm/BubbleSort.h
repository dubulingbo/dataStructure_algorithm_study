#pragma once
//
// Created by DubLBo on 2020/2/8.
//

#ifndef SORT_ALGORITHM_BUBBLE_SORT_H
#define SORT_ALGORITHM_BUBBLE_SORT_H

#include <algorithm>

template<typename T>
void bubbleSort1(T arr[], int n) {

    //�汾һ
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
    //�汾�����Ż�֮���
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
    for (int i = 1; i < n; ++i) {  //ѭ��n-1��
        bool flag = true;  //����Ѿ�����
        // ÿһ�˶���ʹ��ǰ��С��Ԫ������ð������Ԫ�����³�
        for (int j = n - 1; j >= i; --j) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                flag = false;
            }
        }
        if (flag) //�Ѿ�������ֹѭ��
            break;
    }
}


#endif //SORT_ALGORITHM_BUBBLE_SORT_H
