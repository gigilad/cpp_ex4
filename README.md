//email : gilada8892@gmail.com , id:315284554
# trees - STL, Templates, and Iterators
Overview:

This project provides a comprehensive implementation of a generic k-ary tree in C++ along with various iterators to traverse the tree in different orders. It also includes the ability to create a minimum-heap from the tree and provides a visualization tool using the SFML library.
Project Structure
# Node.hpp

Defines the basic Node class template for the tree structure. Each node can hold a value of type T and has a list of children nodes.

    Classes: Node<T>
    Key Methods:
        Node(T val): Constructor to initialize the node with a value.
        ~Node(): Destructor.
        T& getValue(): Gets the value of the node.
        void setValue(T val): Sets the value of the node.

# Complex.hpp and Complex.cpp

Defines the Complex class to handle complex numbers. This class is used to demonstrate tree operations with complex number values.

    Classes: Complex
    Key Methods:
        Complex(double r, double i): Constructor to initialize a complex number with real and imaginary parts.
        double getReal() const: Returns the real part of the complex number.
        double getImage() const: Returns the imaginary part of the complex number.
        bool operator>(const Complex& other) const: Comparison operator to check if one complex number is greater than another.
        std::ostream& operator<<(std::ostream& out, const Complex& other): Overloaded output operator for printing complex numbers.

# Tree.hpp

Defines the Tree class template, which can represent a general k-ary tree. It supports various tree traversal methods and visualization using SFML.

    Classes: Tree<T, N>
    Key Methods:
        Tree(): Constructor to initialize an empty tree.
        ~Tree(): Destructor to clear the tree.
        void add_root(Node<T>& root): Adds a root node to the tree.
        void add_sub_node(Node<T>& tree_node, Node<T>& new_node): Adds a child node to an existing node.
        auto begin_pre_order(), auto end_pre_order(): Methods to get iterators for pre-order traversal.
        auto begin_post_order(), auto end_post_order(): Methods to get iterators for post-order traversal.
        auto begin_in_order(), auto end_in_order(): Methods to get iterators for in-order traversal.
        TreeIteratorBFS<T,N> begin_bfs_scan(), TreeIteratorBFS<T,N> end_bfs_scan(): Methods to get iterators for breadth-first traversal.
        TreeIteratorDFS<T,N> begin_dfs_scan(), TreeIteratorDFS<T,N> end_dfs_scan(): Methods to get iterators for depth-first traversal.
        HeapIterator<T> myHeap(): Converts the tree into a heap and returns an iterator.
        void drawTree(sf::RenderWindow& window, Node<T>* node, int x, int y, int horizontal_gap, sf::Font& font): Visualizes the tree using SFML.

# Iterators

The project includes several iterator classes to traverse the tree in different orders:

    Breadth-First Search (BFS) Iterator:
        Class: TreeIteratorBFS<T, N>
        Key Methods: TreeIteratorBFS(Node<T>* root), TreeIteratorBFS& operator++(), T& operator*()

    Depth-First Search (DFS) Iterator:
        Class: TreeIteratorDFS<T, N>
        Key Methods: TreeIteratorDFS(Node<T>* root), TreeIteratorDFS& operator++(), T& operator*()

    In-Order Iterator (specific to binary trees):
        Class: TreeIteratorInOrder<T>
        Key Methods: TreeIteratorInOrder(Node<T>* root), TreeIteratorInOrder& operator++(), T& operator*()

    Pre-Order Iterator (specific to binary trees):
        Class: TreeIteratorPreOrder<T>
        Key Methods: TreeIteratorPreOrder(Node<T>* root), TreeIteratorPreOrder& operator++(), T& operator*()

    Post-Order Iterator (specific to binary trees):
        Class: TreeIteratorPostOrder<T>
        Key Methods: TreeIteratorPostOrder(Node<T>* root), TreeIteratorPostOrder& operator++(), T& operator*()

# HeapIterator.hpp

Defines the HeapIterator class template, which allows iteration over a tree that has been converted to a min-heap.

    Classes: HeapIterator<T>
    Key Methods:
        HeapIterator(const std::vector<T>& heap, std::size_t i = 0): Constructor to initialize the iterator with a heap.
        T operator*() const: Dereference operator to get the current heap element.
        bool operator!=(const HeapIterator& other) const: Comparison operator.
        HeapIterator& operator++(): Increment operator.
        static HeapIterator end(const std::vector<T>& heap): Returns an iterator pointing to the end of the heap.

# Library Usage
SFML

This project uses the SFML (Simple and Fast Multimedia Library) for visualizing the tree structure. SFML is a simple-to-use and portable API for multimedia applications.

    Drawing Trees: The drawTree function in Tree.hpp uses SFML to render nodes and edges of the tree.
    Dependencies: Ensure you have the SFML library installed. The required libraries are sfml-graphics, sfml-window, and sfml-system.


