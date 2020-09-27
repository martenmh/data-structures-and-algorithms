//
// Created by marten on 27-09-20.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include "Array.h"

// concept Queable = support front(), back(), push_back(), pop_front() & size();

// FIFO
template <class T, class Container = Array<T> >
class Queue {
    Container container;
public:
    bool empty(){ return size() != 0; }
    size_type size(){ return container.size(); }
    T& front(){ return container.front(); }
    T& back(){ return container.back(); }
    // Push at the back
    void enqueue(T val){ container.push_back(val); }
    // Pop the front
    T& dequeue(){
        T popped = container.front();
        container.pop_front();
        return popped;
    }
};


#endif //DATA_STRUCTURES_QUEUE_H
