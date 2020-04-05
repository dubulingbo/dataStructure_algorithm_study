#pragma once

//
// Created by DubLBo on 2020/2/7.
//

#ifndef SORT_ALGORITHM_SELECTION_SORT_H
#define SORT_ALGORITHM_SELECTION_SORT_H

#include<algorithm>
//ʹ��ģ�庯�����
template<typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n - 1; ++i) {

        int minIndex = i;
        //Ѱ��[i,n)���������Сֵ������
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
#endif //SORT_ALGORITHM_SELECTION_SORT_H
