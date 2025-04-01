#include "Graph.hpp"
#include <iostream>
using namespace std;
using namespace graph;
     
void Graph::initadjlist(){
    //initializing the adjacency list to null.
    for (int i = 0; i < vnum; i++) {
        adjlist[i] = nullptr;
    }
}

        
Graph::Graph(int vnum): vnum(vnum) {//:v(v) is bacause we are assigning to a constant
    //constructor of the vertex and the adjacency list
    adjlist = new Node*[vnum];
    initadjlist();
}
Graph::~Graph() {
    //distructor so that we dont overflow
    for (int i = 0; i < vnum; i++) {
        Node* current = adjlist[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjlist;
}

/* 
getter functions: 
get weight return weight of the edge between two vertexes src and dst
*/
int Graph::get_weight(int src,int dst){
    if(!hasedge(src,dst)){
        throw invalid_argument("Edge does not exist");
    }
    Node* current = adjlist[src];
    while (current) {
        if (current->v == dst) {
            return current->weight;
        }
        current = current->next;
    }
    throw invalid_argument("Edge does not exist");
} 
/* 
getter functions: 
get num vetices returns the constant amount of vertexes in the graph
*/
int Graph::getNumVertices() const {
    return vnum;
}

/*
input:
source,destenation vertexes and weight between them the default will be 1.
output:
void function will just add to the adjlist the new edge.

*/
void Graph::Addedge(int src, int dst, int weight) {
    if (src < 0 || dst < 0 || src >= vnum || dst >= vnum) {
        throw invalid_argument("Invalid vertex index");
    }
    if (hasedge(src, dst)){// added this because the graph is undirected
        int exist=get_weight(src,dst);
        if(exist!=weight) {
            throw invalid_argument("Inconsistent weight for undirected edge");
        }
        return;

    } 

    //because its undirected i have to make both ways.
    Node* tmp = new Node(dst, weight);
    tmp->next = adjlist[src];
    adjlist[src] = tmp;

    Node* tmp2 = new Node(src, weight);
    tmp2->next = adjlist[dst];
    adjlist[dst] = tmp2;
}

/*
input:
source,destenation vertexes
output:
void function will just remove to the adjlist the edge.
i had to do it both ways so that i deleted the edge completely.

*/
void Graph::Removeedge(int src,int dst){
    
    if(!hasedge(src,dst)){
        throw invalid_argument("no edge between these vertexes");
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
    for(int i=0;i<vnum;i++){
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
    if(src<0||dst<0 ||src>=vnum||dst>=vnum){
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
int Graph::count_edge(){
    int count=0;
    for(int i=0;i<vnum;i++){
        Node* curr=adjlist[i];
        while(curr!=nullptr){
            if(i<curr->v){
                count++;
            }
            curr=curr->next;
        }
    }
    return count;
} 



