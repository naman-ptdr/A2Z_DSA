// Print Root to Node Path in a Binary Tree

// Problem Statement: Given a Binary Tree and a reference to a root belonging to it. Return the path from the root node to the given leaf node.

// No two nodes in the tree have the same data value.
// It is assured that the given node is present and a path always exists.

// Algorithm / Intuition
// To find the path from the root to the given node in the tree we use a Depth-First Traversal. We initialise a vector to store the current path and recursively travel to each node in the tree. At each step, we check if the current node is null, if it is we return false and if the data value of the current node is equal to the given node, we return true signifying the end of the traversal search.


// During the recursive calls, we append the current node’s data value to the vector and explore the left and right children. We backtrack if the target value is not found as the children return ‘false’ and remove the last node from the path vector. In the end, we return the vector containing the path from the root to the given node.

// Algorithm:

// Step 1:Initialise an empty vector to store the current path.

// Step 2: Initialise a recursive function to explore the Binary Tree using Depth First Search. Starting from the root node, we traverse the tree using the inorder sequence.


// Base Case: If the current node is null then we return false, indicating the end of the path. If the current node’s data value is equal to the given node then we return the true, signifying the completion of the path.

// Step 3: Recursive Calls:

// During the recursive exploration, the recursive function appends the current node's data value to the vector arr.
// It checks if the current node's value matches the target value x. If it does, the function returns true, indicating the completion of the path to the target node.
// We then call the function on the left and right children of the current node.

// Step 4: Backtracking:

// If the target value x is not found in the current path, the function backtracks by removing the last node from the path vector arr.
// This means the current node is not part of the valid path from the root to the given node ensuring that the algorithm explores all possible paths and doesn't miss any valid routes to the target node.
// Step 5: In the end, we return the vector containing the path from the root to the given node.


                            
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
    // Function to find the path from the
    // root to a given node with value 'x'
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        // Base case: If the current
        // node is null, return false
        if (!root) {
            return false;
        }

        // Add the current node's
        // value to the path vector
        arr.push_back(root->val);

        // If the current node's value is equal
        // to the target value 'x', return true
        if (root->val == x) {
            return true;
        }

        // Recursively search for the target value
        // 'x' in the left and right subtrees
        if (getPath(root->left, arr, x)
            || getPath(root->right, arr, x)) {
            return true;
        }

        // If the target value 'x' is not found
        // in the current path, backtrack
        arr.pop_back();
        return false;
    }

    // Function to find and return the path from
    // the root to a given node with value 'B'
    vector<int> solve(TreeNode* A, int B) {
        // Initialize an empty
        // vector to store the path
        vector<int> arr;

        // If the root node is null,
        // return the empty path vector
        if (A == NULL) {
            return arr;
        }

        // Call the getPath function to find
        // the path to the node with value 'B'
        getPath(A, arr, B);

        // Return the path vector
        return arr;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to leaf with value " <<
        targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}
                            
// Complexity Analysis
// Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once in the inorder traversal.

// Space Complexity: O(N) awhere N is the number of nodes in the binary tree. This is because the stack can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.

// O(H): In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).