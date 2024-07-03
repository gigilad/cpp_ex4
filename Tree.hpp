//email : gilada8892@gmail.com , id:315284554
#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <vector>
#include <algorithm> // For std::make_heap
#include "HeapIterator.hpp"
#include "TreeIteratorBFS.hpp"
#include "TreeIteratorDFS.hpp"
#include "TreeIteratorInOrder.hpp"
#include "TreeIteratorPostOrder.hpp"
#include "TreeIteratorPreOrder.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>



template <typename T, int N=2>
class Tree {
private:
    Node<T>* root;
    void clearTree(Node<T>* node);
    void collectNodes(Node<T>* node);

public:
    std::vector<T> heap; // Vector to store tree nodes for heap operations
    Tree();  // Constructor declaration
    ~Tree();  // Destructor declaration
    Node<T>* findNode(Node<T>& node);
    template <typename U, int k>
    friend std::ostream& operator<<(std::ostream& os, Tree<U, k>& tree);
    void drawTree(sf::RenderWindow& window, Node<T>* node, int x, int y, int horizontal_gap, sf::Font& font);
    void add_root(Node<T>& root);
    void add_sub_node(Node<T>& tree_node , Node<T>& new_node);
    auto begin_pre_order();
    auto end_pre_order();
    auto begin_post_order();
    auto end_post_order();
    auto begin_in_order();
    auto end_in_order();

    TreeIteratorBFS<T,N> begin_bfs_scan();
    TreeIteratorBFS<T,N> end_bfs_scan();
    TreeIteratorDFS<T,N> begin_dfs_scan();
    TreeIteratorDFS<T,N> end_dfs_scan();


    HeapIterator<T> myHeap(); // Method to create a minimum heap and return an iterator
};

template <typename T, int N>
Tree<T, N>::Tree() : root(nullptr) {}

template <typename T, int N>
Tree<T, N>::~Tree() {
    clearTree(root);
}

template <typename T, int N>
void Tree<T, N>::add_root(Node<T> &node)
{
    if (root != nullptr)
    {
        delete root; // Remove existing root if any
    }
    root = new Node<T>(node.getValue()); // Allocate new node for root
    root->children.resize(N, nullptr);
    std::cout << "Root added with value " << root->getValue() << " children size is " << root->children.size() << std::endl;
}

template <typename T, int N>
void Tree<T, N>::add_sub_node(Node<T> &tree_node, Node<T> &new_node)
{
    Node<T> *node = findNode(tree_node);
    if (node != nullptr)
    {
        std::cout << "Found your node with value " << node->getValue() << std::endl;
        for (size_t i = 0; i < N; i++)
        {
            if (node->children[i] == nullptr)
            {
                node->children[i] = new Node<T>(new_node.getValue()); // Allocate new node for child
                std::cout << "Node added with value " << new_node.getValue() << std::endl;
                node->children[i]->children.resize(N, nullptr);
                return;
            }
        }
    }
    throw std::logic_error("Didn't find node");
}

template <typename T, int N>
Node<T> *Tree<T, N>::findNode(Node<T> &node)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    std::queue<Node<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        Node<T> *curr = q.front();
        q.pop();

        if (curr->getValue() == node.getValue())
        {
            std::cout << " found it " << curr->children.size() << std::endl;
            return curr;
        }

        for (auto child : curr->children)
        {
            if (child != nullptr)
            {
                q.push(child);
            }
        }
    }
    return nullptr;
}

template <typename T, int N>
auto Tree<T, N>::begin_pre_order() {
    if constexpr (N == 2) {
        return TreeIteratorPreOrder<T>(root);
    } else {
        return TreeIteratorDFS<T, N>(root);
    }
}

template <typename T, int N>
auto Tree<T, N>::end_pre_order() {
    if constexpr (N == 2) {
        return TreeIteratorPreOrder<T>::end();
    } else {
        return TreeIteratorDFS<T, N>::end();
    }
}

template <typename T, int N>
auto Tree<T, N>::begin_post_order() {
    if constexpr (N == 2) {
        return TreeIteratorPostOrder<T>(root);
    } else {
        return TreeIteratorDFS<T, N>(root);
    }
}

template<typename T,int N>
auto Tree<T,N>::end_post_order(){
    if constexpr (N == 2) {
        return TreeIteratorPostOrder<T>::end();
    } else {
        return TreeIteratorDFS<T, N>::end();
    }
}

template <typename T, int N>
auto Tree<T, N>::begin_in_order() {
    if constexpr (N == 2) {
        return TreeIteratorInOrder<T>(root);
    } else {
        return TreeIteratorDFS<T, N>(root);
    }
}

template<typename T,int N>
auto Tree<T,N>::end_in_order(){
    if constexpr (N == 2) {
        return TreeIteratorInOrder<T>::end();
    } else {
        return TreeIteratorDFS<T, N>::end();
    }
}

template<typename T,int N>
TreeIteratorBFS<T,N> Tree<T,N>::begin_bfs_scan(){
    return TreeIteratorBFS<T,N>(root);
}

template<typename T,int N>
TreeIteratorBFS<T,N> Tree<T,N>::end_bfs_scan(){
    return TreeIteratorBFS<T,N>::end();
}

template<typename T,int N>
TreeIteratorDFS<T,N> Tree<T,N>::begin_dfs_scan(){
    return TreeIteratorDFS<T,N>(root);
}

template<typename T,int N>
TreeIteratorDFS<T,N> Tree<T,N>::end_dfs_scan(){
    return TreeIteratorDFS<T,N>::end();
}

template <typename T, int N>
void Tree<T, N>::clearTree(Node<T>* node) {
    if (node != nullptr) {
        for (auto child : node->children) {
            clearTree(child);
        }
        delete node;
    }
}

template <typename T, int N>
HeapIterator<T> Tree<T, N>::myHeap() {
    if constexpr (N != 2) {
        throw std::logic_error("Heapification is not supported for N != 2 in this tree implementation.");
    } else {
        // Collect all nodes into the heap vector
        collectNodes(root);

        // Use std::make_heap to create a minimum heap
        std::make_heap(heap.begin(), heap.end(), std::greater<T>());

        // Return a heap iterator
        return HeapIterator<T>(heap);
    }
}

// Helper function to collect nodes into the heap vector
template <typename T, int N>
void Tree<T, N>::collectNodes(Node<T>* node) {
    if (node != nullptr) {
        heap.push_back(node->getValue());
        for (auto child : node->children) {
            collectNodes(child);
        }
    }
}
template <typename T, int N>
void Tree<T, N>::drawTree(sf::RenderWindow& window, Node<T>* node, int x, int y, int horizontal_gap, sf::Font& font) {
    if (!node) return;

    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Cyan);
    circle.setOutlineThickness(2);
    circle.setOutlineColor(sf::Color::White);
    circle.setPosition(x, y);
    window.draw(circle);

    T value = node->getValue();
    std::ostringstream oss;
    oss.precision(1);
    oss << std::fixed << value;
    std::string text = oss.str();

    sf::Text textObject(text, font, 20);
    textObject.setFillColor(sf::Color::Black);
    sf::FloatRect textBounds = textObject.getLocalBounds();
    textObject.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    textObject.setPosition(x + circle.getRadius(), y + circle.getRadius());
    window.draw(textObject);

    auto children = node->children;
    int num_children = children.size();
    if (num_children > 0) {
        for (int i = 0; i < num_children; ++i) {
            if (children[i]) {
                int child_x = x - horizontal_gap / 2 + i * horizontal_gap;
                int child_y = y + 100;

                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x + circle.getRadius(), y + 2 * circle.getRadius())),
                    sf::Vertex(sf::Vector2f(child_x + circle.getRadius(), child_y))
                };
                line[0].color = sf::Color::Black;
                line[1].color = sf::Color::Black;
                window.draw(line, 2, sf::Lines);

                drawTree(window, children[i], child_x, child_y, horizontal_gap / 2, font);
            }
        }
    }
}

// Definition of operator<<
template <typename T, int k>
std::ostream& operator<<(std::ostream& os, Tree<T, k>& tree) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tree Example");
    // Load the font
    sf::Font font;
    if (!font.loadFromFile("./OpenSans-Bold.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        // Exit if the font is not loaded
    } else {
        window.clear(sf::Color::White);
        tree.drawTree(window, tree.root, 400, 50, 200, font);
        window.display();
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }
    }
    return os;
}
#endif // TREE_HPP
