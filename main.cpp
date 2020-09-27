#include <iostream>
#include "boilerplate.h"


// LIFO container
template<typename T, class AllocaterT = std::allocator<T>>
class stack {
    void push(){}
    T pop(){}
};

// FIFO container
class queue{};
// Double ended queue
class dequeue{};
class priority_queue{};

class set {};

class tree{};

// Enables variable Short String Optimization length
template<size_t SSOLength>
class string {};

class graph{};

template<typename F, F HashFunc>
class hashtable {};

class heap {};

//template <class T, class Allocator = std::allocator<T> >
//class Array : private Allocator
//{
//public:
//    typedef T value_type;
//    typedef std::allocator_traits<Allocator> alloc_tr;
//
//    typedef typename alloc_tr::size_type size_type;
//    typedef typename alloc_tr::difference_type difference_type;
//
//    typedef typename alloc_tr::pointer       iterator;
//    typedef typename alloc_tr::const_pointer const_iterator;
//
//    typedef Allocator allocator_type;
//    allocator_type get_allocator() const {
//        return static_cast<const Allocator&>(*this);
//    }
//
//    iterator begin()             { return first; }
//    iterator end()               { return last; }
//    const_iterator begin() const { return first; }
//    const_iterator end() const   { return last; }
//
//    T& operator[](int index){
//        return first[index];
//    }
//    explicit Array(size_type n = 0,
//          const T& x = T(),
//          const Allocator& a = Allocator());
//    Array(const Array&) = default;
//    ~Array();
//
//    Array& operator=(const Array&) = default;
//
//private:
//    iterator first;
//    iterator last;
//};
//
//template <class T, class Allocator>
//Array<T, Allocator>::Array(size_type n,
//                           const T& x,
//                           const Allocator& a)
//        : Allocator(a), first(0), last(0)
//{
//    if (n != 0) {
//        first = Allocator::allocate(n);
//        size_type i;
//        try {
//            for (i = 0; i < n; ++i) {
//                first[i] = x;
//            }
//        }
//        catch(...) {
////            for(size_type j = 0; j < i; ++j) {
////                Allocator::destroy(first + j);
////            }
//            Allocator::deallocate(first, n);
//            throw;
//        }
//    }
//}
//template <class T, class Allocator>
//Array<T, Allocator>::~Array()
//{
//    if (first != last) {
////        for (iterator i = first; i < last; ++i)
////            Allocator::destroy(i);
//        Allocator::deallocate(first, last - first);
//    }
//}

//template<class T, class Allocator = std::allocator<T>>
//class S {
//public:
//    typedef std::allocator_traits<Allocator> t;
//    Allocator alloc;
//    T* ptr;
//    S(){}
//
//    void push(T i){
//
//        _M_start[0] = i;
//    }
//
//};


#include "contiguous/Array.h"
#include "linked/List.h"
#include <array>
#include <stack>
#include <vector>
#include <list>
int main() {

    std::vector<int> n;
    List<int> list(6,2);
    list.push_back(23);
    list.insert(3,15);
    list.remove(1);
    for(int m : list){
        std::cout << m << std::endl;
    }
    std::cout << "-----------" << std::endl;
    for(int i = 0 ; i < list.m_size; i++){
        std::cout << list[i] << std::endl;
    }
    std::cout << "-----------" << std::endl;
    Array<int> arr(5,3);
    for(int i : arr){
        std::cout << i << std::endl;
    }
    std::cout << "-----------" << std::endl;
    arr.push_back(7);
    //arr.push_back(5);
    //arr.push_back(1);
    //arr.push_back(2);
    arr.emplace_back(2000);
    for(int i : arr){
        std::cout << i << std::endl;
    }
    std::cout << "-----------" << std::endl;
    arr.insert(4, 134098);
    arr.push_back(7);
    //arr.push_back(3);
    arr.push_back(3);
    arr.insert(4, 9);
    arr.remove(2);
    for(int i : arr){
        std::cout << i << std::endl;
    }
    return 0;
}
