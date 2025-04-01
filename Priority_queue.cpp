#include <iostream>
#include <stdexcept>
using namespace std;
#include "Priority_queue.hpp"

/* 
swap function is made to swap between two nodes
input: 
node a and b
output: 
node a as  and node b as a 
*/
void Priority_queue::swap(Node &a,Node &b){
    Node tmp= a;
    a=b;
    b=tmp;
}

/* 
hepify up in order to keep min heap properties for the priority queue
used in push 
input: 
an intger symbloyzing an index
output:
void function just changes the nodes placement.
*/
void Priority_queue::heapifyup(int index){
    while(index>0){
        int parent=(index-1)/2;
        if(heap[index].priority<heap[parent].priority){
            swap(heap[index],heap[parent]);
            index=parent;
        }
        else{
            
            break;
        }
        
    }
}
/* 
hepify down in order to keep min heap properties for the priority queue
used in pop
input: 
an intger symbloyzing an index
output:
void function just changes the nodes placement.
*/
void Priority_queue::heapifydown(int index){
    while(index*2 +1<curr_size){
        int left= index*2+1;
        int right= index*2+2;
        int small=index;
        if(right<curr_size && heap[right].priority<heap[small].priority){
            small=right;
        }
        if(left<curr_size && heap[left].priority<heap[small].priority){
            small= left;
        }
        if(small!=index){
            swap(heap[small],heap[index]);
            index=small;
        }
        else{
            break;
        } 
    }
}

/* 
constructor + distructor 
*/
Priority_queue::Priority_queue(int capacity){
    this->capacity=capacity;
    this->heap=new Node[capacity]();
    this->curr_size=0;
}
Priority_queue::~Priority_queue (){
    delete[] heap;
}

/* 
push function to enter a new value with its prirority.
input: 
value and property of wanted node to ennter
output: 
void but pushes the value in the queue
*/
void Priority_queue::push(int value,int priority){
    if(curr_size==capacity){
        throw overflow_error("Priority queue is at maximum capacity");
    }
    heap[curr_size].value=value;
    heap[curr_size].priority=priority;
   
    heapifyup(curr_size);
    curr_size++;
    
}

/* 
pop function to remove the least one with prirority.
input: 
nothing
output: 
int of the value of the top node
*/
int Priority_queue::pop(){
    if(curr_size==0){
        throw underflow_error("Cannot pop from an empty priority queue");
    }
    int val= heap[0].value;
    heap[0]=heap[curr_size-1];
    curr_size --;
    if(curr_size>0){
        heapifydown(0);
    }
    return val;
}
/* 
top function to show the least one with prirority.
input: 
nothing
output: 
int of the value of the top node
*/
int Priority_queue::top(){
    if(curr_size==0){
        throw underflow_error("Cannot show, empty priority queue");
    }
    int x = heap[0].value;
    return x;
}
