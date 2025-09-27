/*
     Trees in DSA

    Topics Covered:
    ----------------
    1. Introduction to Trees
       - A tree is a non-linear data structure
       - Consists of nodes and edges
       - Root node, internal nodes, leaf nodes

    2. Types of Trees
       - Full Binary Tree
       - Complete Binary Tree
       - Perfect Binary Tree 
       - Balanced Binary Tree
       - Degenarate Binary Tree

    3. Binary Tree Representation in C++
       - Using structs / classes
       - Each node has: data, left child, right child

    4. Traversal Techniques
       - Depth First Search (DFS)
           * Inorder (Left → Root → Right)
           * Preorder (Root → Left → Right)
           * Postorder (Left → Right → Root)
       - Breadth First Search (BFS)
           * Level Order Traversal

    
*/
// Sample Binary Tree Representation in C++
#include <bits/stdc++.h>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {
    // Create root node
    Node* root = new Node(1);

    // Add children
    root->left = new Node(2);
    root->right = new Node(3);

    // Add grandchildren
    root->left->left = new Node(5);

    // Example output
    cout << "Root: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data << endl;
    cout << "Left->Left Grandchild: " << root->left->left->data << endl;

    return 0;
}

