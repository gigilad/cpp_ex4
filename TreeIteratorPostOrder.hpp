#ifndef TREEITERATORPOSTORDER_HPP
#define TREEITERATORPOSTORDER_HPP

#include "Node.hpp"
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream> // For debugging output

template <typename T>
class TreeIteratorPostOrder {
private:
    Node<T>* current;
    std::stack<Node<T>*> stack;
    std::vector<Node<T>*> visitStack;

public:
    explicit TreeIteratorPostOrder(Node<T>* root);
    TreeIteratorPostOrder& operator++();
    TreeIteratorPostOrder operator++(int);
    T* operator->();
    T& operator*();
    static TreeIteratorPostOrder end();
    bool operator!=(const TreeIteratorPostOrder<T>& other) const;
};

// Implementation of TreeIteratorPostOrder class

template <typename T>
TreeIteratorPostOrder<T>::TreeIteratorPostOrder(Node<T>* root) : current(root) {
    if (root) {
        stack.push(root);
        std::cout << "Pushed root to stack: " << root->getValue() << std::endl;
        ++(*this);
    } else {
        current = nullptr;
    }
}
template <typename T>
TreeIteratorPostOrder<T> TreeIteratorPostOrder<T>::operator++(int){
    TreeIteratorPostOrder<T> tmp = *this;
    ++(*this);
    return tmp;
}
template <typename T>
TreeIteratorPostOrder<T>& TreeIteratorPostOrder<T>::operator++() {
    while (!stack.empty()) {
        Node<T>* currentNode = stack.top();

        // Check if all children have been visited
        bool allChildrenVisited = true;
        for (auto child : currentNode->children) {
            if (child != nullptr && std::find(visitStack.begin(), visitStack.end(), child) == visitStack.end()) {
                allChildrenVisited = false;
                break;
            }
        }

        if (allChildrenVisited) {
            // Pop this node, all children have been visited
            stack.pop();
            visitStack.push_back(currentNode);
            current = currentNode;
            return *this;
        } else {
            // Push non-visited children onto the stack in reverse order
            for (int i = currentNode->children.size() - 1; i >= 0; --i) {
                if (currentNode->children[i] != nullptr && std::find(visitStack.begin(), visitStack.end(), currentNode->children[i]) == visitStack.end()) {
                    stack.push(currentNode->children[i]);
                }
            }
        }
    }

    current = nullptr; // End of traversal
    return *this;
}

template <typename T>
T& TreeIteratorPostOrder<T>::operator*() {
    return current->getValue();
}
template <typename T>
T* TreeIteratorPostOrder<T>::operator->() {
    return &(current->getValue());
}

template <typename T>
TreeIteratorPostOrder<T> TreeIteratorPostOrder<T>::end() {
    return TreeIteratorPostOrder<T>(nullptr);
}

template <typename T>
bool TreeIteratorPostOrder<T>::operator!=(const TreeIteratorPostOrder<T>& other) const {
    return current != other.current;
}

#endif // TREEITERATORPOSTORDER_HPP
