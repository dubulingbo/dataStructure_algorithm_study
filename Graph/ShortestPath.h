//
// Created by Administrator on 2020/2/27 0027.
//

#ifndef GRAPH_SHORTEST_PATH_H
#define GRAPH_SHORTEST_PATH_H

#include<iostream>
#include<queue>
#include<cassert>
#include<vector>
#include<stack>

template<typename Graph>
class ShortestPath {
private:
    Graph &G;
    int s;
    bool *visited;
    int *from;
    int *ord;  // 记录从s到每个节点的最短距离

    void bfs(int st) {
        std::queue<int> q;
        q.push(st);
        visited[st] = true;
        ord[st] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            typename Graph::adjIterator adj(G, v);
            for (int i = adj.begin(); !adj.end() && !visited[i]; i = adj.next()) {
                q.push(i);
                visited[i] = true;
                from[i] = v;
                ord[i] = ord[v] + 1;
            }
        }
    }

public:
    ShortestPath(Graph &graph, int s) : G(graph) {
        // 算法初始化
        assert(s >= 0 && s < G.V());

        visited = new bool[G.V()];
        from = new int[G.V()];
        ord = new int[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        this->s = s;

        // 无向图最短路径算法 - 广度优先搜索
        bfs(s);
    }

    ~ShortestPath() {
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, std::vector<int> &vec) {
        assert(w >= 0 && w < G.V());

        std::stack<int> s;
        int p = w;
        while (p != -1) {
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }

    }

    void showPath(int w) {
        assert(w >= 0 && w < G.V());

        std::vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i == vec.size() - 1)
                std::cout << std::endl;
            else
                std::cout << "-->";
        }
    }

    int length(int w) {
        assert(w >= 0 && w < G.V());
        return ord[w];
    }
};


#endif //GRAPH_SHORTEST_PATH_H
