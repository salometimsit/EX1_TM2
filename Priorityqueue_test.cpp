#include <iostream>
#include <cassert>
//#include "units/Graph.hpp"
#include "Priority_queue.hpp"
using namespace std;

int main(){
    Priority_queue p(4);
    p.push(1,2);
    p.push(3,5);
    p.push(1,1);
    p.push(4,3);
    // the queue is supposed to be 1,1,4,3
    Priority_queue q=p;
    for(int i=0;i<=4;i++){
        cout<<q.pop();
    }
    cout<<endl;

    //lets test top function:
    assert(p.top()==1);


}