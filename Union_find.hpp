//Email: timsitmelosa@gmail.com
#ifndef Union_find_HPP
#define Union_find_HPP

#include <iostream>
#include <stdexcept> 
namespace graph {
    struct Nodeu{
        Nodeu* rep;//representive
        Nodeu* next;
        Nodeu() : rep(this) {}
    };
    class Union_find{
        private:
            
            Nodeu** ptr;
        public:
            int size;
            ~Union_find();
            Union_find(int s);
            Nodeu* find(Nodeu* x);
            void add(Nodeu* x, Nodeu* y);
            Nodeu* getNode(int index);
    };
}
#endif 