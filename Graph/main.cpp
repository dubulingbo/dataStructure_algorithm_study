#include <iostream>
#include<ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;

int main() {
    int N = 20;
    int M = 100;

    srand(time(NULL));

    // Sparse Graph
    SparseGraph g1(N, false);
    for (int i = 0; i < M; ++i) {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }

    for (int v = 0; v < N; ++v) {
        cout << v << " : ";
        SparseGraph::adjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }
    cout << endl;


    // Dense Graph
    DenseGraph g2(N, false);
    for (int i = 0; i < M; ++i) {
        int a = rand() % N;
        int b = rand() % N;
        g2.addEdge(a, b);
    }

    for (int v = 0; v < N; ++v) {
        cout << v << " : ";
        DenseGraph::adjIterator adj(g2, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }
    cout << endl;

    string filename1 = "testG1.txt";
    SparseGraph g3(13,false);
    ReadGraph<SparseGraph> readGraph1(g3,filename1);
    Component<SparseGraph> component1(g3);
    cout<< "TestG1.txt, Component count: "<<component1.count()<<endl;
    component1.showIdArr();
    cout<<endl;

    string filename2 = "testG2.txt";
    SparseGraph g4(7,false);
    ReadGraph<SparseGraph> readGraph4(g4,filename2);
    g4.show();
    cout<<endl;

    Path<SparseGraph> dfs(g4,0);
    cout<<"DFS : ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g4,0);
    cout<<"BFS : ";
    bfs.showPath(6);

    system("pause");

    return 0;
}

