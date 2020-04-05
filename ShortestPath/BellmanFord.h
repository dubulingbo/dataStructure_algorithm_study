#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

template<typename Graph, typename Weight>
class BellmanFord {
private:
	Graph& G;
	int s;
	Weight* distTo;
	std::vector<Edge<Weight>*> from;
	bool hasNegativeCycle;

	bool detectNegativeCycle() {
		for (int i = 0; i < G.V(); ++i) {
			typename Graph::adjIterator adj(G, i);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
				if (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()])
					return true;	
		}
		return false;
	}

public:
	BellmanFord(Graph& graph, int s) :G(graph) {
		this->s = s;
		distTo = new Weight[G.V()];
		for (int i = 0; i < G.V(); ++i) {
			from.push_back(NULL);
		}

		// Bellman-Ford 算法
		distTo[s] = Weight();
		for (int pass = 1; pass < G.V(); ++pass) {

			// Relaxation
			for (int i = 0; i < G.V(); ++i) {
				typename Graph::adjIterator adj(G, i);
				for(Edge<Weight>* e = adj.begin();!adj.end();e = adj.next())
					// 对于每一个边首先判断 e->v() 可达
					// 之后看如果 e->w() 以前没有到达过， 显然我们可以更新 distTo[e->w()]
					// 或者 e->w() 以前虽然到达过, 但是通过这个 e 我们可以获得一个更短的距离, 即可以进行一次松弛操作, 我们也可以更新 distTo[e->w()]
					if (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()]) {
						distTo[e->w()] = distTo[e->v()] + e->wt();
						from[e->w()] = e;
					}
			}
		}

		hasNegativeCycle = detectNegativeCycle();
	}

	~BellmanFord() {
		delete[] distTo;
	}

	bool negativeCycle() {
		return hasNegativeCycle;
	}

	Weight shortestPathTo(int w) {
		assert(w >= 0 && w < G.V());
		assert(!hasNegativeCycle);
		return distTo[w];
	}

	bool hasPathTo(int w) {
		assert(w >= 0 && w < G.V());
		return from[w] != NULL;
	}

	void shortestPath(int w, std::vector<Edge<Weight>>& vec) {
		assert(w >= 0 && w < G.V());
		assert(!hasNegativeCycle);

		std::stack<Edge<Weight>*> s;
		Edge<Weight>* e = from[w];
		while (e->v() != this->s) {
			s.push(e);
			e = from[e->v()];
		}
		s.push(e);  //将起始点压栈

		while (!s.empty()) {
			e = s.top();
			vec.push_back(*e);
			s.pop();
		}
	}

	void showPath(int w) {
		assert(w >= 0 && w < G.V());
		assert(!hasNegativeCycle);

		std::vector<Edge<Weight>> vec;
		shortestPath(w, vec);
		for (int i = 0; i < vec.size(); ++i) {
			std::cout << vec[i].v() << " -> ";
			if (i + 1 == vec.size())
				std::cout << vec[i].w() << std::endl;
		}
	}
};

#endif // !BELLMANFORD_H

