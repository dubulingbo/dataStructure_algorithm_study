//
// Created by DubLBo on 2020/2/27.
//

#ifndef UNION_FIND_UNION_FIND4_H
#define UNION_FIND_UNION_FIND4_H

#include<cassert>
#include<iostream>

// 基于rank的优化 : 是每个并操作得到的树层数最少，这样可以减少查操作的耗时
namespace UF4 {
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
            while (p != parent[p])
                p = parent[p];
            return p;
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

#endif //UNION_FIND_UNION_FIND4_H
