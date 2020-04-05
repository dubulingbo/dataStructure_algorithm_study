//
// Created by Administrator on 2020/2/28 0028.
//

#ifndef MINIMUM_SPAN_TREE_EDGE_H
#define MINIMUM_SPAN_TREE_EDGE_H

#include<iostream>
#include<cassert>


template<typename Weight>
class Edge {
private:
    int a, b;  // 有方向默认为a->b ,
    Weight weight;

public:
    Edge(int a, int b, Weight weight) {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge() {}

    ~Edge() {}

    int v() { return a; }

    int w() { return b; }

    Weight wt() { return weight; }

    int other(int x) {
        assert(x == a || x == b);
        return x == a ? b : a;
    }

    friend std::ostream &operator<<(std::ostream &os, const Edge &e) {
        os << e.a << "--" << e.b << ": " << e.weight;
        return os;
    }

    bool operator<(Edge<Weight> &e) {
        return weight < e.wt();
    }

    bool operator>(Edge<Weight> &e){
        return weight > e.wt();
    }

    bool operator<=(Edge<Weight> &e) {
        return weight <= e.wt();
    }

    bool operator>=(Edge<Weight> &e){
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight> &e){
        return weight == e.wt();
    }

};

#endif //MINIMUM_SPAN_TREE_EDGE_H
