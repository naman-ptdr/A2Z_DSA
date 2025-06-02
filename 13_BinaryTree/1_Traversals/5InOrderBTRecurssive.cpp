// Inorder Traversal of Binary Tree

// Problem Statement: Given the root of a Binary Tree, write a recursive function that returns an array containing the inorder traversal of the tree.

// Algorithm / Intuition
// Inorder traversal stands as one of the depth-first traversal techniques for navigating nodes in a binary tree. The method starts by exploring the left subtree recursively in the following order: left child, root node, right child. Initially, it traverses the left subtree until reaching the leftmost node. Upon reaching a null node, signifying the end of a subtree, the recursive process halts.Then we visit the current node that had invoked the inorder on its left child. After visiting the current node we visit the right subtree in the inorder manner as well.


// Base Case: If the current node is null, it means we have reached the end of a subtree and there are no further nodes to explore. Hence the recursive function stops and we return from that particular recursive call.

// Recursive Function:

// Traverse Left Subtree: Recursively traverse the left subtree by invoking the preorder function on the left child of the current node. This step continues the exploration of nodes in a depth first manner.
// Process Current Node: The recursive function begins by processing ie. adding to the array or printing the current node.
// Traverse Right Subtree: After traversing the entire left subtree,we traverse the right subtree recursively. We once again invoke the preorder function, but this time on the right child of the current node.
// Algorithm:

// Step 1: Check for base case that if the current node is null, return the void function.


// Step 2: Invoke the inorder function on the left child to traverse the entire left subtree first.


// Step 3: Push the value of the current node into the preorder traversal array.


// Step 4: After visiting the current node, we invoke the inorder function on the right child to traverse the right subtree in the end.



                            
#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse 
    // the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inOrder(Node* root){
    // Create an empty vector to
    // store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector
    // containing inorder traversal values
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

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

                            
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

// Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).