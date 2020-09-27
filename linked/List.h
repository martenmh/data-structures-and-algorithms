#ifndef DATA_STRUCTURES_LIST_H
#define DATA_STRUCTURES_LIST_H

#include <memory>
#include <cassert>
template<typename T>
struct Node {
    T value;
    Node *prev, *next;
};
template<typename T>
struct SingleNode {
    T value;
    SingleNode* next;
};

// Only support next
struct IsSingleNode {

};
// Support prev and next
struct IsDoubleNode {

};

template <class T, class Allocator = std::allocator<Node<T>>>
class List : private Allocator {
public:
    using node = Node<T>;
    using value_type = T;
    using alloc_tr   = std::allocator_traits<Allocator>;
    using size_type         = typename alloc_tr::size_type;
    using difference_type   = typename alloc_tr::difference_type;

    class list_iterator {
        typedef typename List<T>::difference_type difference_type;
        typedef typename List<T>::value_type value_type;
        using reference = T&;
        using pointer = T*;
        typedef std::random_access_iterator_tag iterator_category; //or another tag
        node* ptr;
    public:
        explicit list_iterator(node* node) : ptr(node){}

        list_iterator operator++(int){
            list_iterator tmp = iterator(ptr);
            ptr = ptr->next;
            return tmp;
        }
        list_iterator& operator++(){
            ptr = ptr->next;
            return *this;
        }
        reference operator=(node* n){
            ptr = n;
            return *this;
        }
        reference operator=(const list_iterator& it){
            ptr = it.ptr;
            return ptr->value;
        }
        bool operator==(const list_iterator& it){ return ptr == it.ptr; }
        bool operator!=(const list_iterator& it){ return ptr != it.ptr; }
        reference operator*() const { return ptr->value; }
        pointer data(){return ptr;}
        pointer operator->() const { return ptr; }
        reference operator[](size_type n) const {
            node* tmp = ptr;
            for(size_type i = 0; i != n; i++){
                tmp = ptr->next;
            }
            return tmp;
        }
    };

    using iterator          = typename alloc_tr::pointer;
    using const_iterator    = typename alloc_tr::const_pointer;
    using allocator_type    = Allocator;

    node* m_start;
    node* m_end;
    size_type m_size;


    iterator construct(T val = T(), node* next = nullptr){
        iterator tmp = alloc_tr::allocate(*this, sizeof(node));
        alloc_tr::construct(*this, tmp, node{val, next});
        return tmp;
    }
    void destruct(iterator n){
        alloc_tr::destroy(*this, n);
        alloc_tr::deallocate(*this, n, sizeof(node));
    }

public:
    explicit List(size_type n = 0, const T& x = T()){
        if(n != 0){
            m_start = construct(x);
            node* prev = m_start;
            node* curr = nullptr;
            for(int i = 0; i != n-1; i++){
                curr = construct(x);
                prev->next = curr;
                prev = prev->next;
            }
            m_end = curr;
            m_size = n;
        } else {
            m_start = nullptr;
            m_end = nullptr;
            m_size = 0;
        }
    }
    list_iterator begin(){ return list_iterator(m_start); }
    list_iterator end(){ return list_iterator(m_end); }
    T& front(){ return m_start->value; }
    T& back(){ return m_end->value; }

    ~List(){
        node* next = m_start;
        node* curr = nullptr;
        for(int i = 0; i != m_size; i++){
            curr = next;
            next = next->next;
            destruct(curr);
        }
    }

    void insert(size_type n, T val){
        node* prev = getNode(n-1, m_start);
        node* next = prev->next;
        node* curr = construct(val);
        curr->next = next;
        prev->next = curr;
        m_size++;
    }
    void remove(size_type n){
        assert(n != 0);
        node* prev = getNode(n-1, m_start);
        node* curr = prev->next;
        node* next = curr->next;
        prev->next = next;
        destruct(curr);
        m_size--;
    }
    void push_front(T val){}

    void push_back(T val){
        m_end->next = construct(val);
        m_size++;
    }
    void pop_front(){}
    void pop_back(T val){}

    template<typename ...Arr>
    void emplace_back(Arr&& ...args){
        push_back(std::forward<Arr>(args)...);
    }
    template<typename ...Arr>
    void emplace_front(Arr&& ...args){
        push_back(std::forward<Arr>(args)...);
    }
    template<typename ...Arr>
    void emplace(size_type n, Arr&& ...args){
        insert(n, std::forward<Arr>(args)...);
    }

    T& operator[](size_type index){
        return getNode(index, m_start)->value;
    }
    T& at(size_type index){
        static_assert(index >= 0 && index <= m_size);
        return getNode(index, m_start)->value;
    }

    node* getNode(size_type index, node* start){
        node* ptr = start;
        for(size_type i = 0; i < index; i++){
            if(ptr->next){
                ptr = ptr->next;
            } else throw;
        }
        return ptr;
    }

};

#endif //DATA_STRUCTURES_LIST_H
