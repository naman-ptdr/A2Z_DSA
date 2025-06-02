// Post-Order Traversal Of Binary Tree

// Problem Statement: Given the root of a Binary Tree, write a recursive function that returns an array containing the postorder traversal of the tree.

// Algorithm / Intuition
// Postorder traversal, another depth-first method in tree exploration, follows a sequence where the algorithm first explores the left subtree, then the right subtree, and finally visits the root node. In postorder traversal, we visit (or add to the array) the current node after traversing both its left and right subtrees.The sequence of steps in preorder traversal follows: Left, Right, Root.


// Base Case: If the current node is null, it means we have reached the end of a subtree and there are no further nodes to explore. Hence the recursive function stops and we return from that particular recursive call.

// Recursive Function:

// Traverse Left Subtree: Explore the left subtree by recursively invoking the postorder function on the left child of the current node, ensuring a depth-first approach to node exploration.
// Traverse Right Subtree: After fully traversing the left subtree, we move on to the right subtree, invoking the postorder function on the right child of the current node.
// Process Current Node: After exploring the children of the current node, we process it by adding its value to the postorder traversal array.

// Algorithm:

// Step 1: Check for base case that if the current node is null, exit the void function.


// Step 2: Traverse the left subtree using a recursive postorder call on the left child.


// Step 3: Traverse the right subtree using a recursive postorder call on the right child.


// Step 4: Add the value of the current node to the postorder traversal array.This recursive approach implicitly uses the call stack to handle backtracking while exploring the tree nodes in a postorder manner.

                            
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

// Function to perform postorder
// traversal recursively
void postorder(Node* root, vector<int>& arr){
    // Base case: if root is null, return
    if(root==NULL){
        return;
    }
    // Traverse left subtree
    postorder(root->left, arr);
    // Traverse right subtree
    postorder(root->right, arr);
    // Visit the node
    // (append node's data to the array)
    arr.push_back(root->data);
}

// Function to get the postorder
// traversal of a binary tree
vector<int> postOrder(Node* root){
    // Create a vector to
    // store the traversal result
    vector<int> arr;
    // Perform postorder traversal
    // starting from the root
    postorder(root, arr);
    // Return the postorder
    // traversal result
    return arr;
}

// Function to print the
// elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
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

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder
    // traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}
                            
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

// Space Complexity: O(N) where N is the number of nodes in the binary tree as an additional space for array is allocated to store the values of all ‘N’ nodes of the binary tree.