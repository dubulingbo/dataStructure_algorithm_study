//
// Created by Administrator on 2020/2/27 0027.
//

#ifndef GRAPH_READ_GRAPH_H
#define GRAPH_READ_GRAPH_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cassert>

template<typename Graph>
class ReadGraph{
private:

public:
    ReadGraph(Graph &graph,const std::string &filename){
        std::ifstream in(filename);
        std::string line;
        int V,E;

        assert(in.is_open());

        assert(getline(in,line));
        std::stringstream ss(line);
        ss>>V>>E;

        assert(V == graph.V());

        for(int i=0;i<E;++i){
            assert(getline(in,line));
            std::stringstream ss(line);
            int a,b;
            ss>>a>>b;
            assert(a>=0 && a<V);
            assert(b>=0 && b<V);
            graph.addEdge(a,b);
        }
    }
};

#endif //GRAPH_READ_GRAPH_H
