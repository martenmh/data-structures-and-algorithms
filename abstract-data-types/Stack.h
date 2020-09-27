#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include "Array.h"

// concept stackable = supports size(), push_back(), pop_back() & T& back()
//template <class T, Stackable Container = Array<T> >

// LIFO
template <class T, class Container = Array<T> >
class Stack {
    Container container;
public:
    bool empty(){ return size() == 0; }
    size_type size(){ return container.size(); }
    T& back(){ return container.back(); }
    void push(T val){ container.push_back(val); }
    T pop(){
        T popped = container.back();
        container.pop_back();
        return popped;
    }
};

#endif //DATA_STRUCTURES_STACK_H
