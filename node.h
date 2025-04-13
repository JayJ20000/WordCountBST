#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

// Node class represents each node in the Binary Search Tree (BST)
class Node {
public:
    // Constructor
    Node(string key, int value);

    // The key associated with the node
    string key;

    // The data/value associated with the key
    int data;

    // Pointer to the left child
    Node *left;

    // Pointer to the right child
    Node *right;
};

#endif // NODE_H
