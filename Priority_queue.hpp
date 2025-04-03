//Email: timsitmelosa@gmail.com
#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>
#include <stdexcept>

class Priority_queue {
    private:
        struct Node {
            int priority;
            int value;
        };
        
        Node* heap;
        int capacity;
        void swap(Node &a, Node &b);
        void heapifyup(int index);
        void heapifydown(int index);

    public:
        int curr_size;
        Priority_queue(int capacity);
        ~Priority_queue();
        void push(int value, int priority);
        int pop();
        int top();
    };

#endif 