/**
 * @file node.h
 * @brief Node class used in the BST
 * 
 * @author Jalen Jones
 * @date 4-10-2025
 */

 #ifndef NODE_H
 #define NODE_H
 
 #include <string>
 using namespace std;
 
 /**
  * @class Node
  * @brief Represents each node
  */
 class Node {
 public:
     /**
      * @brief Constructor
      * @param key The key associated with the node
      * @param value The integer value associated with the key
      */
     Node(string key, int value);
 
     string key;    // The key associated with the node
     int data;      // The value associated with the key
     Node* left;    // Pointer to the left child
     Node* right;   // Pointer to the right child
 };
 
 #endif // NODE_H 
