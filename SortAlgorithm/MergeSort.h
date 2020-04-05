#pragma once

#ifndef SORT_ALGORITHM_MERGE_SORT_H
#define SORT_ALGORITHM_MERGE_SORT_H

#include<algorithm>
#include "InsertionSort.h"

// 将两个有序区间arr[left,mid]与arr[mid+1,right]合并为一个有序的区间 
template<typename T>
void __merge(T arr[], int left, int mid, int right) {
	T* aux = new T[right - left + 1];  //辅助数组
	for (int i = left; i <= right; ++i) {
		aux[i - left] = arr[i];
	}

	int i = left, j = mid + 1;
	for (int k = left; k <= right; ++k) {
		if (i > mid) {
			arr[k] = aux[j - left];
			++j;
		}
		else if (j > right) {
			arr[k] = aux[i - left];
			++i;
		}
		else if (aux[i - left] < aux[j - left]) {
			arr[k] = aux[i - left];
			++i;
		}
		else {
			arr[k] = aux[j - left];
			++j;
		}
	}
	delete[] aux;
}

// 将数组的区间[left,right]进行递归归并排序
template<typename T>
void __mergeSort(T arr[], int left, int right) {
	/*if (right <= left)
		return;*/
	//优化递归出口
	if (right - left <= 15) {
		insertionSort(arr, left, right);
		return;
	}
	int mid = (left + right) / 2;
	__mergeSort(arr, left, mid);
	__mergeSort(arr, mid + 1, right);

	if (arr[mid] > arr[mid + 1]) //若两个序列间存在逆序
		__merge(arr, left, mid, right);
}

// 递归实现：自顶向下
template<typename T>
void mergeSort(T arr[], int n) {

	__mergeSort(arr, 0, n - 1);
}

//迭代实现：自底向上
template<typename T>
void mergeSortBU(T arr[], int n) {

	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i + sz < n; i += (2 * sz))
			//对arr[i,i+sz-1] 和 [i+sz,i+sz+sz-1] 进行归并
			__merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1));
	}
}
#endif // !SORT_ALGORITHM_MERGE_SORT_H