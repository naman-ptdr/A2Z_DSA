// Count Number of Nodes in a Binary Tree

// Problem Statement: Given a Complete Binary Tree, count and return the number of nodes in the given tree. A Complete Binary Tree is a binary tree in which all levels are completely filled, except possibly for the last level, and all nodes are as left as possible.

// Algorithm / Intuition
// Complete Binary Tree: A complete binary tree is a binary tree where all levels, except possibly the last one, are completely filled, and the nodes in the last level are as left as possible. Read more about it here: Introduction to Trees


// A brute force approach would be to traverse the tree using inorder (or any) traversal and count the number of nodes as we are traversing the tree. In Inorder traversal, we visit the left subtree first, then the current node, and finally the right subtree. By incrementing the counter for each visited node, we effectively count all nodes in the binary tree.

// Algorithm:

// Step 1: Start by initialising a variable to count (initial value 0) the number of nodes in the binary tree

// Step 2:Define a recursive inorder function:

// Base Case: If the current node is null, return from the void function.

// Recursive Call: If the current node is not null, call the function for its left child.

// Increment the counter by 1 for each node.
// Recursively call the function on the right child of the current node as well.
// Step 3: Start the inorder traversal from the root of the Binary Tree by calling the recursive function on the root node with initial count to 0.


// Step 4: Return the final value of the count variable after the traversal representing the total number of nodes.

                                
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    // Function to perform inorder
    // traversal and count nodes
    void inorder(TreeNode* root, int &count) {
        // Base case: If the current
        // node is NULL, return
        if (root == NULL) {
            return;
        }

        // Increment count
        // for the current node
        count++;

        // Recursively call inorder
        // on the left subtree
        inorder(root->left, count);

        // Recursively call inorder
        // on the right subtree
        inorder(root->right, count);
    }

    // Function to count nodes in the binary tree
    int countNodes(TreeNode* root) {
        // Base case: If the root is NULL,
        // the tree is empty, return 0
        if (root == NULL) {
            return 0;
        }

        // Initialize count variable to
        // store the number of nodes
        int count = 0;

        // Call the inorder traversal
        // function to count nodes
        inorder(root, count);

        // Return the final count of
        // nodes in the binary tree
        return count;
    }
};




int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;

    // Call the countNodes function
    int totalNodes = sol.countNodes(root);

    // Print the result
    cout << "Total number of nodes in the Complete Binary Tree: "
            << totalNodes << endl;



    return 0;
}
                                


// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

// Space Complexity : O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes. In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).