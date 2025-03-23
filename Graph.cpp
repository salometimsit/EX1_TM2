#include "Graph.hpp"
#include <iostream>
using namespace std;
using namespace graph;
     
void Graph::initadjlist(){
    //initializing the adjacency list to null.
    for (int i = 0; i < v; i++) {
        adjlist[i] = nullptr;
    }
}

        
Graph::Graph(int v): v(v) {//:v(v) is bacause we are assigning to a constant
    //constructor of the vertex and the adjacency list
    adjlist = new Node*[v];
    initadjlist();
}
Graph::~Graph() {
    //distructor so that we dont overflow
    for (int i = 0; i < v; i++) {
        Node* current = adjlist[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjlist;
}

int Graph::get_weight(int src,int dst){
    if(!hasedge(src,dst)){
        throw invalid_argument("Invalid vertex index");
    }
    Node* current = adjlist[src];
    while (current) {
        if (current->v == dst) {
            return current->weight;
        }
        current = current->next;
    }
    throw invalid_argument("edge does not exist");
} 

void Graph::Addedge(int src,int dst, int weight){
    if(src<0||dst<0 ||src>v||dst>v){
        throw invalid_argument("vertex should be in boundries 0<x<v");
    }
    Node* tmp = new Node(dst, weight);
    tmp->next = adjlist[src];
    adjlist[src] = tmp;

    Node* tmp2 = new Node(src, weight);
    tmp2->next = adjlist[dst];
    adjlist[dst] = tmp2;
    

}
void Graph::Removeedge(int src,int dst){
    
    if(!hasedge(src,dst)){
        throw invalid_argument("edge between src and dst should be 1");

    }
    Node* current = adjlist[src];
    Node* prev = nullptr;
    while (current && current->v != dst) {
        prev = current;
        current = current->next;
    }
    if (prev!=nullptr) {
        prev->next = current->next;
    } 
    else {
        adjlist[src] = current->next;
    }
    delete current;

    current = adjlist[dst];
    prev = nullptr;
    
    while (current && current->v != src) {
        prev = current;
        current = current->next;
    }
    
    if (prev!=nullptr) {
        prev->next = current->next;
    } 
    else {
        adjlist[dst] = current->next;
    }
    
    delete current;
}


void Graph::print_graph(){
    for(int i=0;i<v;i++){
        cout << "Vertex " << i << ": ";
        Node* current = adjlist[i];
        while(current!=nullptr){
            cout << "(" << current->v << ", " << current->weight << ") ";
            current=current->next;
        }
        cout<<endl;
    }
}
bool Graph::hasedge(int src,int dst){
    if(src<0||dst<0 ||src>=v||dst>=v){
        throw invalid_argument("Error: Invalid vertex index");
    }
    Node* tmp= adjlist[src];
    while(tmp!=nullptr){
        if(tmp->v==dst){
            return true;
        }
        tmp=tmp->next;
    }
    return false;

}
       



