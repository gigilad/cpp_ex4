//email : gilada8892@gmail.com , id:315284554

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "Node.hpp"
#include "Tree.hpp"
#include <vector>
#include "Complex.hpp"

TEST_CASE("check preOrder iterator"){
    Tree<double,2> tree;
    Node<double> root_node = Node<double>(1.1);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    std::vector<double> excpectedVector = {1.1,1.2,1.4,1.5,1.3,1.6};
    std::vector<double> afterPreOrder = {};
    auto it =tree.begin_pre_order();
    for(;it != tree.end_pre_order();++it){
        afterPreOrder.push_back(*it);
    }
    for (size_t i = 0; i < excpectedVector.size(); i++)
    {
        CHECK(excpectedVector[i] == afterPreOrder[i]);
    }
    // Check the Tree<int , N>2 > return an dfs iterator
    Tree<int,3> tree1;
    Node<int> root_node1 = Node<int>(1);
    Node<int> v1 = Node<int>(2);
    Node<int> v2 = Node<int>(3);
    Node<int> v3 = Node<int>(4);
    Node<int> v4 = Node<int>(5);
    Node<int> v5 = Node<int>(6);
    Node<int> v6 = Node<int>(7);
    Node<int> v7 = Node<int>(8);
    Node<int> v8 = Node<int>(9);

    tree1.add_root(root_node1);
    tree1.add_sub_node(root_node1, v1);
    tree1.add_sub_node(root_node1, v2);
    tree1.add_sub_node(root_node1, v3);
    tree1.add_sub_node(v1, v4);
    tree1.add_sub_node(v2, v5);
    tree1.add_sub_node(v3, v6);
    tree1.add_sub_node(v2, v7);
    tree1.add_sub_node(v3, v8);

    std::vector<int> excpectedVector1 = {1,2,5,3,6,8,4,7,9};
    std::vector<int> afterDFS = {};
    auto it1 =tree1.begin_pre_order();
    for(;it1 != tree1.end_pre_order();++it1){
        afterDFS.push_back(*it1);
    }
    for (size_t i = 0; i < excpectedVector1.size(); i++)
    {
        CHECK(excpectedVector1[i] == afterDFS[i]);
    }
}
TEST_CASE("check inOrder iterator"){
    Tree<double,2> tree;
    Node<double> root_node = Node<double>(1.1);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    std::vector<double> excpectedVector = {1.4,1.2,1.5,1.1,1.6,1.3};
    std::vector<double> afterinOrder = {};
    auto it =tree.begin_in_order();
    for(;it != tree.end_in_order();++it){
        afterinOrder.push_back(*it);
    }
    for (size_t i = 0; i < excpectedVector.size(); i++)
    {
        CHECK(excpectedVector[i] == afterinOrder[i]);
    }
     Tree<int,3> tree1;
    Node<int> root_node1 = Node<int>(1);
    Node<int> v1 = Node<int>(2);
    Node<int> v2 = Node<int>(3);
    Node<int> v3 = Node<int>(4);
    Node<int> v4 = Node<int>(5);
    Node<int> v5 = Node<int>(6);
    Node<int> v6 = Node<int>(7);
    Node<int> v7 = Node<int>(8);
    Node<int> v8 = Node<int>(9);

    tree1.add_root(root_node1);
    tree1.add_sub_node(root_node1, v1);
    tree1.add_sub_node(root_node1, v2);
    tree1.add_sub_node(root_node1, v3);
    tree1.add_sub_node(v1, v4);
    tree1.add_sub_node(v2, v5);
    tree1.add_sub_node(v3, v6);
    tree1.add_sub_node(v2, v7);
    tree1.add_sub_node(v3, v8);

    std::vector<int> excpectedVector1 = {1,2,5,3,6,8,4,7,9};
    std::vector<int> afterDFS = {};
    auto it1 =tree1.begin_in_order();
    for(;it1 != tree1.end_in_order();++it1){
        afterDFS.push_back(*it1);
    }
    for (size_t i = 0; i < excpectedVector1.size(); i++)
    {
        CHECK(excpectedVector1[i] == afterDFS[i]);
    }
}
TEST_CASE("check postOrder iterator"){
    Tree<double,2> tree;
    Node<double> root_node = Node<double>(1.1);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    std::vector<double> excpectedVector = {1.4,1.5,1.2,1.6,1.3,1.1};
    std::vector<double> afterPostOrder = {};
    auto it =tree.begin_post_order();
    for(;it != tree.end_post_order();++it){
        afterPostOrder.push_back(*it);
    }
    for (size_t i = 0; i < excpectedVector.size(); i++)
    {
        CHECK(excpectedVector[i] == afterPostOrder[i]);
    }
    Tree<int,3> tree1;
    Node<int> root_node1 = Node<int>(1);
    Node<int> v1 = Node<int>(2);
    Node<int> v2 = Node<int>(3);
    Node<int> v3 = Node<int>(4);
    Node<int> v4 = Node<int>(5);
    Node<int> v5 = Node<int>(6);
    Node<int> v6 = Node<int>(7);
    Node<int> v7 = Node<int>(8);
    Node<int> v8 = Node<int>(9);

    tree1.add_root(root_node1);
    tree1.add_sub_node(root_node1, v1);
    tree1.add_sub_node(root_node1, v2);
    tree1.add_sub_node(root_node1, v3);
    tree1.add_sub_node(v1, v4);
    tree1.add_sub_node(v2, v5);
    tree1.add_sub_node(v3, v6);
    tree1.add_sub_node(v2, v7);
    tree1.add_sub_node(v3, v8);

    std::vector<int> excpectedVector1 = {1,2,5,3,6,8,4,7,9};
    std::vector<int> afterDFS = {};
    auto it1 =tree1.begin_post_order();
    for(;it1 != tree1.end_post_order();++it1){
        afterDFS.push_back(*it1);
    }
    for (size_t i = 0; i < excpectedVector1.size(); i++)
    {
        CHECK(excpectedVector1[i] == afterDFS[i]);
    }
}
TEST_CASE("check BFS iterator"){
    Tree<double,2> tree;
    Node<double> root_node = Node<double>(1.1);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    std::vector<double> excpectedVector = {1.1,1.2,1.3,1.4,1.5,1.6};
    std::vector<double> afterBfs = {};
    auto it =tree.begin_bfs_scan();
    for(;it != tree.end_bfs_scan();++it){
        afterBfs.push_back(*it);
    }
    for (size_t i = 0; i < excpectedVector.size(); i++)
    {
        CHECK(excpectedVector[i] == afterBfs[i]);
    }
    Tree<int,3> tree1;
    Node<int> root_node1 = Node<int>(1);
    Node<int> v1 = Node<int>(2);
    Node<int> v2 = Node<int>(3);
    Node<int> v3 = Node<int>(4);
    Node<int> v4 = Node<int>(5);
    Node<int> v5 = Node<int>(6);
    Node<int> v6 = Node<int>(7);


    tree1.add_root(root_node1);
    tree1.add_sub_node(root_node1, v1);
    tree1.add_sub_node(v1, v2);
    tree1.add_sub_node(v2, v3);
    tree1.add_sub_node(v3, v4);
    tree1.add_sub_node(v1, v5);
    tree1.add_sub_node(v1, v6);


    std::vector<int> excpectedVector1 = {1,2,3,6,7,4,5};
    std::vector<int> afterBFS = {};
    auto it1 =tree1.begin_bfs_scan();
    for(;it1 != tree1.end_bfs_scan();++it1){
        afterBFS.push_back(*it1);
    }
    for (size_t i = 0; i < excpectedVector1.size(); i++)
    {
        CHECK(excpectedVector1[i] == afterBFS[i]);
    }
}

TEST_CASE("check DFS iterator"){
    Tree<double,2> tree;
    Node<double> root_node = Node<double>(1.1);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    std::vector<double> excpectedVector = {1.1,1.2,1.4,1.5,1.3,1.6};
    std::vector<double> afterDfs = {};
    auto it =tree.begin_dfs_scan();
    for(;it != tree.end_dfs_scan();++it){
        afterDfs.push_back(*it);
    }
    for (size_t i = 0; i < excpectedVector.size(); i++)
    {
        CHECK(excpectedVector[i] == afterDfs[i]);
    }

    Tree<int,3> tree1;
    Node<int> root_node1 = Node<int>(1);
    Node<int> v1 = Node<int>(2);
    Node<int> v2 = Node<int>(3);
    Node<int> v3 = Node<int>(4);
    Node<int> v4 = Node<int>(5);
    Node<int> v5 = Node<int>(6);
    Node<int> v6 = Node<int>(7);


    tree1.add_root(root_node1);
    tree1.add_sub_node(root_node1, v1);
    tree1.add_sub_node(v1, v2);
    tree1.add_sub_node(v2, v3);
    tree1.add_sub_node(v3, v4);
    tree1.add_sub_node(v1, v5);
    tree1.add_sub_node(v1, v6);


    std::vector<int> excpectedVector1 = {1,2,3,4,5,6,7};
    std::vector<int> afterDFS = {};
    auto it1 =tree1.begin_dfs_scan();
    for(;it1 != tree1.end_dfs_scan();++it1){
        afterDFS.push_back(*it1);
    }
    for (size_t i = 0; i < excpectedVector1.size(); i++)
    {
        CHECK(excpectedVector1[i] == afterDFS[i]);
    }
}

TEST_CASE("Catch error when trying make heap on not a binary tree"){
    Tree<int,4> tree1;
    Node<int> root_node1 = Node<int>(1);
    Node<int> v1 = Node<int>(2);
    Node<int> v2 = Node<int>(3);
    Node<int> v3 = Node<int>(4);

    tree1.add_root(root_node1);
    tree1.add_sub_node(root_node1, v1);
    tree1.add_sub_node(v1, v2);
    try
    {
        tree1.myHeap();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


}
TEST_CASE("Add Root") {
    Tree<int, 3> tree;
    Node<int> root_node(10);
    tree.add_root(root_node);
    Node<int> * foundNode = tree.findNode(root_node);
    CHECK(foundNode->getValue() == 10);
}
TEST_CASE("Add Sub-node to Non-existing Node") {
    Tree<int, 3> tree;
    Node<int> root_node(10), non_existent_node(999), new_node(20);

    tree.add_root(root_node);
    CHECK_THROWS_AS(tree.add_sub_node(non_existent_node, new_node), std::logic_error);
}
TEST_CASE("Add Sub-node to Full Node") {
    Tree<int, 2> tree;  // Binary tree for simplicity
    Node<int> root_node(10), n1(20), n2(30), n3(40);

    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);

    // Adding another child should fail because binary tree can have only 2 children per node
    CHECK_THROWS_AS(tree.add_sub_node(root_node, n3), std::logic_error);
}
TEST_CASE("Heap Structure") {
    Tree<int, 2> tree;  // Binary tree
    Node<int> root_node(10), n1(5), n2(15), n3(2), n4(8), n5(12), n6(18);

    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);

    auto it = tree.myHeap();
    std::vector<int> expected_heap = {2, 5, 10, 8, 15, 12, 18};

    for (const int& value : expected_heap) {
        CHECK(*it == value);
        ++it;
    }
}
// // Helper function to compare vectors of Complex numbers
bool areVectorsEqual(const std::vector<Complex>& v1, const std::vector<Complex>& v2) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

TEST_CASE("Testing Tree with Complex numbers and iterators") {
    // Create a Tree of Complex numbers
    Tree<Complex, 2> complexTree;

    // Create Complex numbers
    Complex root(1, 1);
    Complex c1(2, 2);
    Complex c2(3, 3);
    Complex c3(4, 4);
    Complex c4(5, 5);

    // Create Node<Complex> objects
    Node<Complex> rootNode(root);
    Node<Complex> node1(c1);
    Node<Complex> node2(c2);
    Node<Complex> node3(c3);
    Node<Complex> node4(c4);

    // Add nodes to the tree
    complexTree.add_root(rootNode);
    complexTree.add_sub_node(rootNode, node1);
    complexTree.add_sub_node(rootNode, node2);
    complexTree.add_sub_node(node1, node3);
    complexTree.add_sub_node(node1, node4);

    SUBCASE("Test Pre-Order Traversal") {
        std::vector<Complex> expectedOrder = {root, c1, c3, c4, c2};
        std::vector<Complex> actualOrder;

        for (auto it = complexTree.begin_pre_order(); it != complexTree.end_pre_order(); ++it) {
            actualOrder.push_back(*it);
        }

        CHECK(areVectorsEqual(expectedOrder, actualOrder));
    }

    SUBCASE("Test Post-Order Traversal") {
        std::vector<Complex> expectedOrder = {c3, c4, c1, c2, root};
        std::vector<Complex> actualOrder;

        for (auto it = complexTree.begin_post_order(); it != complexTree.end_post_order(); ++it) {
            actualOrder.push_back(*it);
        }

        CHECK(areVectorsEqual(expectedOrder, actualOrder));
    }

    SUBCASE("Test In-Order Traversal") {
        std::vector<Complex> expectedOrder = {c3, c1, c4, root, c2};
        std::vector<Complex> actualOrder;

        for (auto it = complexTree.begin_in_order(); it != complexTree.end_in_order(); ++it) {
            actualOrder.push_back(*it);
        }

        CHECK(areVectorsEqual(expectedOrder, actualOrder));
    }

    SUBCASE("Test BFS Traversal") {
        std::vector<Complex> expectedOrder = {root, c1, c2, c3, c4};
        std::vector<Complex> actualOrder;

        for (auto it = complexTree.begin_bfs_scan(); it != complexTree.end_bfs_scan(); ++it) {
            actualOrder.push_back(*it);
        }

        CHECK(areVectorsEqual(expectedOrder, actualOrder));
    }

    SUBCASE("Test DFS Traversal") {
        std::vector<Complex> expectedOrder = {root, c1, c3, c4, c2};
        std::vector<Complex> actualOrder;

        for (auto it = complexTree.begin_dfs_scan(); it != complexTree.end_dfs_scan(); ++it) {
            actualOrder.push_back(*it);
        }

        CHECK(areVectorsEqual(expectedOrder, actualOrder));
    }
}


TEST_CASE("Testing Complex number constructors and getters") {
    Complex c1(3.0, 4.0);
    CHECK(c1.getReal() == doctest::Approx(3.0));
    CHECK(c1.getImage() == doctest::Approx(4.0));

    Complex c2(-1.5, 2.5);
    CHECK(c2.getReal() == doctest::Approx(-1.5));
    CHECK(c2.getImage() == doctest::Approx(2.5));
}

// Test comparison operators
TEST_CASE("Testing comparison operators") {
    Complex c1(1.0, 1.0);
    Complex c2(2.0, 2.0);
    Complex c3(1.0, 1.0);

    CHECK(c1 < c2);
    CHECK(c2 > c1);
    CHECK(c1 == c3);
    CHECK(c1 != c2);
}

TEST_CASE("Testing output stream operator") {
    Complex c1(1.0, 2.0);
    Complex c2(-1.5, -3.0);

    std::ostringstream oss1;
    oss1 << c1;
    CHECK(oss1.str() == "1 + 2i");

    std::ostringstream oss2;
    oss2 << c2;
    CHECK(oss2.str() == "-1.5 + -3i");
}
TEST_CASE("Testing TreeIteratorBFS postfix increment operator++") {
    // Define a simple Tree with integer values
    Tree<int, 3> tree; // A ternary tree (N=3)

    // Create nodes
    Node<int> root(1);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    Node<int> n6(7);

    // Add nodes to the tree
    tree.add_root(root);
    tree.add_sub_node(root, n1);
    tree.add_sub_node(root, n2);
    tree.add_sub_node(root, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n2, n6);

    // Expected BFS order: 1, 2, 3, 4, 5, 6, 7
    std::vector<int> expected_bfs_order = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> actual_bfs_order;

    // Initialize BFS iterator
    auto it = tree.begin_bfs_scan();
    auto end_it = tree.end_bfs_scan();

    // Collect values using postfix increment operator
    while (it != end_it) {
        actual_bfs_order.push_back(*it++);
    }

    // Check if actual BFS order matches expected order
    CHECK(expected_bfs_order == actual_bfs_order);
}


