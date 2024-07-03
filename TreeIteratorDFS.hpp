#ifndef TREEITERATORDFS_HPP
#define TREEITERATORDFS_HPP

#include "Node.hpp"
#include <stack>
#include <iostream> // For debugging output

template <typename T, int N>
class TreeIteratorDFS {
private:
    Node<T>* current;
    std::stack<Node<T>*> nodeStack;

public:
    explicit TreeIteratorDFS(Node<T>* root);
    TreeIteratorDFS& operator++();
    TreeIteratorDFS operator++(int);
    T* operator->();
    T& operator*();
    static TreeIteratorDFS end();
    bool operator!=(const TreeIteratorDFS<T, N>& other) const;
};

// Implementation of TreeIteratorDFS class

template <typename T, int N>
TreeIteratorDFS<T, N>::TreeIteratorDFS(Node<T>* root) : current(nullptr) {
    if (root) {
        nodeStack.push(root);
        std::cout << "Pushed root to stack: " << root->getValue() << std::endl;
    }
    if (!nodeStack.empty()) {
        current = nodeStack.top();
    }
}
template <typename T, int N>
TreeIteratorDFS<T,N> TreeIteratorDFS<T,N>::operator++(int){
    TreeIteratorDFS<T,N> tmp = *this;
    ++(*this);
    return tmp;
}
template <typename T, int N>
TreeIteratorDFS<T, N>& TreeIteratorDFS<T, N>::operator++() {
    if (!nodeStack.empty()) {
        Node<T>* node = nodeStack.top();
        nodeStack.pop();

        std::cout << "Popped node with value: " << node->getValue() << std::endl;

        // Push children onto the stack in reverse order to maintain DFS order
        for (int i = N - 1; i >= 0; --i) {
            if (node->children[i] != nullptr) {
                nodeStack.push(node->children[i]);
                std::cout << "Pushed child: " << node->children[i]->getValue() << std::endl;
            }
        }

        if (!nodeStack.empty()) {
            current = nodeStack.top();
        } else {
            current = nullptr;
        }
    } else {
        current = nullptr;
    }
    return *this;
}

template <typename T, int N>
T& TreeIteratorDFS<T, N>::operator*() {
    return current->getValue();
}
template <typename T, int N>
T* TreeIteratorDFS<T, N>::operator->() {
    return &(current->getValue());
}

template <typename T, int N>
TreeIteratorDFS<T, N> TreeIteratorDFS<T, N>::end() {
    return TreeIteratorDFS<T, N>(nullptr);
}

template <typename T, int N>
bool TreeIteratorDFS<T, N>::operator!=(const TreeIteratorDFS<T, N>& other) const {
    return current != other.current;
}

#endif // TREEITERATORDFS_HPP
