//
// Created by DubLBo on 2020/2/27.
//

#ifndef GRAPH_DENSE_GRAPH_H
#define GRAPH_DENSE_GRAPH_H

#include <iostream>
#include <cassert>
#include <vector>

// 稠密图 - 邻接矩阵
class DenseGraph {
  private:
    int n, m;
    bool directed;
    std::vector<std::vector<bool>> g;

  public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i)
            g.push_back(std::vector<bool>(n, false));
    }

    ~DenseGraph() {}

    int V() { return n; }

    int E() { return m; }

    void addEdge(int v, int w) {
        /*assert(v>=0 && v<n);
        assert(w>=0 && w<n);*/

        if (hasEdge(v, w))
            return;

        g[v][w] = true;
        if (!directed)
            g[w][v] = true; //无向图还需赋值 (w,v) = true;

        ++m;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

    void show() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << g[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    class adjIterator {
      private:
        DenseGraph &G;
        int v;
        int index;

      public:
        adjIterator(DenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = -1;
        }

        ~adjIterator() {}

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            for (index += 1; index < G.V(); ++index) {
                if (G.g[v][index]) {
                    return index;
                }
            }
            return -1;
        }

        bool end() { return index >= G.V(); }
    };
};

#endif // GRAPH_DENSE_GRAPH_H
