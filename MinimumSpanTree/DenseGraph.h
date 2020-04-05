//
// Created by DubLBo on 2020/2/27.
//

#ifndef GRAPH_DENSE_GRAPH_H
#define GRAPH_DENSE_GRAPH_H

#include<iostream>
#include<cassert>
#include<vector>
#include "Edge.h"

// 稠密图 - 邻接矩阵
template<typename Weight>
class DenseGraph {
private:
	int n, m;
	bool directed;
	std::vector<std::vector<Edge<Weight>* >> g;
public:
	DenseGraph(int n, bool directed) {
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; ++i)
			g.push_back(std::vector<Edge<Weight>*>(n, NULL));
	}

	~DenseGraph() {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (g[i][j] != NULL)
					delete g[i][j];
	}

	int V() { return n; }

	int E() { return m; }

	void addEdge(int v, int w, Weight weight) {

		if (hasEdge(v, w)) {
			delete g[v][w];
			if (!directed)
				delete g[w][v];
			--m;
		}

		g[v][w] = new Edge<Weight>(v, w, weight);
		if (!directed) g[w][v] = new Edge<Weight>(w, v, weight);  //无向图还需赋值 (w,v) = true;

		++m;
	}

	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w] != NULL;
	}

	void show() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[i][j])
					std::cout << g[i][j]->wt() << "\t";
				else
					std::cout << "NULL\t";
			}
			std::cout << std::endl;
		}
	}

	class adjIterator {
	private:
		DenseGraph& G;
		int v;
		int index;
	public:
		adjIterator(DenseGraph& graph, int v) : G(graph) {
			this->v = v;
			this->index = -1;
		}

		~adjIterator() {}

		Edge<Weight>* begin() {
			index = -1;
			return next();
		}

		Edge<Weight>* next() {
			for (index += 1; index < G.V(); ++index) {
				if (G.g[v][index]) {
					return G.g[v][index];
				}
			}
			return NULL;
		}

		bool end() { return index >= G.V(); }
	};

};

#endif //GRAPH_DENSE_GRAPH_H
