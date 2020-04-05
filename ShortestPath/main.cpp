#include <iostream>
#include <string>
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

using namespace std;

int main() {
    string filename =
        "testG_negative_circle.txt"; // testG_negative_circle.txt testG2.txt
    int V = 5;
    SparseGraph<int> g = SparseGraph<int>(V, false);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout << "Test Bellman-Ford:" << endl << endl;
    BellmanFord<SparseGraph<int>, int> bell(g, 0);
    if (bell.negativeCycle())
        cout << "The Graph contain negative cycle!" << endl;
    else
        for (int i = 1; i < V; ++i) {
            cout << "Shortest Path to " << i << " : " << bell.shortestPathTo(i)
                 << endl;
            bell.showPath(i);
            cout << "-------------" << endl;
        }
    return 0;
}