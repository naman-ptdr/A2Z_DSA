// Calculate the Diameter of a Binary Tree

// Problem Statement: Given the root of the Binary Tree, return the length of its diameter. The Diameter of a Binary Tree is the longest distance between any two nodes of that tree. This path may or may not pass through the root.

// Algorithm / Intuition
// The O(N2) time complexity of the previous approach can be optimised by eliminating the steps of repeatedly calculating subtree heights. The heights of the left and right subtrees are computed multiple times for each node, which leads to redundant calculations.Instead, we can compute these heights in a bottom-up manner. The Postorder method allows us to validate balance conditions efficiently during the traversal.


// The postorder traversal operates in a bottom-up manner, calculating subtree information before moving to the parent node. We efficiently compute the heights of both the subtrees and at the same time calculate the diameter and update the maximum diameter encountered.

// Algorithm:

// Step 1: Initialise a variable `diameter` to store the diameter of the tree. Create a function height that takes a node and a reference to the diameter variable as input.

// Step 2: Base Case: If the node is null, return 0 indicating the height of an empty tree.

// Step 3: Recursive Function:

// Recursively calculate the height of the left subtree then height of the right subtree.
// Set the current diameter as the sum of left subtree, right subtree + 1 for the current level.
// Update the diameter with the maximum of the current diameter and the global diameter.

// Step 4: After the traversal if complete, return the maximum diameter found during the traversal as the result.

                                
#include <iostream>
#include <algorithm>

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
    // Function to find the
    // diameter of a binary tree
    int diameterOfBinaryTree(Node* root) {
        // Initialize the variable to
        // store the diameter of the tree
        int diameter = 0;
        // Call the height function to traverse
        // the tree and calculate diameter
        height(root, diameter);
        // Return the calculated diameter
        return diameter;
    }

private:
    // Function to calculate the height of
    // the tree and update the diameter
    int height(Node* node, int& diameter) {
        // Base case: If the node is null,
        // return 0 indicating the
        // height of an empty tree
        if (!node) {
            return 0;
        }

        // Recursively calculate the
        // height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum
        // of current diameter or sum of
        // left and right heights
        diameter = max(diameter, lh + rh);

        // Return the height of
        // the current node's subtree
        return 1 + max(lh, rh);
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

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
                                
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.

// Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.