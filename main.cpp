//#include "Graph.hpp"
//#include <Graph.cpp>
// using namespace graph;
// using namespace std;
// int main()
// {
//     graph::Graph g(6);

//     // Add edges
//     g.Addedge(0, 3);
//     g.Addedge(0, 4);
//     g.Addedge(1, 4);
//     g.Addedge(1, 5);
//     g.Addedge(1, 2);
//     g.Addedge(2, 5);
//     g.Addedge(2, 3);
//     g.Addedge(3, 5);
//     g.Addedge(4, 5);

//     // Print the adjacency matrix
//     g.print_graph();

//     // Try removing an edge
//     try {
//         g.Removeedge(0, 3);
//         cout << "\nAfter removing edge (0,3):" << endl;
//         g.print_graph();
//     } catch (exception& e) {
//         cout << e.what() << endl;
//     }

//     return 0;
// }
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace std;
using namespace graph;

int main() {
    // ✅ Step 1: Create a Graph
    Graph g(6);
    g.Addedge(0, 1);
    g.Addedge(0, 2);
    g.Addedge(1, 3);
    g.Addedge(1, 4);
    g.Addedge(2, 5);

    // ✅ Step 2: Create an instance of Algorithms with the graph
    Algorithms algo(g, 6);

    // ✅ Step 3: Test BFS
    cout << "\n🔹 Running BFS from Node 0..." << endl;
    Graph bfsTree = algo.BFS(g,0);
    cout << "✅ BFS Tree Adjacency Matrix:" << endl;
    bfsTree.print_graph();

    // ✅ Step 4: Test DFS
    cout << "\n🔹 Running DFS from Node 0..." << endl;
    Graph dfsTree = algo.DFS(g,0);
    cout << "✅ DFS Tree Adjacency Matrix:" << endl;
    dfsTree.print_graph();

    return 0;
}

