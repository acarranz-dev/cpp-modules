#ifndef TREE_BAG_HPP
#define TREE_BAG_HPP

#include "bag.hpp"
#include <iostream>

template <typename T>
class TreeBag : public Bag<T> {
protected:
    struct Node {
        T item;
        Node* left;
        Node* right;
        int count; // Number of occurrences of this item
        
        Node(const T& anItem) : item(anItem), left(nullptr), right(nullptr), count(1) {}
    };
    
    Node* root;
    int itemCount;
    
    Node* copyTree(Node* treePtr) const;
    void destroyTree(Node* subTreePtr);
    Node* insertNode(Node* subTreePtr, const T& item);
    Node* removeNode(Node* subTreePtr, const T& target, bool& success);
    Node* removeLeftmostNode(Node* nodePtr, T& inorderSuccessor);
    Node* findNode(Node* treePtr, const T& target) const;
    void inorderTraverse(Node* treePtr) const;
    
public:
    TreeBag();
    TreeBag(const TreeBag<T>& other);
    virtual ~TreeBag();
    TreeBag<T>& operator=(const TreeBag<T>& other);
    
    virtual void add(const T& item);
    virtual void remove(const T& item);
    virtual bool contains(const T& item) const;
    virtual int size() const;
    virtual bool isEmpty() const;
    virtual void clear();
    
    void display() const;
};

#include "tree_bag.cpp"
#endif
