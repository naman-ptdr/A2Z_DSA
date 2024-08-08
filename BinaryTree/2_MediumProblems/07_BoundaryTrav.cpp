// Boundary Traversal of a Binary Tree

// Problem Statement: Given a Binary Tree, perform the boundary traversal of the tree. The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.
// Algorithm / Intuition
// The boundary traversal algorithm should be divided into three main parts traversed in the anti-clockwise direction:


// Left Boundary: Traverse the left boundary of the tree. Start from the root and keep moving to the left child; if unavailable, move to the right child. Continue this until we reach a leaf node.

// Bottom Boundary: Traverse the bottom boundary of the tree by traversing the leaf nodes using a simple preorder traversal. We check if the current node is a lead, and if so, its value is added to the boundary traversal array.

// Right Boundary: The right boundary is traversed in the reverse direction, similar to the left boundary traversal starting from the root node and keep moving to the right child; if unavailable, move to the left child. Nodes that are not leaves are pushed into the right boundary array from end to start to ensure that they are added in the reverse direction.

// Algorithm:

// Step 1: Initialise an empty array to store the boundary traversal nodes.

// Step 2: Create a helper function to check if a node is a leaf. This is to avoid cases where there will be an overlap in the traversal of nodes. We exclude leaf nodes when adding left and right boundaries as they will already be added when in the bottom boundary.

// Step 3: Initialise a recursive function `addLeftBoundary` and a vector to store the left traversal.

// Start from the root of the tree.
// Traverse down the left side of the tree until we reach a leaf node. For each non-leaf node, add its value to the result list.
// Traverse to its left child. If unavailable, call the recursion function to its right child.

// Step 4: Implement a recursive function `addLeafNodes` and a vector to store the bottom traversal.

// If the current node is a leaf, add its value to the result list.
// Recursively travel to the current nodes left and right subtrees in a preorder fashion.

// Step 5: Implement a recursive function `addRightBoundary` and a vector to store the right traversal.

// Start from the root of the tree.
// Traverse to the right most side of the tree until we reach a leaf node.
// For each non-leaf node, call the recursive function to its right child; if unavailable, call to its left child.
// While the recursion backtracks, add the current node’s value to the result list.


                            
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

class Solution {
public:
    // Function to check
    // if a node is a leaf
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    // Function to add the
    // left boundary of the tree
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            // If the current node is not a leaf,
            // add its value to the result
            if (!isLeaf(curr)) {
                res.push_back(curr->data);
            }
            // Move to the left child if it exists,
            // otherwise move to the right child
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    // Function to add the
    // right boundary of the tree
    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            // If the current node is not a leaf,
            // add its value to a temporary vector
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }
            // Move to the right child if it exists,
            // otherwise move to the left child
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        // Reverse and add the values from
        // the temporary vector to the result
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    // Function to add the
    // leaves of the tree
    void addLeaves(Node* root, vector<int>& res) {
        // If the current node is a
        // leaf, add its value to the result
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        // Recursively add leaves of
        // the left and right subtrees
        if (root->left) {
            addLeaves(root->left, res);
        }
        if (root->right) {
            addLeaves(root->right, res);
        }
    }

    // Main function to perform the
    // boundary traversal of the binary tree
    vector<int> printBoundary(Node* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        // If the root is not a leaf,
        // add its value to the result
        if (!isLeaf(root)) {
            res.push_back(root->data);
        }

        // Add the left boundary, leaves,
        // and right boundary in order
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

// Helper function to
// print the result
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}
                            
                        



// Time Complexity: O(N) where N is the number of nodes in the Binary Tree.

// Adding the left boundary of the Binary Tree results in the traversal of the left side of the tree which is proportional to the the height of the three hence O(H) ie. O(log2N). In the worst case that the tree is skewed the complexity would be O(N).
// For the bottom traversal of the Binary Tree, traversing the leaves is proportional to O(N) as preorder traversal visits every node once.
// Adding the right boundary of the Binary Tree results in the traversal of the right side of the tree which is proportional to the the height of the three hence O(H) ie. O(log2N). In the worst case that the tree is skewed the complexity would be O(N).
// Since all these operations are performed sequentially, the overall time complexity is dominated by the most expensive operation, which is O(N).
// Space Complexity: O(N) where N is the number of nodes in the Binary Tree to store the boundary nodes of the tree. O(H) or O(log2N) Recursive stack space while traversing the tree. In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum depth of the tree, resulting in an O(N) auxiliary space complexity.