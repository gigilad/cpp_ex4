//email : gilada8892@gmail.com , id:315284554

#ifndef TREEITERATORBFS_HPP
#define TREEITERATORBFS_HPP

#include "Node.hpp"
#include <queue>
#include <iostream> // For debugging output

template <typename T, int N>
class TreeIteratorBFS {
private:
    Node<T>* current;
    std::queue<Node<T>*> nodeQueue;

public:
    explicit TreeIteratorBFS(Node<T>* root);
    TreeIteratorBFS& operator++();
    TreeIteratorBFS operator++(int);
    T& operator*();
    T* operator->();
    static TreeIteratorBFS end();
    bool operator!=(const TreeIteratorBFS<T, N>& other) const;
};

// Implementation of TreeIteratorBFS class

template <typename T, int N>
TreeIteratorBFS<T, N>::TreeIteratorBFS(Node<T>* root) : current(nullptr) {
    if (root) {
        nodeQueue.push(root);
    }
    if (!nodeQueue.empty()) {
        current = nodeQueue.front();
    }
}
template <typename T, int N>
TreeIteratorBFS<T,N> TreeIteratorBFS<T,N>::operator++(int){
    TreeIteratorBFS<T,N> tmp = *this;
    ++(*this);
    return tmp;

}
template <typename T, int N>
T* TreeIteratorBFS<T, N>::operator->() {
    return &(current->getValue());
}
template <typename T, int N>
TreeIteratorBFS<T, N>& TreeIteratorBFS<T, N>::operator++() {
    if (!nodeQueue.empty()) {
        Node<T>* node = nodeQueue.front();
        nodeQueue.pop();


        // Enqueue all non-null children of the current node
        for (size_t i = 0; i < N; ++i) {
            if (node->children[i] != nullptr) {
                nodeQueue.push(node->children[i]);
                // std::cout << "Enqueued child: " << node->children[i]->value << std::endl;
            }
        }

        if (!nodeQueue.empty()) {
            current = nodeQueue.front();
        } else {
            current = nullptr;
        }
    } else {
        current = nullptr;
    }
    return *this;
}

template <typename T, int N>
T& TreeIteratorBFS<T, N>::operator*() {
    return current->getValue();
}

template <typename T, int N>
TreeIteratorBFS<T, N> TreeIteratorBFS<T, N>::end() {
    return TreeIteratorBFS<T, N>(nullptr);
}

template <typename T, int N>
bool TreeIteratorBFS<T, N>::operator!=(const TreeIteratorBFS<T, N>& other) const {
    return current != other.current;
}

#endif // TREEITERATORBFS_HPP
