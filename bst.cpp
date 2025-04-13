/**
 * @file bst.cpp
 * @brief This file contains the implementation of the bst class
 * 
 * @author Jalen Jones
 * @date 4-10-2025
 */

 #include "bst.h"
 #include <iostream>
 #include <fstream>
 
 using namespace std;
 
 /**
  * @brief Constructor for the Node class
  * 
  * @param key The key of the node
  * @param value The value associated with the key
  */
 Node::Node(string key, int value) 
     : key(key), data(value), left(nullptr), right(nullptr) {}
 
 /**
  * @brief Constructor for the BST class
  *        Initializes the root of the BST
  */
 BST::BST() 
     : root(nullptr) {}
 
 /**
  * @brief Helper function to recursively delete all nodes in the tree
  * 
  * @param current The current node to be deleted
  */
 void BST::destroy(Node* current) {
     if (!current) return;
     destroy(current->left);  // Recursively delete left subtree 
     destroy(current->right); // Recursively delete right subtree 
     delete current;  // Delete the current node 
 }
 
 /**
  * @brief Destructor for the BST class
  *        Destroys all dynamically allocated nodes in the tree
  */
 BST::~BST() {
     destroy(root);
 }
 
 /**
  * @brief Inserts or updates a key-value pair
  * 
  * @param key The key to be inserted or updated
  * @param value The value associated with the key
  */
 void BST::set(string key, int value) {
     Node** current = &root; // Start at the root of the tree 
 
     while (*current) { // Traverse the tree to find the correct position 
         if (key < (*current)->key) {
             current = &((*current)->left); // Go to the left child 
         } else if (key > (*current)->key) {
             current = &((*current)->right); // Go to the right child 
         } else {
             (*current)->data = value; // Key already exists; update the value 
             return;
         }
     }
     *current = new Node(key, value); // Create a new node if the key is not found 
 }
 
 /**
  * @brief Finds the value associated with a given key in the BST
  * 
  * @param key The key to search for in the tree
  * @return int The value associated with the key
  */
 int BST::find(string key) {
     Node* current = root; // Start at the root 
     while (current != nullptr) { // Continue until reaching a null pointer
         if (current->key == key) {
             return current->data; // Key found; return value 
         }
         if (key < current->key) {
             current = current->left; // Go to the left child 
         } else {
             current = current->right; // Go to the right child 
         }
     }
     return -1; // Key not found
 }
 
 /**
  * @brief Helper function to recursively print the tree in in-order traversal
  * 
  * @param current The current node to be printed
  */
 void BST::printHelper(Node* current) {
     if (!current) return;
     printHelper(current->left); // Visit the left subtree 
     cout << "(" << current->key << ", " << current->data << ") "; // Print current node 
     printHelper(current->right); // Visit the right subtree 
 }
 
 /**
  * @brief Prints the entire tree
  */
 void BST::print() {
     printHelper(root); // Calling the helper 
     cout << endl;
 }
 
 /**
  * @brief Finds the minimum key in the BST
  * 
  * @return string The minimum key in the tree
  */
 string BST::min() {
     if (!root) {
         cout << "Tree is empty.\n";
         return "";
     }
 
     Node* current = root;
     while (current->left) current = current->left; // Traverse to the farthest left node 
     return current->key; // Return the key
 }
 
 /**
  * @brief Finds the maximum key in the BST
  * 
  * @return string The maximum key in the tree
  */
 string BST::max() {
     if (!root) {
         cerr << "Tree is empty.\n";
         return "";
     }
 
     Node* current = root;
     while (current->right) current = current->right; // Traverse to the farthest right node 
     return current->key; // Return the key
 }
 
 /**
  * @brief Helper function to recursively save the tree contents to a file
  * 
  * @param current The current node to be saved
  * @param outFile The output file stream
  */
 void BST::saveHelper(Node* current, ofstream &outFile) {
     if (!current) return;
     saveHelper(current->left, outFile); // Visit the left subtree 
     outFile << current->key << " " << current->data << endl; // Save current node 
     saveHelper(current->right, outFile); // Visit the right subtree 
 }
 
 /**
  * @brief Saves the contents of the tree to a file
  * 
  * @param filename The name of the file to save the tree to
  */
 void BST::save_file(string filename) {
     ofstream outFile(filename); // Open the file
     if (!outFile) {
         cerr << "Could not open file.\n";
         return;
     }
     saveHelper(root, outFile); // Save the tree using the helper function 
     outFile.close(); // Close the file 
 }
 
 /**
  * @brief Helper function to delete a node with the given ke
  * 
  * @param current The current node to check
  * @param key The key of the node to delete
  * @return Node* The node after deletion
  */
 Node* BST::deleteNode(Node* current, string key) {
     if (!current) return nullptr; // Base case: key not found 
 
     if (key < current->key)
         current->left = deleteNode(current->left, key); // Go to the left subtree 
     else if (key > current->key)
         current->right = deleteNode(current->right, key); // Go to the right subtree 
     else {
         // Node to delete found 
         if (!current->left) { // If node has no left child 
             Node* temp = current->right;
             delete current;
             return temp;
         } else if (!current->right) { // If node has no right child 
             Node* temp = current->left;
             delete current;
             return temp;
         }
 
         // Node has two children 
         Node* temp = current->right;
         while (temp && temp->left) // Find the successor 
             temp = temp->left;
 
         // Replace current node's key and value with successor's key and value 
         current->key = temp->key;
         current->data = temp->data;
         current->right = deleteNode(current->right, temp->key); // Delete the successor 
     }
     return current;
 }
 
 /**
  * @brief Deletes a node with the given key from the BST
  * 
  * @param key The key of the node to delete
  */
 void BST::deleteKey(string key) {
     root = deleteNode(root, key);
 }
 
