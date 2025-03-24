#include "Algorithms.hpp"
#include <iostream>
#include "Priority_queue.hpp"
#include <limits.h>
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
Graph Algorithms::Dijakstra(Graph& G, int ori){
    int v=this->v;
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
Graph Algorithms::Prims(Graph& G, int ori) {
    int v=this->v;
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
Graph Algorithms::Kruskal(Graph& G){
    int v= this->v;
    Graph kruskal(v);
    int edg=G.count_edge();
    Edge* edges= new Edge[edg];
    for(int i=0;i<v;i++){
        Node* curr=G.adjlist[i];
        while(curr!=nullptr){
            if(i<curr->v){
                edges[i].weight=curr->v;
                edges[i].src=i;
                edges[i].dst=curr->v;
                
            }
            curr=curr->next;
        }
    }
    
    bubbleSort(edges,edg);
    graph::Union_find f(v);
    // int edcount=0;// counts the mst edges
    for (int i = 0; i < edg; i++) {
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

