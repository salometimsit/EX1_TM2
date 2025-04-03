//Email: timsitmelosa@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <stdexcept>  

namespace graph {
    struct Node{
        const int v; 
        int weight; 
        Node* next;
        Node(int v, int w) : v(v), weight(w), next(nullptr) {}
    };
    class Graph {
    private:
       const int  vnum;                  
        void initadjlist(); 

    public:
        Node **adjlist;
        Graph(int vnum); 
        ~Graph(); 
        int get_weight(int src,int dst);
        int getNumVertices() const;
        void Addedge(int src, int dst, int weight = 1);
        void Removeedge(int src, int dst);
        void print_graph();
        bool hasedge(int src,int dst);
        int count_edge();
    };
}
#endif