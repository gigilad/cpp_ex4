#ifndef TREEITERATORPREORDER_HPP
#define TREEITERATORPREORDER_HPP

#include "Node.hpp"
#include <stack>
#include <iostream> // For debugging output

template <typename T>
class TreeIteratorPreOrder {
private:
    Node<T>* current;
    std::stack<Node<T>*> stack;

public:
    explicit TreeIteratorPreOrder(Node<T>* root);
    TreeIteratorPreOrder& operator++();
    TreeIteratorPreOrder operator++(int);
    T* operator->();
    T& operator*();
    static TreeIteratorPreOrder end();
    bool operator!=(const TreeIteratorPreOrder<T>& other) const;
};

// Implementation of TreeIteratorPreOrder class

template <typename T>
TreeIteratorPreOrder<T>::TreeIteratorPreOrder(Node<T>* root) : current(root) {
    if (root) {
        stack.push(root);
        std::cout << "Pushed root to stack: " << root->getValue() << std::endl;
    }
}
template <typename T>
TreeIteratorPreOrder<T> TreeIteratorPreOrder<T>::operator++(int){
    TreeIteratorPreOrder<T> tmp = *this;
    ++(*this);
    return tmp;
}
template <typename T>
TreeIteratorPreOrder<T>& TreeIteratorPreOrder<T>::operator++() {
    if (!stack.empty()) {
        Node<T>* currentNode = stack.top();
        stack.pop();
        std::cout << "Visiting node with value: " << currentNode->getValue() << std::endl;

        // Push children onto stack in reverse order
        for (int i = currentNode->children.size() - 1; i >= 0; --i) {
            if (currentNode->children[i]) {
                stack.push(currentNode->children[i]);
            }
        }

        if (!stack.empty()) {
            current = stack.top();
        } else {
            current = nullptr;
        }
    }

    return *this;
}

template <typename T>
T& TreeIteratorPreOrder<T>::operator*() {
    return current->getValue();
}
template <typename T>
T* TreeIteratorPreOrder<T>::operator->() {
    return &(current->getValue());
}
template <typename T>
TreeIteratorPreOrder<T> TreeIteratorPreOrder<T>::end() {
    return TreeIteratorPreOrder<T>(nullptr);
}

template <typename T>
bool TreeIteratorPreOrder<T>::operator!=(const TreeIteratorPreOrder<T>& other) const {
    return current != other.current;
}

#endif // TREEITERATORPREORDER_HPP
