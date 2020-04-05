#ifndef PRIMMST_H
#define PRIMMST_H
#include<iostream>
#include<vector>
#include "IndexMinHeap.h"
#include "Edge.h"

template<typename Graph, typename Weight>
class PrimMST {
private:
	Graph& G;
	IndexMinHeap<Weight> ipq;
	std::vector<Edge<Weight>* > edgeTo;
	bool* marked;
	std::vector<Edge<Weight>> mst;
	Weight mstWeight;

	void visit(int v) {
		assert(!marked[v]);
		marked[v] = true;

		typename Graph::adjIterator adj(G, v);  //使用邻边迭代器
		for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
			int w = e->other(v);
			if (!marked[w]) {
				if (!edgeTo[w]) {
					ipq.insert(w, e->wt());
					edgeTo[w] = e;
				}
				else if (e->wt() < edgeTo[w]->wt()) {
					edgeTo[w] = e;
					ipq.change(w, e->wt());
				}
			}
		}
	}
public:
	PrimMST(Graph& graph) :G(graph), ipq(IndexMinHeap<Weight>(graph.V())) {
		marked = new bool[G.V()];
		for (int i = 0; i < G.V(); ++i) {
			marked[i] = false;
			edgeTo.push_back(NULL);
		}
		mst.clear();

		// Prim
		visit(0);
		while (!ipq.isEmpty()) {
			int v = ipq.extractMinIndex();
			assert(edgeTo[v]);
			mst.push_back(*edgeTo[v]);
			visit(v);
		}

		//求最小权值的总和
		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size(); ++i)
			mstWeight += mst[i].wt();
	}

	~PrimMST() {
		delete[] marked;
	}

	std::vector<Edge<Weight>> mstEdges() { return mst; }

	Weight result() { return mstWeight; }

};
#endif // !PRIMMST_H

