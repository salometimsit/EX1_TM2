#include <iostream>
#include <cassert>
//#include "units/Graph.hpp"
#include "Graph.hpp"
using namespace std;
using namespace graph;
int main(){
   
    graph::Graph g(2);
    g.Addedge(0,0);
    g.Addedge(0,1);
    cout<<"printing test graph"<<endl;
    g.print_graph();
    //testing the functions: Addedge and hasedge
    cout<<"test hasedge and addedge"<<endl;
    assert(g.hasedge(0,1)); //supposed to be true because we added
    assert(!g.hasedge(1,1)); ////supposed to be false because we didn't add
    cout<<"test hasedge passed"<<endl;

    //testing Removeedge function
    cout<<"test removeedge"<<endl;
    g.Removeedge(0,0);
    assert(!g.hasedge(0,0)); //removed so i am not supposed to have an edge
    cout<<"test removeedge passed"<<endl;
    //will test countedge 
    assert(g.count_edge()==1); //because i removed an edge im supposed to stay with one edge only.

    cout << "All Graph tests passed!" << endl;


}