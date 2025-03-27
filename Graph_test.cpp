// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
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