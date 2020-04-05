//
// Created by DubLBo on 2020/2/27.
//

#ifndef UNION_FIND_UNION_FIND2_H
#define UNION_FIND_UNION_FIND2_H

#include<cassert>
#include<iostream>

namespace UF2 {
    class UnionFind {
    private:
        int *parent;  // parent[i] 表示 i 节点的父亲节点
        int count;
    public:
        UnionFind(int n) {
            parent = new int[n];
            count = n;
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }

        ~UnionFind() {
            delete[] parent;
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

            parent[pRoot] = qRoot;
        }
    };
}

#endif //UNION_FIND_UNION_FIND2_H
