// Implementation
// The strategy involves using a stack to keep track of nodes and a flag to indicate whether a node has been visited. Here's a detailed C++ implementation:

// Explanation
// Data Structures:

// stack<pair<TreeNode*, bool>> s: A stack to hold nodes along with a boolean indicating whether the node has been visited.
// Algorithm:

// Push the root node onto the stack with a false flag to indicate it has not been visited yet.
// While the stack is not empty:
// Pop a node from the stack. If it is not null and is marked as visited, add its value to the result list.
// If it is not visited:
// Push it back onto the stack with a true flag.
// Push its right and left children (if any) onto the stack with a false flag to be processed.
// Output:

// The printVector function is used to display the result of the postorder traversal.
// Memory Management:

// The code constructs a simple binary tree and cleans up the allocated memory. In practice, you should ensure to free any dynamically allocated memory to avoid memory leaks.
// This approach ensures that each node is processed in postorder sequence (left-right-root) using only one stack.

#include<bits/stdc++.h>
// #include <iostream>
// #include <stack>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<pair<TreeNode*, bool>> s;  // stack to store nodes and their visited status
    s.push({root, false});
    
    while (!s.empty()) {
        TreeNode* node = s.top().first;
        bool visited = s.top().second;
        s.pop();

        if (node == nullptr) continue;

        if (visited) {
            // If visited, add to result
            result.push_back(node->value);
        } else {
            // Push the node back with visited status
            s.push({node, true});
            // Push right and left children to the stack
            s.push({node->right, false});
            s.push({node->left, false});
        }
    }
    
    return result;
}

// Helper function to print the result
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Example usage:
int main() {
    // Constructing a simple binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> result = postorderTraversal(root);
    printVector(result);  // Output: 4 5 2 3 1

    // Cleanup the allocated memory (in a real scenario you should free memory to avoid leaks)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
