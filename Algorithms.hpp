#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include <stdexcept>  
#include "Graph.hpp"
#include "Priority_queue.hpp"
namespace graph {
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


    };
}
#endif