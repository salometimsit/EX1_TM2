#include "Algorithms.hpp"
#include <iostream>
#include "Priority_queue.hpp"
using namespace std;
using namespace graph;
Algorithms::Algorithms(Graph& G, int v) : G(G), v(v),p(v) {}
Algorithms::~Algorithms() {}
Graph Algorithms::BFS(Graph& G,int ori){
    int v=this->v;
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
Graph Algorithms::DFS(Graph& G,int ori){
    int v=this->v;
    Graph dfs(v);
    Priority_queue q(v);
    cout << "DFS Debug: Adding start node " << ori << " to queue." << endl;
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
// Graph Algorithms::Dijakstra(int ori){

// }