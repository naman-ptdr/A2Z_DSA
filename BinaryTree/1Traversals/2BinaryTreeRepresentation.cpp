// Binary Tree Representation in C++


// In C++, a binary tree is represented using pointers, forming a hierarchical structure where each node can point to two further nodes: a left child and a right child.

// This representation uses pointers to establish connected between nodes in the tree, allowing traversal and navigation throughout the structure.


// Node Structure:
// A binary tree node is represented using a struct or class that contains the following components:

// Data Component: This holds the value of the node, which could be of any data type (e.g., integer, string, object).
// Pointers to Children: Two pointers, left and right, pointing to the left and right child nodes, respectively. These pointers store the memory addresses of the child nodes, allowing navigation and access to further nodes in the tree.

// Node Constructor:
// The constructor function is named Node, which is the same as the structure name. It takes an integer val as a parameter, which represents the value to be stored in the node.

// Within the constructor:

// data = val; : Assigns the value passed as a parameter (val) to the data member of the node. This sets the value of the node to the input integer.
// left = right = NULL; : Initializes both the left and right pointers to NULL. This is done to ensure that initially, the node does not have any left or right children. Setting pointers to NULL indicates that there are no connections to other nodes at the time of node creation.

// Node Connection:
// When constructing a binary tree using pointers, each node stores references (memory addresses) to its left and right children. These references form the connections between nodes, enabling the hierarchical structure.

// When creating a new node, memory is allocated, and the node's data is stored.
// Pointers left and right are initialised as nullptr (in C++) or NULL to signify that the node currently has no children.
// Later, nodes are connected by assigning the left and right pointers of a parent node to the memory addresses of its respective left and right child nod


#include <iostream>

// Structure definition for
// a node in a binary tree
struct Node {
    // Defining the value of
    // the node (integer data)
    int data;        
     // Reference pointer to
     // the left child node
    Node* left;      
    // Reference pointer to
    // the right child node
    Node* right;      

    // Method to initialize
    // the node with a value
    Node(int val) {
        // Set the value of the
        // node to the passed integer
        data = val;   
        // Initialize left and 
        //r ight pointers as NULL
        left = right = NULL;  
    }
};

int main() {
    // Creating a new node for the root of the 
    // binary tree using dynamic allocation
    Node* root = new Node(1);
    // Creating left and right child
    // nodes for the root node
    root->left = new Node(2);
    root->right = new Node(3);
    // Creating a right child node for
    // the left child node of the root
    root->left->right = new Node(5);
}
