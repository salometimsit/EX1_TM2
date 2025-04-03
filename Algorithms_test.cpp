//Email: timsitmelosa@gmail.com
#include "doctest.h"
using namespace std;

#include "Priority_queue.hpp"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "Union_find.hpp"
using namespace graph;

TEST_CASE("dfs and bfs"){
    Graph g(3);
    g.Addedge(0, 1);
    g.Addedge(0, 2);
    g.Addedge(1, 0);
    Algorithms algo(g, 3);
    Graph bfsGraph = algo.BFS(g, 0);
    Graph dfsGraph = algo.DFS(g, 0);
    int count = dfsGraph.count_edge();
    CHECK(count == 2); 
    Graph expected(3);
    expected.Addedge(0, 1);
    expected.Addedge(0, 2);
    CHECK(algo.samegraph(bfsGraph, expected, 3));
    CHECK(algo.samegraph(dfsGraph, expected, 3));
}
TEST_CASE("Single vertex graph") {
    Graph g(1);
    Algorithms algo(g, 1);
    CHECK(g.count_edge() == 0);
    Graph bfs = algo.BFS(g, 0);
    CHECK(bfs.count_edge() == 0);
}
TEST_CASE("BFS/DFS on disconnected node") {
    Graph g(4);
    g.Addedge(0, 1);
    g.Addedge(1, 2);
    Algorithms algo(g, 4);
    Graph bfs = algo.BFS(g, 0);
    CHECK(bfs.getNumVertices() == 4);
    CHECK(bfs.hasedge(0, 1));
    CHECK_FALSE(bfs.hasedge(0, 3));
}
TEST_CASE("Dijkstra's algorithm") {
    Graph g(4);
    g.Addedge(0, 1, 1);  
    g.Addedge(0, 2, 4); 
    g.Addedge(1, 3, 2);

    Algorithms algo(g, 4);
    Graph result = algo.Dijakstra(g, 0);

    Graph expected(4);
    expected.Addedge(0, 1, 1);  
    expected.Addedge(1, 3, 2);  
    expected.Addedge(0, 2, 4);  

    CHECK(algo.samegraph(result, expected, 4));
    Graph g2(2);
    g2.Addedge(0,1,-3);
    Algorithms algo2(g2,2);
    CHECK_THROWS_AS(algo2.Dijakstra(g2, 0), std::invalid_argument);
    


}
TEST_CASE("Prim's test") {
    Graph g(6);
    g.Addedge(0, 1, 1);
    g.Addedge(0, 2, 3);
    g.Addedge(1, 3, 4);
    g.Addedge(1, 4, 2);
    g.Addedge(2, 5, 6);

    Algorithms algo(g, 6);
    Graph result = algo.Prims(g, 0);

    Graph expected(6);
    expected.Addedge(0, 1, 1);
    expected.Addedge(1, 4, 2);
    expected.Addedge(0, 2, 3);
    expected.Addedge(1, 3, 4);
    expected.Addedge(2, 5, 6);

    CHECK(algo.samegraph(result, expected, 6));
}
TEST_CASE("Prim on disconnected graph") {
    Graph g(4);
    g.Addedge(0, 1, 1);
    g.Addedge(1, 2, 2);
    // קודקוד 3 מנותק

    Algorithms algo(g, 4);
    Graph pt = algo.Prims(g,0);

    // בדוק שאין שום צלע שכוללת את הקודקוד המנותק
    CHECK_FALSE(pt.hasedge(3, 0));
    CHECK_FALSE(pt.hasedge(3, 1));
    CHECK_FALSE(pt.hasedge(3, 2));

    CHECK(pt.count_edge() == 2); 
}

TEST_CASE("Kruskal's test") {
    
    Graph g(6);
    g.Addedge(0, 1, 1);
    g.Addedge(0, 2, 3);
    g.Addedge(1, 3, 4);
    g.Addedge(1, 4, 2);
    g.Addedge(2, 5, 6);

    Algorithms algo(g, 6);
    Graph result = algo.Kruskal(g);

    Graph expected(6);
    expected.Addedge(0, 1, 1);  
    expected.Addedge(0, 2, 3);
    expected.Addedge(1, 4, 2);
    expected.Addedge(1, 3, 4);
    expected.Addedge(2, 5, 6);

    CHECK(algo.samegraph(result, expected, 6));

}
