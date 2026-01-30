#ifndef TREE_BAG_CPP
#define TREE_BAG_CPP

#include "tree_bag.hpp"

template <typename T>
TreeBag<T>::TreeBag() : root(nullptr), itemCount(0) {
}

template <typename T>
TreeBag<T>::TreeBag(const TreeBag<T>& other) : itemCount(other.itemCount) {
    root = copyTree(other.root);
}

template <typename T>
TreeBag<T>::~TreeBag() {
    destroyTree(root);
}

template <typename T>
TreeBag<T>& TreeBag<T>::operator=(const TreeBag<T>& other) {
    if (this != &other) {
        destroyTree(root);
        itemCount = other.itemCount;
        root = copyTree(other.root);
    }
    return *this;
}

template <typename T>
typename TreeBag<T>::Node* TreeBag<T>::copyTree(Node* treePtr) const {
    if (treePtr == nullptr) {
        return nullptr;
    }
    
    Node* newNode = new Node(treePtr->item);
    newNode->count = treePtr->count;
    newNode->left = copyTree(treePtr->left);
    newNode->right = copyTree(treePtr->right);
    return newNode;
}

template <typename T>
void TreeBag<T>::destroyTree(Node* subTreePtr) {
    if (subTreePtr != nullptr) {
        destroyTree(subTreePtr->left);
        destroyTree(subTreePtr->right);
        delete subTreePtr;
    }
}

template <typename T>
void TreeBag<T>::add(const T& item) {
    root = insertNode(root, item);
    itemCount++;
}

template <typename T>
typename TreeBag<T>::Node* TreeBag<T>::insertNode(Node* subTreePtr, const T& item) {
    if (subTreePtr == nullptr) {
        return new Node(item);
    }
    
    if (item < subTreePtr->item) {
        subTreePtr->left = insertNode(subTreePtr->left, item);
    } else if (item > subTreePtr->item) {
        subTreePtr->right = insertNode(subTreePtr->right, item);
    } else {
        // Item already exists, increment count
        subTreePtr->count++;
    }
    
    return subTreePtr;
}

template <typename T>
void TreeBag<T>::remove(const T& item) {
    bool success = false;
    root = removeNode(root, item, success);
    if (success) {
        itemCount--;
    }
}

template <typename T>
typename TreeBag<T>::Node* TreeBag<T>::removeNode(Node* subTreePtr, const T& target, bool& success) {
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    }
    
    if (target < subTreePtr->item) {
        subTreePtr->left = removeNode(subTreePtr->left, target, success);
    } else if (target > subTreePtr->item) {
        subTreePtr->right = removeNode(subTreePtr->right, target, success);
    } else {
        // Found the node
        success = true;
        
        if (subTreePtr->count > 1) {
            // Multiple occurrences, just decrement count
            subTreePtr->count--;
            return subTreePtr;
        }
        
        // Only one occurrence, remove the node
        if (subTreePtr->left == nullptr) {
            Node* temp = subTreePtr->right;
            delete subTreePtr;
            return temp;
        } else if (subTreePtr->right == nullptr) {
            Node* temp = subTreePtr->left;
            delete subTreePtr;
            return temp;
        } else {
            // Node has two children
            T inorderSuccessor;
            subTreePtr->right = removeLeftmostNode(subTreePtr->right, inorderSuccessor);
            subTreePtr->item = inorderSuccessor;
            return subTreePtr;
        }
    }
    
    return subTreePtr;
}

template <typename T>
typename TreeBag<T>::Node* TreeBag<T>::removeLeftmostNode(Node* nodePtr, T& inorderSuccessor) {
    if (nodePtr->left == nullptr) {
        inorderSuccessor = nodePtr->item;
        return nodePtr->right;
    }
    nodePtr->left = removeLeftmostNode(nodePtr->left, inorderSuccessor);
    return nodePtr;
}

template <typename T>
bool TreeBag<T>::contains(const T& item) const {
    return findNode(root, item) != nullptr;
}

template <typename T>
typename TreeBag<T>::Node* TreeBag<T>::findNode(Node* treePtr, const T& target) const {
    if (treePtr == nullptr) {
        return nullptr;
    }
    
    if (target < treePtr->item) {
        return findNode(treePtr->left, target);
    } else if (target > treePtr->item) {
        return findNode(treePtr->right, target);
    } else {
        return treePtr;
    }
}

template <typename T>
int TreeBag<T>::size() const {
    return itemCount;
}

template <typename T>
bool TreeBag<T>::isEmpty() const {
    return itemCount == 0;
}

template <typename T>
void TreeBag<T>::clear() {
    destroyTree(root);
    root = nullptr;
    itemCount = 0;
}

template <typename T>
void TreeBag<T>::inorderTraverse(Node* treePtr) const {
    if (treePtr != nullptr) {
        inorderTraverse(treePtr->left);
        for (int i = 0; i < treePtr->count; i++) {
            std::cout << treePtr->item << " ";
        }
        inorderTraverse(treePtr->right);
    }
}

template <typename T>
void TreeBag<T>::display() const {
    std::cout << "TreeBag contains " << itemCount << " items: ";
    inorderTraverse(root);
    std::cout << std::endl;
}

#endif
