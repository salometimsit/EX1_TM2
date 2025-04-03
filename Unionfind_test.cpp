//Email: timsitmelosa@gmail.com
#include "doctest.h"
#include "Union_find.hpp"

using namespace std;
using namespace graph;
Union_find u(6);
TEST_CASE("Findtest") {
    Nodeu* x = u.getNode(0);
    Nodeu* y = u.getNode(1);
    CHECK(u.find(x) == x);
    CHECK(u.find(y) == y);
    CHECK(u.find(y) != x);
}
TEST_CASE("ADD test"){
    Nodeu* n0 = u.getNode(0);
    Nodeu* n1 = u.getNode(1);
    Nodeu* n2 = u.getNode(3);
    Nodeu* n3 = u.getNode(5);
    Nodeu* n4 = u.getNode(4);
    Nodeu* n5 = u.getNode(2);
    u.add(n0,n1);
    u.add(n1,n2);
    u.add(n2,n3);
    u.add(n3,n4);
    Nodeu* rep = u.find(n0);
    CHECK(u.find(n1) == rep);
    CHECK(u.find(n2) == rep);
    CHECK(u.find(n3) == rep);
    CHECK(u.find(n4) == rep);
    CHECK(u.find(n5) != rep);
}