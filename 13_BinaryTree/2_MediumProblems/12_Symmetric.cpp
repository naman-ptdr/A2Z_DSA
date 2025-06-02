// Check for Symmetrical Binary Tree

// Problem Statement: Given a Binary Tree, determine whether the given tree is symmetric or not. A Binary Tree would be Symmetric, when its mirror image is exactly the same as the original tree. If we were to draw a vertical line through the centre of the tree, the nodes on the left and right side would be mirror images of each other.
// Algorithm / Intuition
// A tree is said to be symmetric when its structure exhibits a mirroring pattern, meaning that the left and right subtrees of any node are identical or mirror images of each other. In other words, if you could draw a vertical line through the centre of the tree, the nodes on the left side should be symmetrically aligned with the nodes on the right side.


// For a binary tree to be symmetric:

// The root node and its two subtrees (left and right) must have the same value.
// The left subtree of the root should be a mirror image of the right subtree.
// This mirroring should be consistent throughout the entire tree, not just at the root level.
// When recursively checking the left and right subtrees for symmetry in a binary tree, the traversals are mirrored. Specifically, the algorithm compares the left child of the left subtree with the right child of the right subtree and the right child of the left subtree with the left child of the right subtree.

// Algorithm:

// Step 1:Check if the given tree is empty ie. root is null. If the tree is empty, it is considered symmetric by default and we return true.

// Step 2: If the tree is not empty, we call a utility function `isSymmetricUtil`, passing the left and right subtrees of the root. This utility function handles the recursive checks for symmetry.


// Base Case: The base case for recursion is when both the left and right subtrees are empty, indicating a symmetric structure and we return true. If only one of the subtrees is empty (while the other is not), we return false as this violates the conditions of symmetry.


// Check for Symmetry:

// Compare the values of the current nodes from the left and right subtrees. For the binary tree to be symmetric, the corresponding nodes received should have equal values.
// Recursively check the symmetry of these subtrees. We check if the left subtree of the left node is symmetric with the right subtree of the right node.
// Similarly, also check the symmetry of the right subtree of the left node with the left subtree of the right node.
// Hence, we compare the node values and recursively explore the left and right subtrees in a mirrored fashion.

// Step 3:The final result of the isSymmetric function is based on the outcome of the utility function `isSymmetricUtil` recursive function for the roots left and right subtree.

                            
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

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
private:
    // Function to check if
    // two subtrees are symmetric
    bool isSymmetricUtil(Node* root1, Node* root2) {
        // Check if either subtree is NULL
        if (root1 == NULL || root2 == NULL) {
            // If one subtree is NULL, the other
            // must also be NULL for symmetry
            return root1 == root2;
        }
        // Check if the data in the current nodes is equal
        // and recursively check for symmetry in subtrees
        return (root1->data == root2->data)
            && isSymmetricUtil(root1->left, root2->right)
            && isSymmetricUtil(root1->right, root2->left);
    }

public:
    // Public function to check if the
    // entire binary tree is symmetric
    bool isSymmetric(Node* root) {
        // Check if the tree is empty
        if (!root) {
            // An empty tree is
            // considered symmetric
            return true;
        }
        // Call the utility function
        // to check symmetry of subtrees
        return isSymmetricUtil(root->left, root->right);
    }
};


// Function to print the Inorder
// Traversal of the Binary Tree
void printInorder(Node* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    Solution solution;
    
    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res;
    res = solution.isSymmetric(root);
    
    if(res){
        cout << "This Tree is Symmetrical" << endl;
    }
    else{
        cout << "This Tree is NOT Symmetrical" << endl;
    }

    return 0;
}
                            


// Complexity Analysis
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the traversal and the function compares the nodes in a symmetric manner.

// Space Complexity: O(1) as no additional data structures or memory is allocated.

// O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.
// The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.
