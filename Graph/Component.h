//
// Created by Administrator on 2020/2/27 0027.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include<iostream>
#include<cassert>
// 计算连通分量
template<typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int *id;
    int _count;

    void dfs(int v) {
        visited[v] = true;
        id[v] = _count;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i])
                dfs(i);
        }
    }

public:
    Component(Graph &graph) : G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        _count = 0;
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            id[i] = -1;
        }

        for (int i = 0; i < G.V(); ++i) {
            if (!visited[i]) {
                dfs(i);
                ++_count;
            }
        }
    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() { return _count; }

    bool isConnected(int p, int q) {
        assert(p >= 0 && p < G.V());
        assert(q >= 0 && q < G.V());
        return id[p] == id[q];
    }

    void showIdArr(){
        for(int i=0;i<G.V();++i){
            std::cout<<id[i]<<" ";
        }
        std::cout<<std::endl;
    }

};

#endif //GRAPH_COMPONENT_H
