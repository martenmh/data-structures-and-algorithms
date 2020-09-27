#ifndef DATA_STRUCTURES_DEQUE_H
#define DATA_STRUCTURES_DEQUE_H

// concept Queable = support front(), back(), push_back(), pop_front() & size();
#include <
// Double Ended Queue
template <class T, class Container = Array<T> >
class Deque : public Container {
public:
    bool empty(){}
    size_type size(){}
    T& front(){}
    T& back(){}

};

#endif //DATA_STRUCTURES_DEQUE_H
