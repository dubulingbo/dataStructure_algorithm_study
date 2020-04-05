#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

// ���ܴ���Ȩ��
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

		// Dijkstra �㷨��ʼ
		// ������ʼ�� s ���г�ʼ��
		distTo[s] = Weight();
		from[s] = new Edge<Weight>(s, s, Weight());
		marked[s] = true;
		ipq.insert(s, distTo[s]);
		while (!ipq.isEmpty()) {
			int v = ipq.extractMinIndex();

			// distTo[v] ���� s �� v ����̾���
			marked[v] = true;

			// Relaxation �ɳڲ���
			// �� v ���������ڽڵ���и���
			typename Graph::adjIterator adj(G, v);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
				int w = e->other(v);
				// ����� s �㵽 w ������·����û���ҵ�
				if (!marked[w]) {
					// ��� w ��û�з��ʹ� || ���ʹ�, ����ͨ����ǰ�� v �㵽 w ��������, ����и���
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

	// ���ش� s �㵽 w ������·������
	Weight shortestPathTo(int w) {
		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));
		return distTo[w];
	}

	// �жϴ� s �㵽 w ���Ƿ���ͨ
	bool hasPathTo(int w) {
		assert(w >= 0 && w < G.V());
		return marked[w];
	}
	// Ѱ�Ҵ� s �� w �����·��, ������·�������ıߴ����vec��
	void shortestPath(int w, std::vector<Edge<Weight>>& vec) {

		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));

		// ͨ�� from ����������ҵ��� s �� w ��·��, ��ŵ�ջ��
		std::stack<Edge<Weight>*> s;
		Edge<Weight>* e = from[w];
		while (e->v() != this->s) {
			s.push(e);
			e = from[e->v()];
		}
		s.push(e);

		// ��ջ������ȡ��Ԫ��, ���˳��Ĵ� s �� w ��·��
		while (!s.empty()) {
			e = s.top();
			vec.push_back(*e);
			s.pop();
		}
	}

	// ��ӡ���� s �㵽 w ���·��
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

