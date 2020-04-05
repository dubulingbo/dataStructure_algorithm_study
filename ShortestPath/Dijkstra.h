#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

// 不能处理负权边
template<typename Graph, typename Weight>
class Dijkstra {
private:
	Graph& G;
	int s;
	Weight* distTo;
	bool* marked;
	std::vector<Edge<Weight>*> from;
public:
	Dijkstra(Graph& graph, int s) :G(graph) {
		this->s = s;
		distTo = new Weight[G.V()];
		marked = new bool[G.V()];
		for (int i = 0; i < G.V(); ++i) {
			distTo[i] = Weight();
			marked[i] = false;
			from.push_back(NULL);
		}

		IndexMinHeap<Weight> ipq(G.V());

		// Dijkstra 算法开始
		// 对于起始点 s 进行初始化
		distTo[s] = Weight();
		from[s] = new Edge<Weight>(s, s, Weight());
		marked[s] = true;
		ipq.insert(s, distTo[s]);
		while (!ipq.isEmpty()) {
			int v = ipq.extractMinIndex();

			// distTo[v] 就是 s 到 v 的最短距离
			marked[v] = true;

			// Relaxation 松弛操作
			// 对 v 的所有相邻节点进行更新
			typename Graph::adjIterator adj(G, v);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
				int w = e->other(v);
				// 如果从 s 点到 w 点的最短路径还没有找到
				if (!marked[w]) {
					// 如果 w 点没有访问过 || 访问过, 但是通过当前的 v 点到 w 点距离更短, 则进行更新
					if (from[w] == NULL || distTo[v] + e->wt() < distTo[w]) {
						distTo[w] = distTo[v] + e->wt();
						from[w] = e;
						if (ipq.contain(w))
							ipq.change(w, distTo[w]);
						else
							ipq.insert(w, distTo[w]);
					}
				}
			}
		}
	}

	~Dijkstra() {
		delete from[this->s];
		delete[] distTo;
		delete[] marked;

	}

	// 返回从 s 点到 w 点的最短路径长度
	Weight shortestPathTo(int w) {
		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));
		return distTo[w];
	}

	// 判断从 s 点到 w 点是否连通
	bool hasPathTo(int w) {
		assert(w >= 0 && w < G.V());
		return marked[w];
	}
	// 寻找从 s 到 w 的最短路径, 将整个路径经过的边存放在vec中
	void shortestPath(int w, std::vector<Edge<Weight>>& vec) {

		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));

		// 通过 from 数组逆向查找到从 s 到 w 的路径, 存放到栈中
		std::stack<Edge<Weight>*> s;
		Edge<Weight>* e = from[w];
		while (e->v() != this->s) {
			s.push(e);
			e = from[e->v()];
		}
		s.push(e);

		// 从栈中依次取出元素, 获得顺序的从 s 到 w 的路径
		while (!s.empty()) {
			e = s.top();
			vec.push_back(*e);
			s.pop();
		}
	}

	// 打印出从 s 点到 w 点的路径
	void showPath(int w) {

		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));

		std::vector<Edge<Weight>> vec;
		shortestPath(w, vec);
		for (int i = 0; i < vec.size(); ++i) {
			std::cout << vec[i].v() << " -> ";
			if (i + 1 == vec.size())
				std::cout << vec[i].w() << std::endl;
		}
	}

};

#endif // !DIJKSTRA_H

