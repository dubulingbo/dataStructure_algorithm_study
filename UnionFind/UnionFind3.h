//
// Created by DubLBo on 2020/2/27.
//

#ifndef UNION_FIND_UNION_FIND3_H
#define UNION_FIND_UNION_FIND3_H

#include<cassert>
#include<iostream>

// 基于size的优化 : 优化根的个数，总是将元素个数较少的根节点修改为较多元素的根节点
namespace UF3 {
    class UnionFind {
    private:
        int *parent;
        int *sz;      // sz[i] 表示以 i 为根的集合中的元素个数
        int count;
    public:
        UnionFind(int n) {
            parent = new int[n];
            sz = new int[n];
            count = n;
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                sz[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] sz;
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

            if (sz[pRoot] < sz[qRoot]) {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            } else {
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }

        }
    };
}

#endif //UNION_FIND_UNION_FIND3_H
