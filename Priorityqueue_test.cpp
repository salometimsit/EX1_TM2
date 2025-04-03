//Email: timsitmelosa@gmail.com
#include "doctest.h"
using namespace std;
//using namespace graph;
#include "Priority_queue.hpp"

Priority_queue p(6);
TEST_CASE("toptest"){
    p.push(1,2);
    p.push(3,5);
    p.push(3,3);
    p.push(1,1);
    p.push(4,3);
    CHECK(p.top()==1);
    CHECK_FALSE(p.top()==3);

}
TEST_CASE("poptest"){
    CHECK(p.pop()==1);
    CHECK(p.pop()==1);
    CHECK(p.pop()==3);
    CHECK(p.pop()==4);
    CHECK(p.pop()==3);
}
TEST_CASE("empty"){
    CHECK_THROWS_WITH(p.pop(), "Cannot pop from an empty priority queue");
}
TEST_CASE("heapifytest"){
    p.push(5, 10);
    p.push(3, 7);
    p.push(4, 8);
    p.push(1, 1);
    CHECK(p.top() == 1); 
    p.pop();
    CHECK(p.top() == 3); 

    
}