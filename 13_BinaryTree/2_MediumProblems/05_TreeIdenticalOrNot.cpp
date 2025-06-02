// Check if two trees are identical

// Problem Statement: Given two Binary Trees, return if true if the two trees are identical, otherwise return false.

// Algorithm / Intuition
// To determine if two binary trees are identical, we can follow a recursive approach. We traverse both trees in the preorder manner, meaning that the current node's value is checked before recursively traversing its left and right subtrees.


// The idea is to traverse both trees simultaneously, comparing the values of corresponding nodes at each step. We need to ensure that the left subtree of each node in the first tree is identical to the left subtree of the corresponding node in the second tree, and similarly for the right subtrees.

// Base Case: The base case for recursion is reached when both nodes are null, indicating the end of the subtree. In this case return true. If only one of the nodes in null while the other is not or vice versa, return false since they cannot be identical.

// Recursive Function:

// Check if the values of the current nodes in both tree are equal. If not, return false otherwise check the conditions below.
// Check if the left subtree of both the trees is identical or not by calling the recursive function on the left child.
// Check if the right subtree of both the trees is identical or not by calling the recursive function on the right child.
// If all recursive calls return true, indicating that the values and structures of the subtrees are identical, the function returns true, confirming that the entire trees are identical.


// Algorithm:

// Step 1: Start at the root node of both trees (node1 and node2).

// Step 2: Check if the values of the current nodes in both trees are equal. If not return false.

// Step 3: Recursively check the left then right subtree of the current node in both trees is identical.

// Step 4: If all the recursive checks return true, then return the trees are identical, otherwise they are not.

                            
#include <iostream>
#include <algorithm>
#include <climits>

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
    // Function to check if two
    // binary trees are identical
    bool isIdentical(Node* node1, Node* node2){
        // If both nodes are NULL,
        // they are identical
        if(node1 == NULL && node2 == NULL){
            return true;
        }
        // If only one of the nodes is
        // NULL, they are not identical
        if( node1== NULL || node2==NULL){
            return false;
        }
        // Check if the current nodes
        // have the same data value
        // and recursively check their
        // left and right subtrees
        return ((node1->data == node2->data)
            && isIdentical(node1->left, node2->left)
                && isIdentical(node1->right, node2->right));
    }
};


int main() {
    // Node1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    Solution solution;
    
    if (solution.isIdentical(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}
                            
// Time Complexity: O(N+M) where N is the number of nodes in the first Binary Tree and M is the number of nodes in the second Binary Tree. This complexity arises from visiting each node of the two binary nodes during their comparison.

// Space Complexity: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case (its N).