/**
 * @file bst.h
 * @brief Header file for the BST class
 * 
 * @author Jalen Jones
 * @date 4-10-2025
 */

 #ifndef BST_H
 #define BST_H
 
 #include "node.h"
 #include <string>
 #include <iostream>
 #include <fstream>
 
 using namespace std;
 
 /**
  * @class BST
  * @brief Binary Search Tree that stores string keys and integer values
  */
 class BST {
 private:
     Node* root;  // Pointer to the root node of the tree
 
     /**
      * @brief Helper function to delete all nodes in the tree
      * 
      * @param current The current node being deleted
      */
     void destroy(Node* current);
 
     /**
      * @brief Helper function to print the tree 
      * 
      * @param current The current node being printed
      */
     void printHelper(Node* current);
 
     /**
      * @brief Helper function to delete a node with the given key
      * 
      * @param current The current node in the recursion
      * @param key The key of the node to delete
      * @return Node* The modified subtree after deletion
      */
     Node* deleteNode(Node* current, string key);
 
     /**
      * @brief Helper function to save the contents of the tree to a file
      * 
      * @param current The current node being processed
      * @param outFile The output file stream
      */
     void saveHelper(Node* current, ofstream& outFile);
 
 public:
     /**
      * @brief Constructor: Initializes an empty tree
      */
     BST();
 
     /**
      * @brief Destructor: Cleans up memory by deleting all nodes in the tree
      */
     ~BST();
 
     /**
      * @brief Inserts a new key-value pair into the tree or updates the value if the key exists
      * 
      * @param key The key to insert or update
      * @param value The associated integer value
      */
     void set(string key, int value);
 
     /**
      * @brief Finds the value associated with the given key
      * 
      * @param key The key to search for
      * @return int The associated value
      */
     int find(string key);
 
     /**
      * @brief Prints the contents of the tree
      */
     void print();
 
     /**
      * @brief Finds and returns the minimum key in the tree
      * 
      * @return string The minimum key
      */
     string min();
 
     /**
      * @brief Finds and returns the maximum key in the tree
      * 
      * @return string The maximum key
      */
     string max();
 
     /**
      * @brief Saves the tree's contents to a file
      * 
      * @param filename The name of the file to save to
      */
     void save_file(string filename);
 
     /**
      * @brief Deletes the node with the specified key from the tree
      * 
      * @param key The key of the node to delete
      */
     void deleteKey(string key);
 };
 
 #endif // BST_H
