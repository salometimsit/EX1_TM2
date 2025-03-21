#include "Graph.hpp"
#include <iostream>
using namespace std;
using namespace graph;

        
void Graph::initadjlist(){
    //initializing the adjacency list to 0.
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adjlist[i][j]=0;
        }
    }
}

        
Graph::Graph(int v): v(v) {//:v(v) is bacause we are assigning to a constant
    //constructor of the vertex and the adjacency list
    adjlist = new int *[v];
    for(int i=0;i<v;i++){
        adjlist[i]=new int[v];
    }
    initadjlist();
}
Graph::~Graph() {
    //distructor so that we dont overflow
    for (int i = 0; i < v; i++) {
        delete[] adjlist[i];
    }
    delete[] adjlist;
}

void Graph::Addedge(int src,int dst, int weight){
    if(src<0||dst<0 ||src>v||dst>v){
        throw std::invalid vertex("vertex should be in boundries 0<x<v");
    }
    //need to do both ways because its an undirected graph
    adjlist[src][dst]=weight;
    adjlist[dst][src]=weight;

}
void Graph::Removeedge(int src,int dst){
    if(src<0||dst<0 ||src>v||dst>v){
        throw std::invalid vertex("vertex should be in boundries 0<x<v");
        //במקום זה אני צריכה לעשות throw 
    }
    if(adjlist[src][dst]==0 ||adjlist[dst][src]==0){
        throw std::invalid edge("edge between src and dst should be 1");

    }
    adjlist[src][dst]=0;
    adjlist[dst][src]=0;
}
void Graph::print_graph(){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<adjlist[i][j]<<" ";  
        }
        cout << endl;
    }
}
       



