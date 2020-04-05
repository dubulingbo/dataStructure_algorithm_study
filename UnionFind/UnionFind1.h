//
// Created by DubLBo on 2020/2/27.
//

#ifndef UNION_FIND_UNION_FIND1_H
#define UNION_FIND_UNION_FIND1_H

#include<cassert>
#include<iostream>

namespace UF1 {
    class UnionFind {
    private:
        int *id;
        int count;
    public:
        UnionFind(int n) {
            id = new int[n];
            count = n;
            for (int i = 0; i < n; ++i)
                id[i] = i;
        }

        ~UnionFind() {
            delete[] id;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            return id[p];
        }

        bool isConnected(int p, int q) { return find(p) == find(q); }

        void unionElements(int p, int q) {
            int pID = find(p);
            int qID = find(q);
            if (pID == qID)
                return;

            for (int i = 0; i < count; ++i)
                if (id[i] == pID)
                    id[i] = qID;
        }
    };
}

#endif //UNION_FIND_UNION_FIND1_H
