//
// Created by marten on 27-09-20.
//

#ifndef DATA_STRUCTURES_BTREE_H
#define DATA_STRUCTURES_BTREE_H

template<typename T>
struct Node {
    T value;
    Node *left, *right;
};

template<typename T>
class BTree{
    Node* m_start;
};

template<typename T, class Pred>
class BinarySearchTree{

};

#endif //DATA_STRUCTURES_BTREE_H
