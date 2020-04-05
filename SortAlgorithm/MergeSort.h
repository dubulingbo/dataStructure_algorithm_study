#pragma once

#ifndef SORT_ALGORITHM_MERGE_SORT_H
#define SORT_ALGORITHM_MERGE_SORT_H

#include<algorithm>
#include "InsertionSort.h"

// ��������������arr[left,mid]��arr[mid+1,right]�ϲ�Ϊһ����������� 
template<typename T>
void __merge(T arr[], int left, int mid, int right) {
	T* aux = new T[right - left + 1];  //��������
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

// �����������[left,right]���еݹ�鲢����
template<typename T>
void __mergeSort(T arr[], int left, int right) {
	/*if (right <= left)
		return;*/
	//�Ż��ݹ����
	if (right - left <= 15) {
		insertionSort(arr, left, right);
		return;
	}
	int mid = (left + right) / 2;
	__mergeSort(arr, left, mid);
	__mergeSort(arr, mid + 1, right);

	if (arr[mid] > arr[mid + 1]) //���������м��������
		__merge(arr, left, mid, right);
}

// �ݹ�ʵ�֣��Զ�����
template<typename T>
void mergeSort(T arr[], int n) {

	__mergeSort(arr, 0, n - 1);
}

//����ʵ�֣��Ե�����
template<typename T>
void mergeSortBU(T arr[], int n) {

	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i + sz < n; i += (2 * sz))
			//��arr[i,i+sz-1] �� [i+sz,i+sz+sz-1] ���й鲢
			__merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1));
	}
}
#endif // !SORT_ALGORITHM_MERGE_SORT_H