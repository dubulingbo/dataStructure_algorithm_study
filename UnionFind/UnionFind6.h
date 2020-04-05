//
// Created by DubLBo on 2020/2/27.
//

#ifndef UNION_FIND_UNION_FIND6_H
#define UNION_FIND_UNION_FIND6_H

#include<cassert>
#include<iostream>

// 基于路径压缩的优化 : 主要是针对查操作的优化，使查操作后的每棵树只有两层，（递归实现）
namespace UF6 {
    class UnionFind {
    private:
        int *parent;
        int *rank;      // rank[i] 表示以 i 为根的集合所表示的树的层数
        int count;
    public:
        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            count = n;
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
//            while(p != parent[p]){
//                parent[p] = parent[parent[p]];  //将p节点的父亲指向它的父亲的父亲，减少了层数，即减少查操作的时间
//                p = parent[p];
//            }

            if (p != parent[p])
                parent[p] = find(parent[p]);  //递归可能需要耗费时间
            return parent[p];
        }

        bool isConnected(int p, int q) { return find(p) == find(q); }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot)
                return;

            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else if (rank[pRoot] > rank[qRoot]) {
                parent[qRoot] = pRoot;
            } else { // rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                ++rank[qRoot];
            }

        }
    };
}

#endif //UNION_FIND_UNION_FIND6_H
