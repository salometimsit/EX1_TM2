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

        for(int i=0;i<v;i++){
            if(G.hasedge(curr_node,i)&& (visited[i]==false)){
                bfs.Addedge(curr_node,i,G.get_weight(curr_node,i));
                q.push(i,q.curr_size+1);
                visited[i]=true;
            }
        }
    }
    delete[] visited;
    return bfs;
}
Graph Algorithms::DFS(Graph& G,int ori){
    int v=this->v;
    Graph dfs(this->v);
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
        cout << " DFS Debug: Queue size = " << q.curr_size << endl;
        int curr_node  = q.pop();
        cout << " DFS Debug: Popped node " << curr_node << endl;
        for(int i=0;i<v;i++){
            if(G.hasedge(curr_node,i)&& (visited[i]==false)){
                dfs.Addedge(curr_node,i,G.get_weight(curr_node,i));
                cout << "DFS Debug: Adding node " << i << " to queue." << endl;
                visited[i]=true;
                q.push(i,-time);
                time++;
            }
        }
    }
    delete[] visited;
    return dfs;
}
Graph Algorithms::Dijakstra(int ori){

}