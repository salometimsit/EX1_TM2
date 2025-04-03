//Email: timsitmelosa@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include <stdexcept>  
#include "Graph.hpp"
#include "Priority_queue.hpp"
#include <climits>
#include "Union_find.hpp"
namespace graph {
    struct Edge{
        int src;
        int weight;
        int dst;
    };
    class Algorithms {
        private:
            Priority_queue p;
            Graph& G;
            int v;
        public:
            Algorithms(Graph& G, int v);
            ~Algorithms();
            
            Graph BFS(Graph& G,int ori);
            Graph DFS(Graph& G,int ori);
            Graph Dijakstra(Graph& G, int ori);
            Graph Prims(Graph& G, int ori);
            void bubbleSort(Edge* edges, int n);
            Graph Kruskal(Graph& G);
            bool samegraph(Graph& x1, Graph& x2, int size);
           

    };
   
            
}
#endif