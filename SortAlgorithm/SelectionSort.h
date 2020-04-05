#pragma once

//
// Created by DubLBo on 2020/2/7.
//

#ifndef SORT_ALGORITHM_SELECTION_SORT_H
#define SORT_ALGORITHM_SELECTION_SORT_H

#include<algorithm>
//使用模板函数编程
template<typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n - 1; ++i) {

        int minIndex = i;
        //寻找[i,n)区间里的最小值的索引
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
#endif //SORT_ALGORITHM_SELECTION_SORT_H
