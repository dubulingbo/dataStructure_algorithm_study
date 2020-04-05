#include <iostream>
#include <string>
#include <iomanip>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"

using namespace std;

int main() {
    string filename = "testG1.txt";
    int V = 8;
    //cout<<fixed<<setprecision(2);

    // Test Weight Dense Graph
   /* DenseGraph<double> g1 = DenseGraph<double>(V,false);
    ReadGraph<DenseGraph<double>,double> readGraph1(g1,filename);
    g1.show();
    cout<<endl;

    // Test Weight Sparse Graph
    SparseGraph<double> g2 = SparseGraph<double>(V,false);
    ReadGraph<SparseGraph<double>,double> readGraph2(g2,filename);
    g2.show();
    cout<<endl;*/

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);
    
    // Test Lazy Prim MST
    cout << "Test Lazy Prim MST:" << endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << lazyPrimMST.result() << endl;

    cout << endl;

    // Test Prim MST
    cout << "Test Prim MST:" << endl;
    PrimMST<SparseGraph<double>, double> primMST(g);
    mst = primMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << primMST.result() << endl;

    cout << endl;

    // Test Kruskal MST
    cout << "Test Kruskal MST:" << endl;
    KruskalMST<SparseGraph<double>, double> kruskalMST(g);
    mst = kruskalMST.mstEdges();
    for (int i = 0; i < mst.size(); ++i)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << kruskalMST.result() << endl;

    return 0;
}
