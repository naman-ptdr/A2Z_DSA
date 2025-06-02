// Check if the Binary Tree is Balanced Binary Tree

// Problem Statement: Given a Binary Tree, return true if it is a Balanced Binary Tree else return false. A Binary Tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.

// Algorithm / Intuition
// The O(N*N) time complexity of the previous approach can be optimised by simultaneously checking the balance condition while traversing the tree. Instead of repeatedly calculating the heights of left and right subtrees at each node, we can compute these heights in a bottom-up manner. The Postorder method allows us to validate balance conditions efficiently during the traversal. The postorder traversal operates in a bottom-up manner, calculating subtree information before moving to the parent node. We save on time complexity of calling the height of children over and over again as we have access to the height information of both subtrees when evaluating the balance condition at the parent.


// This also allows early detection of unbalanced nodes without unnecessary height calculate if a subtree is already found to be unbalanced, hence avoiding unnecessary function calls.

// Algorithm:

// Step 1: Traverse the Binary Tree is post-order manner using recursion. Visit left subtree, then right subtree, and finally the root node.


// Step 2:During the traversal, for each node, calculate the heights of the its left and right subrees. Use the obtained subtree heights to validate the balance conditions for the current node.

// Step 3: At each node, if the absolute difference between the heights of the left and right subtrees is greater than 1 or if any subtree is unbalanced (returns -1), return -1 immediately indicating an unbalanced tree.


// Step 4: If the tree is balanced, return the height of the current node by considering the maximum height of its left and right subtree plus 1 accounting for the current node.

// Step 5: Complete the traversal until all nodes are visited and return the final result - either the height of the entire tree if balanced or -1 if unbalanced.

                                
#include <iostream>
#include <vector>
#include <stack>

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

class Solution {

public:
    // Function to check if a binary tree is balanced
    bool isBalanced(Node* root) {
        // Check if the tree's height difference
        // between subtrees is less than 2
        // If not, return false; otherwise, return true
        return dfsHeight(root) != -1;
    }

    // Recursive function to calculate
    // the height of the tree
    int dfsHeight(Node* root) {
        // Base case: if the current node is NULL,
        // return 0 (height of an empty tree)
        if (root == NULL) return 0;

        // Recursively calculate the
        // height of the left subtree
        int leftHeight = dfsHeight(root->left);

        // If the left subtree is unbalanced,
        // propagate the unbalance status
        if (leftHeight == -1) 
            return -1;

        // Recursively calculate the
        // height of the right subtree
        int rightHeight = dfsHeight(root->right);

        // If the right subtree is unbalanced,
        // propagate the unbalance status
        if (rightHeight == -1) 
            return -1;

        // Check if the difference in height between
        // left and right subtrees is greater than 1
        // If it's greater, the tree is unbalanced,
        // return -1 to propagate the unbalance status
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        // Return the maximum height of left and
        // right subtrees, adding 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }
};





// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
                                
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.

// Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.                