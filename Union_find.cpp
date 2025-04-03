//Email: timsitmelosa@gmail.com
#include "Union_find.hpp"
using namespace graph;
//constructor+distructor
Union_find::Union_find(int s){
    size=s;
    this->ptr= new Nodeu*[size];
    for(int i=0;i<size;i++){
        this->ptr[i]=new Nodeu();
    }


}
Union_find::~Union_find() {
    for (int i = 0; i < size; i++) {
        delete ptr[i];
    }
    delete[] ptr;
}
// 
Nodeu*  graph::Union_find::find(Nodeu* x){
    if(x->rep==x){
        return x;
    }
    x->rep=find(x->rep);
    return x->rep;
}
void graph::Union_find::add(Nodeu* x, Nodeu* y){
    Nodeu* repx=find(x);
    Nodeu* repy=find(y);
    if(repx!=repy){
        repx->rep=repy;
    }


}
Nodeu* graph::Union_find::getNode(int index) {
    return ptr[index];
}