#ifndef TREEITERATORINORDER_HPP
#define TREEITERATORINORDER_HPP

#include "Node.hpp"
#include <stack>
#include <iostream> // For debugging output

template <typename T>
class TreeIteratorInOrder {
private:
    Node<T>* current;
    std::stack<Node<T>*> stack;

    void pushLeftChildren(Node<T>* node);

public:
    explicit TreeIteratorInOrder(Node<T>* root);
    TreeIteratorInOrder& operator++();
    T* operator->();
    TreeIteratorInOrder operator++(int);
    T& operator*();
    static TreeIteratorInOrder end();
    bool operator!=(const TreeIteratorInOrder<T>& other) const;
};

// Implementation of TreeIteratorInOrder class

template <typename T>
TreeIteratorInOrder<T>::TreeIteratorInOrder(Node<T>* root) : current(nullptr) {
    pushLeftChildren(root);
    if (!stack.empty()) {
        current = stack.top();
    }
}

template <typename T>
void TreeIteratorInOrder<T>::pushLeftChildren(Node<T>* node) {
    while (node != nullptr) {
        stack.push(node);
        node = node->children[0]; // Assuming left child is at index 0
    }
}
template <typename T>
TreeIteratorInOrder<T> TreeIteratorInOrder<T>::operator++(int){
    TreeIteratorInOrder<T> tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
TreeIteratorInOrder<T>& TreeIteratorInOrder<T>::operator++() {
    if (!stack.empty()) {
        Node<T>* node = stack.top();
        stack.pop();

        if (node->children.size() == 2 && node->children[1] != nullptr) { // Check right child
            pushLeftChildren(node->children[1]); // Assuming right child is at index 1
        }

        if (!stack.empty()) {
            current = stack.top();
        } else {
            current = nullptr;
        }
    } else {
        current = nullptr;
    }
    return *this;
}

template <typename T>
T& TreeIteratorInOrder<T>::operator*() {
    return current->getValue();
}

template <typename T>
TreeIteratorInOrder<T> TreeIteratorInOrder<T>::end() {
    return TreeIteratorInOrder<T>(nullptr);
}
template <typename T>
T* TreeIteratorInOrder<T>::operator->() {
    return &(current->getValue());
}
template <typename T>
bool TreeIteratorInOrder<T>::operator!=(const TreeIteratorInOrder<T>& other) const {
    return current != other.current;
}

#endif // TREEITERATORINORDER_HPP
