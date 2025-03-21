#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <stdexcept>  

namespace graph {
    class Graph {
    private:
        const int v; 
        int** adjlist; 

        void initadjlist(); 

    public:
        Graph(int v); 
        ~Graph(); 

        void Addedge(int src, int dst, int weight = 1);
        void Removeedge(int src, int dst);
        void print_graph();
        bool hasedge(int src,int dst);
    };
}
#endif