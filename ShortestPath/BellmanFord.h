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

		// Bellman-Ford �㷨
		distTo[s] = Weight();
		for (int pass = 1; pass < G.V(); ++pass) {

			// Relaxation
			for (int i = 0; i < G.V(); ++i) {
				typename Graph::adjIterator adj(G, i);
				for(Edge<Weight>* e = adj.begin();!adj.end();e = adj.next())
					// ����ÿһ���������ж� e->v() �ɴ�
					// ֮����� e->w() ��ǰû�е������ ��Ȼ���ǿ��Ը��� distTo[e->w()]
					// ���� e->w() ��ǰ��Ȼ�����, ����ͨ����� e ���ǿ��Ի��һ�����̵ľ���, �����Խ���һ���ɳڲ���, ����Ҳ���Ը��� distTo[e->w()]
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
		s.push(e);  //����ʼ��ѹջ

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

