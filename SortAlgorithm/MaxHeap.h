//
// Created by DubLBo on 2020/2/15.
//

#ifndef SORT_ALGORITHM_MAX_HEAP_H
#define SORT_ALGORITHM_MAX_HEAP_H

#include <cassert>
#include<iostream>
#include<algorithm>

// 大顶堆（也叫最大堆）
// 1.堆中任何一个节点的值都不大于其父节点的值
// 2.必须是完全二叉树（可以采用数组存储）
template<typename Item>
class MaxHeap {
private :
    Item *data;
    int count;
    int _capacity;

    // 调整索引位置k，使其保持最大堆的性质
    void shiftUp(int k) {
        while (k > 1 && data[k / 2] < data[k]) {
            std::swap(data[k / 2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {  //只要有左孩子，就是有孩子
            int j = 2 * k;  //在此轮循环中，data[k]和data[j]可能交换位置
            if (j + 1 <= count && data[j + 1] > data[j])
                j += 1;

            if (data[k] >= data[j])
                break;
            std::swap(data[k], data[j]);
            k = j;
        }
    }

public :
    void print() {
        for (int i = 1; i <= count; ++i)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    MaxHeap(int capacity) {
        this->_capacity = capacity;
        data = new Item[this->_capacity + 1];
        count = 0;
    }

    MaxHeap(Item arr[],int n){
        this->_capacity = n;
        data = new Item[_capacity+1];

        for(int i=1;i<=n;++i)
            data[i] = arr[i-1];
        count = n;

        for(int i = count/2;i>=1;--i)
            shiftDown(i);
    }

    ~MaxHeap() {
        delete[] data;
    }

    bool isEmpty() {
        return count <= 0;
    }

    // 返回堆中元素的个数
    int size() {
        return count;
    }

    //返回开辟的空间数量
    int capacity() {
        return _capacity;
    }

    //插入一个元素，并调整使堆继续保持最大堆的性质
    void insert(const Item &item) {
        assert(count + 1 <= capacity());
        data[count + 1] = item;
        ++count;
        shiftUp(count);
    }

    // 从堆中取出一个元素
    Item extractMax() {
        assert(count > 0);
        Item temp = data[1];
        std::swap(data[1], data[count]);
        --count;
        shiftDown(1);
        return temp;
    }

};

#endif //SORT_ALGORITHM_MAX_HEAP_H
