//Email: timsitmelosa@gmail.com
#include "Algorithms.hpp"
#include <iostream>
#include "Priority_queue.hpp"
#include <limits.h>
using namespace std;
using namespace graph;
/*
Algorithms class: 
    in this class nearly all functions excluding kruskal and bubble sort will have an input of original vertex 
    and a graph and the output will be a graph represnting the result of the algorithm.
*/

/*
constructor+ distructor:
*/
Algorithms::Algorithms(Graph& G, int v) : p(v),G(G),v(v) {}
Algorithms::~Algorithms() {}

/*
BFS: implementation with priority queue and every new node addded will get the priority of its index +1 
so that when i want to pop ill get the first one that was entered because my priority queue works with min heap(FIFO), 
so its basically like a standart queue you would use for BFS.
 */
Graph Algorithms::BFS(Graph& G,int ori){
    int v=G.getNumVertices();
    Graph bfs(v);
    Priority_queue q(v);
    q.push(ori,0);
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++){
        visited[i] = false;
    } 
    visited[ori]=true;
    while(q.curr_size>0){
        int curr_node  = q.pop();
        Node* neigh = G.adjlist[curr_node];
        while(neigh!=nullptr){
            int i= neigh->v;
            if(visited[i]==false){
                bfs.Addedge(curr_node,i,neigh->weight);
                q.push(i,q.curr_size+1);
                visited[i]=true;
            }
            neigh=neigh->next;
        }
    }
    delete[] visited;
    return bfs;
}
/*
DFS: implementation with priority queue and every new node addded will get the priority of a variable called
 time that starts at 0 end decrease so that the queue can act like a stack in (LIFO) so that when i want
  to pop ill get the last one that was entered because my priority queue works with min heap. so its basically like
   a standart stack you would use for DFS.
*/
Graph Algorithms::DFS(Graph& G,int ori){
    int v=G.getNumVertices();
    Graph dfs(v);
    Priority_queue q(v);
    int time=0;
    q.push(ori,-time);
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++){
        visited[i] = false;
    } 
    visited[ori]=true;
    time++;
    while(q.curr_size>0){
        int curr_node  = q.pop();
        Node* neigh = G.adjlist[curr_node];
        while (neigh != nullptr) {
            int i = neigh->v;
            if (visited[i]==false) {
                dfs.Addedge(curr_node, i, neigh->weight);
                visited[i] = true;
                q.push(i, -time);
                time++;
            }
            neigh = neigh->next;
        }
    }
    delete[] visited;
    return dfs;
}
/*
Dijakstra: i initialized all distances to INT_MAX(to demo infinity) and using a priority queue 
to always process the closest unvisited node.I tracked  the shortest distances and update
 them when a better path is found. To reconstruct the shortest-path tree, i stored each node’s parent, 
 and after the main loop, build the result graph using those parent links.I also added a check to prevent negative weights,
  which Dijkstra doesn't support.

*/
Graph Algorithms::Dijakstra(Graph& G, int ori){
    for(int i = 0; i < G.getNumVertices(); i++){
        Node* curr = G.adjlist[i];
        while(curr != nullptr){
            if(curr->weight < 0){
                throw std::invalid_argument("Invalid source vertex");
            }
            curr = curr->next;
        }
            
    }
    int v=G.getNumVertices();
    Graph dij(v);
    Priority_queue q(v);
    q.push(ori,0);
    int* dist = new int[v];
    int* parents=new int[v]; // הייתי חייבת להוסיף הורים כי אחרת הוא ספר כל פעם ולא התקדם.
    for (int i = 0; i < v; i++){
        dist[i]=INT_MAX;
        parents[i]=-1;
    } 
    dist[ori]=0;
    while(q.curr_size>0){
        int curr_node  = q.pop();
        Node* neigh = G.adjlist[curr_node];
        while(neigh!=nullptr){
            int i= neigh->v;
            if(dist[curr_node]+neigh->weight<dist[i]){
                dist[i]= dist[curr_node]+neigh->weight;
                //dij.Addedge(curr_node,i,neigh->weight);
                parents[i]=curr_node;
                q.push(i,dist[i]);
            }
            neigh=neigh->next;
        }
    }
    for(int i=0;i<v;i++){
        if(parents[i]!=-1){
            dij.Addedge(parents[i],i,G.get_weight(parents[i], i));
        }
    }
    delete[]parents;
    delete[] dist;
    return dij;
}

/*
Prims: implementation- started from a source node (ori) and used the priority queue to always pick the next node with the
 smallest edge weight. in order to track the minimum edge to each node i used 2 arrays oine for the parents and another one 
 of the edges that are already in the tree.

*/
Graph Algorithms::Prims(Graph& G, int ori) {
    int v=G.getNumVertices();
    Graph prim(v);
    Priority_queue q(v);
    q.push(ori,0);
    int* vert = new int[v];
    bool* intree=new bool[v];
    int* parents=new int[v]; // הייתי חייבת להוסיף הורים כי אחרת הוא ספר כל פעם ולא התקדם.
    for (int i = 0; i < v; i++){
        vert[i]=INT_MAX;
        parents[i]=-1;
        intree[i]=false;
    } 
    vert[ori]=0;
    while(q.curr_size>0){
        int curr_node  = q.pop();
        
        if(intree[curr_node]==true){
            continue;
        }
        intree[curr_node]=true;
        if(parents[curr_node]!=-1){
            //both sides 
            prim.Addedge(parents[curr_node],curr_node,vert[curr_node]);
            // prim.Addedge(curr_node,parents[curr_node],vert[curr_node]);
        }
        Node* neigh = G.adjlist[curr_node];
        
        while(neigh!=nullptr){
            int i= neigh->v;
            if((intree[i]!=true) && (neigh->weight<vert[i])){
                parents[i]=curr_node;
                vert[i]=neigh->weight;
                q.push(i,vert[i]);
            }
            neigh=neigh->next;
        }
    }
    delete[] intree;
    delete[] parents;
    delete[] vert;
    return prim;
}
/*
Bublle sort: because I wasnt limited in time complexity I decided to implements the sort of the edges with bubble sort,
i got edges and sorted them from ascending
*/
void Algorithms::bubbleSort(Edge* edges, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<(n-i-1); j++){
            if(edges[j].weight > edges[j + 1].weight){
                Edge temp =edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
}

/*
Kruskal: in Kruskals akgorithm we sort the edge and then check what edges dont close a circle, 
in order to do that i used the union structure checking that find of two roots x and y 
dont give me the same representative- so that there not in the same component.

*/
Graph Algorithms::Kruskal(Graph& G){
    int v=G.getNumVertices();
    Graph kruskal(v);
    int edg=G.count_edge();
    Edge* edges= new Edge[edg];
    int in=0;
    for(int i=0;i<v;i++){
        Node* curr=G.adjlist[i];
        while(curr!=nullptr){
            if(i< curr->v){
                edges[in].weight=curr->weight;
                edges[in].src=i;
                edges[in].dst=curr->v;
                in++;
            }
            curr=curr->next;
        }
    }
    
    bubbleSort(edges,in);
    graph::Union_find f(v);
    // int edcount=0;// counts the mst edges
    for (int i = 0; i < in; i++) {
        // if (edcount >= v - 1) {
        //     break; 
        // }
        Nodeu* srcn= f.getNode(edges[i].src);
        Nodeu* dstn= f.getNode(edges[i].dst);
        if(f.find(srcn)!=f.find(dstn)){
            kruskal.Addedge(edges[i].src,edges[i].dst,edges[i].weight);
            f.add(srcn,dstn);
            // edcount++;

        }

    }
    delete[] edges;
    return kruskal;
}

/* 
samegraph: this function is souly for test purposes to compare two graphs
input: 
2 graphs and their maximum size of the biggest tree
output: 
true- if its the same tree
false- otherwise
*/
bool Algorithms::samegraph(Graph& x1, Graph& x2, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bool has1 = x1.hasedge(i, j);
            bool has2 = x2.hasedge(i, j);
            if (has1 != has2){
             return false;
            }
            if (has1 && x1.get_weight(i, j) != x2.get_weight(i, j)){
                return false;
            } 
        }
    }
    return true;
}

