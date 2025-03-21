#include "Algorithms.hpp"
#include <iostream>
#include "Priority_queue.hpp"
using namespace std;
using namespace graph;
Algorithms::Algorithms(Graph& G, int v) : G(G), v(v) {}
Graph Algorithms:: BFS(int ori){
    Graph bfs(v);
    Priority_queue q(v);
    q.push(ori,0);
    bool* visit = new bool[v];
    for (int i = 0; i < v; i++){
        visited[i] = false;
    } 
    visit[ori]=true;
    while(q.curr_size>0){
        int cuur_node  = q.pop();
        for(int i=0;i<v;i++){
            if(G.)
        }
    }

    



}