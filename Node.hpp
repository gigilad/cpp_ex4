#ifndef NODE_HPP
#define NODE_HPP

#include <vector> // Include necessary header

template <typename T>
class Node
{
private:
    T value;

public:
    std::vector<Node<T>*> children; // Use Node<T>* for the vector
    Node(T val);
    ~Node();
    T& getValue();
    void setValue(T val);

};
template <typename T>
Node<T>::Node(T val) : value(val) {}

template <typename T>
Node<T>::~Node() {}

template <typename T>
T& Node<T>::getValue(){
    return value;
}
template <typename T>
void Node<T>::setValue(T val) {
    value = val;
}

// Include the template implementation file


#endif // NODE_HPP
