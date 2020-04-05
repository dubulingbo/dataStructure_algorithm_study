//
// Created by DubLBo on 2020/2/27.
//

#ifndef GRAPH_SPARSE_GRAPH_H
#define GRAPH_SPARSE_GRAPH_H

#include<iostream>
#include<cassert>
#include<vector>

class SparseGraph {
private:
    int n, m;
    bool directed;
    std::vector<std::vector<int>> g;

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        /*for(int i=0;i<n;++i)
            g.push_back(std::vector<int>());*/
        // g鍒濆鍖栦负n涓┖鐨剉ector, 琛ㄧず姣忎竴涓猤[i]閮戒负绌�, 鍗虫病鏈変换鍜岃竟
        g = std::vector<std::vector<int>>(n, std::vector<int>());
    }

    ~SparseGraph() {}

    int V() { return n; }

    int E() { return m; }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);


        g[v].push_back(w);
        if (v != w && !directed) g[w].push_back(v);

        ++m;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] == w) {
                return true;
            }
        }
        return false;
    }

    void show(){
        for(int i=0;i<n;++i){
            std::cout<<"vertex "<<i<<":\t";
            for(int j=0;j<g[i].size();++j){
                std::cout<<g[i][j]<<"\t";
            }
            std::cout<<std::endl;
        }
    }

    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = 0;
        }

        ~adjIterator() {}

        int begin() {
            index = 0;
            if (G.g[v].size()) {
                return G.g[v][index];
            }
            return -1;
        }

        int next() {
            ++index;
            if (index < G.g[v].size()) {
                return G.g[v][index];
            }
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }

    };

};

#endif //GRAPH_SPARSE_GRAPH_H
