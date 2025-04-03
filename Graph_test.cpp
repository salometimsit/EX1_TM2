//Email: timsitmelosa@gmail.com
#include "doctest.h"
#include "Graph.hpp"

using namespace std;
using namespace graph;
graph::Graph g(2);
TEST_CASE("testing hasedge"){
    g.Addedge(0,0);
    g.Addedge(0,1);
    CHECK(g.hasedge(0,1));
    CHECK_FALSE(g.hasedge(1,1));
}
TEST_CASE("test removeedge and count"){
    g.Removeedge(0,0);
    CHECK_FALSE(g.hasedge(0,0));
    CHECK(g.count_edge()==1);
}
TEST_CASE("double adding same edge") {
    Graph g(4);
    g.Addedge(1, 2);
    g.Addedge(1, 2);   
    CHECK(g.count_edge() == 1);  
}
TEST_CASE("removing edge that doesnt exist") {
    Graph g(3);
    CHECK_THROWS(g.Removeedge(0, 1));  
}
TEST_CASE("Empty graph") {
    Graph g(0);
    Algorithms algo(g, 0);
    CHECK(g.count_edge() == 0);
}
TEST_CASE("Invalid edge") {
    Graph g(3);
    CHECK_THROWS_AS(g.Addedge(0, 5), std::invalid_argument);
    CHECK_THROWS_AS(g.Addedge(-1, 2), std::invalid_argument);
}
TEST_CASE("Adding inconsistent undirected edge weights should throw") {
    Graph g(3);
    g.Addedge(0, 1, 4); // add edge 0-1 with weight 4

    // try to add the same edge in reverse with different weight
    CHECK_THROWS_AS(g.Addedge(1, 0, 3), std::invalid_argument);
}