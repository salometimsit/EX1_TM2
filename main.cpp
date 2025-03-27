#include "Priority_queue.hpp"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "Union_find.hpp"
using namespace graph;
using namespace std;
void graphfunctions(){
    graph::Graph g(6);

    // Add edges
    cout<<"adding edges to graph"<<endl;
    g.Addedge(0, 3);
    g.Addedge(0, 4);
    g.Addedge(1, 4);
    g.Addedge(1, 5);
    g.Addedge(1, 2);
    g.Addedge(2, 5);
    g.Addedge(2, 3);
    g.Addedge(3, 5);
    g.Addedge(4, 5);
    cout<<"graph after adding edges"<<endl;
    g.print_graph();
    cout<<"removing edge (0,3)"<<endl;
    g.Removeedge(0,3);
    cout << "graph after removing edge (0,3):" << endl;
    g.print_graph();

}
void bfsprint(){
    cout<<"adding edges..."<<endl;
    Graph g(6);
    g.Addedge(0, 1);
    g.Addedge(0, 2);
    g.Addedge(1, 3);
    g.Addedge(1, 4);
    g.Addedge(2, 5);
    cout<<"tree before BFS"<<endl;
    g.print_graph();
    Algorithms algo(g, 6);
    cout << " Running BFS from Node 0..." << endl;
    Graph bfsTree = algo.BFS(g,0);
    cout << "BFS Tree Adjacency " << endl;
    bfsTree.print_graph();
}
void dfsprint(){
    Graph g(6);
    g.Addedge(0, 1);
    g.Addedge(0, 2);
    g.Addedge(1, 3);
    g.Addedge(1, 4);
    g.Addedge(2, 5);

    Algorithms algo(g, 6);
    cout<<"tree before DFS"<<endl;
    g.print_graph();
    cout << "Running DFS from Node 0..." << endl;
    Graph dfsTree = algo.DFS(g,0);
    cout << "DFS Tree Adjacency:" << endl;
    dfsTree.print_graph();

}
void printdijakstra(){
    Graph G(6);

    // Add weighted edges (Undirected Graph)
    G.Addedge(0, 1, 4);
    G.Addedge(0, 2, 1);
    G.Addedge(1, 3, 1);
    G.Addedge(2, 1, 2);
    G.Addedge(2, 3, 5);
    G.Addedge(3, 4, 3);
    G.Addedge(4, 5, 2);
    G.Addedge(3, 5, 8);

    // Print the original graph
    cout << "graph before dijakstra" << endl;
    G.print_graph();
    cout << endl;

    // Run Dijkstra's Algorithm
    int start_node = 0;
    Algorithms algo(G, 6);
    Graph dij_graph = algo.Dijakstra(G, start_node);

    // Print the shortest path tree from the source node
    cout << "Dijkstra's Shortest Path Tree from node 0:"<< endl;
    dij_graph.print_graph();

}
void printprim(){
    Graph G(6);

    G.Addedge(0, 1, 4);
    G.Addedge(0, 2, 1);
    G.Addedge(1, 3, 1);
    G.Addedge(2, 1, 2);
    G.Addedge(2, 3, 5);
    G.Addedge(3, 4, 3);
    G.Addedge(4, 5, 2);
    G.Addedge(3, 5, 8);

    cout << "grapoh before prim:" << endl;
    G.print_graph();
    cout << endl;
    int start_node = 0;
    Algorithms algo(G, 6);
    Graph prim_mst = algo.Prims(G, start_node);

    // Print the Minimum Spanning Tree
    cout << "Prim's Minimum Spanning Tree from node 0"<< endl;
    prim_mst.print_graph();

}
void printkruskal(){
    Graph G(6);
    G.Addedge(0, 1, 4);
    G.Addedge(0, 2, 3);
    G.Addedge(1, 2, 1);
    G.Addedge(1, 3, 2);
    G.Addedge(2, 3, 4);
    G.Addedge(3, 4, 2);
    G.Addedge(4, 5, 6);
    
    cout << "graph before kruskal:"<<endl;;
    G.print_graph();
   int start_node = 0;
   Algorithms algo(G, 6);
   Graph kruskal = algo.Kruskal(G);
   Graph prim=algo.Prims(G,start_node);

    cout<<"graph after applying kruskal mst"<<endl;
    kruskal.print_graph();

}
int main(){
    int x;
    cout<<"interactive main, please chose what class to visualize:"<<endl;
    cout<<"1.GRAPH"<<endl;
    cout<<"2.BFS"<<endl;
    cout<<"3.DFS"<<endl;
    cout<<"4.DIJAKSTRA"<<endl;
    cout<<"5.PRIM"<<endl;
    cout<<"6.KRUSKAL"<<endl;
    cout<<"enter a number: ";
    cin>> x;
    if(x==1){
        graphfunctions();
    }
    else if(x==2){
        bfsprint();
    }
    else if(x==3){
        dfsprint();
    }
    else if(x==4){
        printdijakstra();
    }
    else if(x==5){
        printprim();
    }
    else if(x==6){
        printkruskal();
    }
    else{
       cout<<"invalid option please try again...";
    }

}
// #include "Graph.hpp"
// #include "Algorithms.hpp"
// #include <iostream>

// using namespace std;
// using namespace graph;





// int main() {
//     // Create a graph with 6 vertices
//     Graph G(6);
    
//     // Add edges
//     G.Addedge(0, 1, 4);
//     G.Addedge(0, 2, 3);
//     G.Addedge(1, 2, 1);
//     G.Addedge(1, 3, 2);
//     G.Addedge(2, 3, 4);
//     G.Addedge(3, 4, 2);
//     G.Addedge(4, 5, 6);
    
//     std::cout << "Original Graph:\n";
//     G.print_graph();

    
//     // Apply Kruskal's algorithm
//    // Graph mst = Kruskal(G);
//    int start_node = 0;
//    Algorithms algo(G, 6);
//    Graph kruskal = algo.Kruskal(G);
//    Graph prim=algo.Prims(G,start_node);

//     std::cout << "\nkruskal:\n";
//     kruskal.print_graph();
   
//     std::cout << "\nprim:\n";
//     prim.print_graph();
    
//     // Calculate and print the total weight of the MST
//    // int totalWeight = calculateTotalWeight(mst);
//    // std::cout << "\nTotal weight of the MST: " << totalWeight << std::endl;
    
//     return 0;
// }
// int main() {
//     Union_find uf(5); // ✅ Create Union-Find with 5 elements

//     // ✅ Use `getNode(index)` instead of accessing `ptr[]`
//     Nodeu* node0 = uf.getNode(0);
//     Nodeu* node1 = uf.getNode(1);
//     Nodeu* node2 = uf.getNode(2);
//     Nodeu* node3 = uf.getNode(3);
//     Nodeu* node4 = uf.getNode(4);

//     // ✅ Perform union operations
//     uf.add(node0, node1);
//     uf.add(node2, node3);
//     uf.add(node1, node3); // ✅ Connects (0,1) and (2,3)

//     // ✅ Check if nodes are in the same set
//     cout << "Are 0 and 3 connected? " << (uf.find(node0) == uf.find(node3) ? "Yes" : "No") << endl;
//     cout << "Are 1 and 4 connected? " << (uf.find(node1) == uf.find(node4) ? "Yes" : "No") << endl;

//     return 0;
// }