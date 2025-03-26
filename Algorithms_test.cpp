#include <iostream>
#include <cassert>
//#include "units/Graph.hpp"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "Priority_queue.hpp"
#include "Union_find.hpp"
using namespace std;
using namespace graph;
int main(){
    Graph g(6);
    g.Addedge(0, 1);
    g.Addedge(0, 2);
    g.Addedge(1, 3);
    g.Addedge(1, 4);
    g.Addedge(2, 5);
    g.print_graph();
}