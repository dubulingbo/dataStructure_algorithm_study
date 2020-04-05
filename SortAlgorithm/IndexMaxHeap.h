//
// Created by DubLBo on 2020/2/15.
//

#ifndef SORT_ALGORITHM_INDEX_MAX_HEAP_H
#define SORT_ALGORITHM_INDEX_MAX_HEAP_H

#include<iostream>
#include<algorithm>
#include<cassert>
#include<ctime>

// 最大索引堆（解决元素比较复杂，要交换两个元素可能需要消耗大量的系统资源）
// 节点 data 域存放的是真实元素的索引
// 其他性质与最大堆一样
template<typename Item>
class IndexMaxHeap {
private :
    Item *data;
    int *indexes;
    // reverses[i] 表示索引 i 在indexes（堆）中的位置；reverses[indexes[i]] = i; 和indexes[reverses[i]] = i
    int *reverses;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
            std::swap(indexes[k / 2], indexes[k]);
            reverses[indexes[k / 2]] = k / 2;
            reverses[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k;  //在此轮循环中，indexes[j]和indexes[k]交换位置
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
                ++j;

            if (data[indexes[k]] >= data[indexes[j]])
                break;

            std::swap(indexes[k], indexes[j]);
            reverses[indexes[k]] = k;
            reverses[indexes[j]] = j;

            k = j;
        }
    }

public :
    IndexMaxHeap(int capacity) {
        this->capacity = capacity;
        data = new Item[this->capacity + 1];
        indexes = new int[this->capacity + 1];
        reverses = new int[this->capacity + 1];
        count = 0;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverses;
    }

    int size() { return count; }

    bool isEmpty() { return count == 0; }

    // 传入的 i 对用户而言，是从 0 开始索引的
    void insert(const Item &item, int i) {
        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);


        ++i;
        data[i] = item;
        indexes[count + 1] = i;
        reverses[i] = count + 1;

        ++count;
        shiftUp(count);
    }

    // 返回最大元素
    const Item extractMax() {
        assert(count > 0);

        Item ret = data[indexes[1]];

        std::swap(indexes[1], indexes[count]);
        reverses[indexes[1]] = 1;
        reverses[indexes[count]] = 0;  //等于零相对与该元素已删除，即索引的位置不存在

        --count;
        shiftDown(1);
        return ret;
    }

    // 返回最大元素的索引
    const int extractMaxIndex() {
        assert(count > 0);

        int retIndex = indexes[1] - 1;
        std::swap(indexes[1], indexes[count]);
        --count;
        shiftDown(1);

        return retIndex;
    }

    // 判断data[i+1]是不是堆中的元素
    bool contain(int i) {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return reverses[i + 1] != 0;
    }

    Item getItem(int i) {
        assert(contain(i));
        return data[i + 1];
    }


    void change(int i, Item newItem) {

        assert(contain(i)); // 保证data[i+1]是堆的元素
        ++i;
        data[i] = newItem;

        // 找到 indexes[j]=i , j 表示 data[i] 在堆中的位置
        // 之后再 shiftUp(j) , 再 shiftDown(j)

        /*
        // 时间复杂度 O(n)
        for (int j = 1; j <= count; ++j) {
            if (indexes[j] == i) {
                shiftUp(j);
                shiftDown(j);
                return;
            }
        }
        */
        int j = reverses[i];  //时间复杂都O(1)
        shiftUp(j);
        shiftDown(j);
    }
};

#endif //SORT_ALGORITHM_INDEX_MAX_HEAP_H