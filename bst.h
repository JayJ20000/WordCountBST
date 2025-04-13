#ifndef BST_H
#define BST_H

#include "node.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class BST {
private:
    Node* root;  // Pointer to the root node of the tree

    // Renamed: Helper function to delete all nodes in the tree
    void destroy(Node* current);

    // Helper function to print the tree (in-order traversal)
    void printHelper(Node* current);

    // Renamed: Helper function to delete a node with the given key
    Node* deleteNode(Node* current, string key);

    // Helper function to save the contents to a file
    void saveHelper(Node* current, ofstream& outFile);

public:
    // Constructor: Initializes an empty tree
    BST();

    // Destructor: Cleans up memory by deleting all nodes in the tree
    ~BST();

    // Inserts a new key-value pair into the tree or updates the value if the key exists
    void set(string key, int value);

    // Finds the value associated with the given key
    int find(string key);

    // Prints the contents of the tree
    void print();

    // Finds and returns the minimum key in the tree
    string min();

    // Finds and returns the maximum key in the tree
    string max();

    // Saves the tree's contents to a file
    void save_file(string filename);

    // Deletes the node with the specified key from the tree
    void deleteKey(string key);
};

#endif // BST_H
