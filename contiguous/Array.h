//
// Created by marten on 26-09-20.
//

#ifndef DATA_STRUCTURES_ARRAY_H
#define DATA_STRUCTURES_ARRAY_H

#include <memory>

const constexpr double allocationMultiplier = 1.5;

template <class T, class Allocator = std::allocator<T> >
class Array : private Allocator {
public:
    using value_type = T;
    using alloc_tr   = std::allocator_traits<Allocator>;
    using size_type         = typename alloc_tr::size_type;
    using difference_type   = typename alloc_tr::difference_type;
    using iterator          = typename alloc_tr::pointer;
    using const_iterator    = typename alloc_tr::const_pointer;
    using allocator_type    = Allocator;

private:
    iterator  m_first;
    iterator  m_last;
    iterator  m_endofcap;
    size_type m_size;
    size_type m_capacity;

    void deallocate(iterator first, size_type size){
        for (int i = 0; i != size; i++){
            alloc_tr::destroy(*this, first + i);
        }
        alloc_tr::deallocate(*this, first, size);
    }

    void reallocate(){
        try {
            size_type newCapacity = m_capacity * allocationMultiplier;
            iterator tmp = alloc_tr::allocate(*this, newCapacity);
            std::copy(m_first, m_last, tmp);
            // Deallocate old space
            deallocate(m_first, m_capacity);
            // reset fields
            m_capacity = newCapacity;
            m_first = tmp;
            m_last = m_first + m_size;
            m_endofcap = m_first + m_capacity;
        } catch(...){
            deallocate(m_first, m_capacity);
            throw;
        }
    }

public:

    explicit Array(size_type n = 0, const T& x = T()){
        m_capacity = (n + 1) * allocationMultiplier;
        reallocate();
        if (n != 0) {
            size_type i;
            try {
                for (i = 0; i < n; ++i) {
                    alloc_tr::construct(*this, m_first + i, x);
                }
            } catch(...) {
                deallocate(m_first, n);
                throw;
            }
        }
    }

    Array(const Array&) = default;
    ~Array(){
        deallocate(m_first, m_size);
    }

    /* Modifiers */
    void insert(iterator it, T val){
        if(m_size >= m_capacity) reallocate();
        alloc_tr::construct(*this, m_last+1, *m_last);
        std::copy(it, m_last, it+1);
        *it = val;
        m_last++;
        m_size++;
    }
    void remove(size_type n){
        std::copy(m_first+n, m_last, m_first+n-1);
        m_last--;
        m_size--;
    }
    void remove(iterator it){
        std::copy(it, m_last, it-1);
        m_last--;
        m_size--;
    }
    void insert(size_type n, T val){
        if(m_size >= m_capacity) reallocate();
        alloc_tr::construct(*this, m_last+1, *m_last);
        std::copy(m_first+n, m_last, m_first+n+1);
        this->operator[](n) = val;
        m_last++;
        m_size++;
    }

    template<typename ...Arr>
    void emplace(iterator it, Arr&&... args){
        insert(it, std::forward<Arr>(args)...);
    }

    void pop_back(){
        remove(m_last);
    }
    void push_back(T val){
        if(m_size >= m_capacity) reallocate();
        alloc_tr::construct(*this, m_last, val);
        m_last++;
        m_size++;
    }

    template<typename ...Arr>
    void emplace_back(Arr&&... args){ push_back(std::forward<Arr>(args)...); }
    void pop_front(){ remove(m_first); }
    void push_front(T val){ insert(m_first, val); }

    template<typename ...Arr>
    void emplace_front(Arr&&... args){ push_front(std::forward<Arr>(args)...); }

    void reserve(size_type n){
        m_capacity = n;
        reallocate();
    }

    Array& operator=(const Array&) = default;


    /* Accessing */
    allocator_type get_allocator() const {
        return static_cast<const Allocator&>(*this);
    }

    T& front(){ return *m_first;}
    T& back() { return *m_last; }

    iterator begin()    { return m_first; }
    iterator end()      { return m_last; }
    const_iterator cbegin() const { return m_first; }
    const_iterator cend()   const { return m_last; }

    T& operator[](size_type index){
        return m_first[index];
    }
    T& at(size_type index){
        static_assert(index >= 0 || index <= m_size);
        return m_first[index];
    }

    size_type size() const { return m_size; }
    size_type capacity() const {return m_capacity; }


};

#endif //DATA_STRUCTURES_ARRAY_H
