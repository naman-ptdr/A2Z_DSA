// Floor in a Binary Search Tree

// Problem Statement: Given a Binary Search Tree and a key, return the floor of the given key in the Binary Search Tree.

// Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key.
// If the floor node does not exist, return nullptr.
// To find the `floor` value, the approach involves tracking the largest node value encountered that is smaller than or equal to the key. It traverses the tree, either finding the exact key or reaching the nodes that approach the given key’s value. During the traversal, at every node, if the key matches the node’s values, it directly assigns the node’s value as the floor and concludes the search. If the key is smaller than the current node’s value, the algorithm navigates to the left subtree to potentially find a smaller value and if the key is larger the algorithm updates the floor value with the current node’s values and explores the right subtree for potentially larger values..

// Algorithm:
// Step 1:Initialise a variable `floor` to -1 to store the ceiling value initially.


// Step 2: Traverse the Binary Search Tree by starting from the root and continue until reaching the end of the tree or finding the key. At every node:

// If the key value is equal to the node value, assign it as the floor value and return.
// If the key value is greater than the current node’s value, update the `floor` with the current node’s value, and move to the right subtree.

// If the key is smaller than the current node’s value, move to the left subtree since the potential floor value should be smaller.

// Step 3: Return the computed `floor` value if the key is not found in the tree. This `floor` value would represent the largest node value smaller than the key, or -1 if no such value exists in the BST.



                            
#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the floor of a key
    // in a Binary Search Tree (BST)
    int floorInBST(TreeNode* root, int key){
        // Initialize the floor variable
        // to store the floor value
        int floor = -1;
        
        // Traverse the BST until reaching
        // the endor finding the key
        while(root){
            // If the key is found, assign it 
            // as the floor value and return
            if(root->val == key){
                floor = root->val;
                return floor;
            }
            
            // If the key is greater than the current
            // node's value, move to the right subtree
            if(key > root->val){
                // Update the floor with the current node's
                // value and move to the right subtree
                floor = root->val;
                root = root->right;
            }
            else{
                // If the key is smaller than the current
                // node's value, move to the left subtree
                root = root->left;
            }
        }
        // Return the computed floor value
        return floor;
    }
};



// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Searching for a value in the BST
    int target = 8;
    int ciel = solution.floorInBST(root, target);
    
    if(ciel != -1){
        cout << "Floor of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No floor found!";
    }
    
    return 0;
}
                            
// Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(N), as it would require traversing all nodes along the path from the root to the leaf.

// Space Complexity: O(1) since the algorithm does not use any additional space or data structures.