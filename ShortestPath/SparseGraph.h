//
// Created by DubLBo on 2020/2/27.
//

#ifndef GRAPH_SPARSE_GRAPH_H
#define GRAPH_SPARSE_GRAPH_H

#include<iostream>
#include<cassert>
#include<vector>
#include "Edge.h"

// 稀疏图 - 邻接表
template<typename Weight>
class SparseGraph {
private:
	int n, m;
	bool directed;
	std::vector<std::vector<Edge<Weight>* >> g;






public:
	SparseGraph(int n, bool directed) {
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; ++i)
			g.push_back(std::vector<Edge<Weight>*>());
		// g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
		// g = std::vector<std::vector< Edge<Weight> * >>(n, std::vector<Edge<Weight>*>());
	}

	~SparseGraph() {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < g[i].size(); ++j)
				delete g[i][j];
	}

	int V() { return n; }

	int E() { return m; }

	void addEdge(int v, int w, Weight weight) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);


		g[v].push_back(new Edge<Weight>(v, w, weight));
		if (v != w && !directed)
			g[w].push_back(new Edge<Weight>(w, v, weight));

		++m;
	}

	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (int i = 0; i < g[v].size(); ++i) {
			if (g[v][i]->other(v) == w) {
				return true;
			}
		}
		return false;
	}

	void show() {
		for (int i = 0; i < n; ++i) {
			std::cout << "vertex " << i << ":\t";
			for (int j = 0; j < g[i].size(); ++j) {
				std::cout << "( to:" << g[i][j]->w() << ",wt:" << g[i][j]->wt() << " )\t";
			}
			std::cout << std::endl;
		}
	}

	class adjIterator {
	private:
		SparseGraph& G;
		int v;
		int index;
	public:
		adjIterator(SparseGraph& graph, int v) : G(graph) {
			this->v = v;
			this->index = 0;
		}

		~adjIterator() {}

		Edge<Weight>* begin() {
			index = 0;
			if (G.g[v].size()) {
				return G.g[v][index];
			}
			return NULL;
		}

		Edge<Weight>* next() {
			++index;
			if (index < G.g[v].size()) {
				return G.g[v][index];
			}
			return NULL;
		}

		bool end() {
			return index >= G.g[v].size();
		}

	};

};

#endif //GRAPH_SPARSE_GRAPH_H
