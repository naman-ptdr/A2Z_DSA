// Preorder Traversal of Binary Tree


// Problem Statement: Given the root of a Binary Tree, write a recursive function that returns an array containing the preorder traversal of the tree.


// Algorithm / Intuition
// Preorder traversal is one of the depth-first traversal methods used to explore nodes in a binary tree. The algorithm first visits the root node then in the preorder traversal, we visit (ie. add to the array) the current node by accessing its value then we recursively traverse the left subtree in the same manner. We repeat these steps for the left subtree then when we return to the current node, we recursively travel to the right subtree in a preorder manner as well.The sequence of steps in preorder traversal follows: Root, Left, Right.


// Base Case: If the current node is null, it means we have reached the end of a subtree and there are no further nodes to explore. Hence the recursive function stops and we return from that particular recursive call.

// Recursive Function:

// Process Current Node: The recursive function begins by processing ie. adding to the array or printing the current node.
// Traverse Left Subtree: Recursively traverse the left subtree by invoking the preorder function on the left child of the current node. This step continues the exploration of nodes in a depth first manner.
// Traverse Right Subtree: After traversing the entire left subtree,we traverse the right subtree recursively. We once again invoke the preorder function, but this time on the right child of the current node.

// Algorithm:

// Step 1: Check for base case that if the current node is null, exit the void function.


// Step 2: Push the value of the current node into the preorder traversal array.


// Step 3: Invoke the preorder function on the left child then right child to traverse the left and right subtrees in the preorder manner respectively.



                            
#include <iostream>
#include <vector>

using namespace std;

// Node structure for
// the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform preorder traversal
// of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse
    // the left subtree
    preorder(root->left, arr);
    // Recursively traverse 
    // the right subtree
    preorder(root->right, arr);
}

// Function to initiate preorder traversal
// and return the resulting vector
vector<int> preOrder(Node* root){
    // Create an empty vector to
    // store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector
    // containing preorder traversal values
    return arr;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}

                            
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

// Space Complexity: O(N) where N is the number of nodes in the binary tree as an additional space for array is allocated to store the values of all ‘N’ nodes of the binary tree.