#pragma once
//
// Created by DubLBo on 2020/2/7.
//

#ifndef SORT_ALGORITHM_SORT_TEST_HELPER_H
#define SORT_ALGORITHM_SORT_TEST_HELPER_H

#include<iostream>
#include<algorithm>
#include<ctime>
#include<cassert>
#include<string>
#include<iomanip>

namespace SortTestHelper {
    int* generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        //生成有n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
        int* arr = new int[n];
        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    int* generateNearlyOrderedArray(int n, int swapTimes) {
        int* arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = i;
        srand((unsigned int)time(NULL));
        for (int i = 0; i < swapTimes; ++i) {
            int px = rand() % n;
            int py = rand() % n;
            std::swap(arr[px], arr[py]);
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {

        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {

        for (int i = 0; i < n - 1; ++i)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

    template<typename T>
    void testSort(const std::string& sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));

        std::cout << sortName << " : " << setiosflags(std::ios::fixed) << std::setprecision(7)
            << ((double)endTime - (double)startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }

    int* copyIntArray(int a[], int n) {
        int* arr = new int[n];
        std::copy(a, a + n, arr);
        return arr;
    }
}
#endif //SORT_ALGORITHM_SORT_TEST_HELPER_H
