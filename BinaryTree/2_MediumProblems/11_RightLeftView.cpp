// Right/Left view of binary tree

// Problem Statement: Given a Binary Tree, return its right and left views.

// The Right View of a Binary Tree is a list of nodes that can be seen when the tree is viewed from the right side. The Left View of a Binary Tree is a list of nodes that can be seen when the tree is viewed from the left side.
// Algorithm / Intuition
// Algorithm:

// Step 1: Initialise an empty queue data structure to store the nodes during traversal. Create a 2D array or a vector of a vector to store the level order traversal. If the tree is empty, return this empty 2D vector.


// Step 2:Enqueue the root node ie. Add the root node of the binary tree to the queue.


// Step 3:Iterate until the queue is empty:

// Get the current size of the queue. This size indicates the number of nodes at the current level.
// Create a vector ‘level’ to store the nodes at the current level.
// Iterate through ‘size’ number of nodes at the current level:
// Pop the front node from the queue.
// Store the node’s value in the level vector.
// Enqueue the left and right child nodes of the current node (if they exist) into the queue.
// After processing all the nodes at the current level, add the ‘level’ vector to the ‘ans’ 2D vector, representing the current level.

// Step 4: Once the traversal loop completes, the 'ans' 2D vector now contains the level order traversal of the binary tree. To obtain the left view and right view we use each level's vector in the 'ans' vector

// Left View: For each level, extract the first element from the vector and store it in a separate array. Return this array as the final left view of the binary tree.

// Right View: For each level, extract the last element from the vector and store it in a separate array. Return this array as the final right view of the binary tree.



                                
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
    Node(int val) : data(val),
        left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to return the
    // Right view of the binary tree
    vector<int> rightsideView(Node* root) {
        // Vector to store
        // the result
        vector<int> res;

        // Get the level order
        // traversal of the tree
        vector<vector<int>> levelTraversal = levelOrder(root);

        // Iterate through each level and
        // add the last element to the result
        for (auto level : levelTraversal) {
            res.push_back(level.back());
        }

        return res;
    }

    // Function to return the
    // Left view of the binary tree
    vector<int> leftsideView(Node* root) {
        // Vector to store the result
        vector<int> res;

        // Get the level order
        // traversal of the tree
        vector<vector<int>> levelTraversal = levelOrder(root);

        // Iterate through each level and
        // add the first element to the result
        for (auto level : levelTraversal) {
            res.push_back(level.front());
        }

        return res;
    }

private:
    // Function that returns the
    // level order traversal of a Binary tree 
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        // Return an empty vector
        // if the tree is empty
        if (!root) {
            return ans;
        }

        // Use a queue to perform
        // level order traversal
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            // Process each node
            // in the current level
            for (int i = 0; i < size; i++) {
                Node* top = q.front();
                level.push_back(top->data);
                q.pop();

                // Enqueue the left
                // child if it exists
                if (top->left != NULL) {
                    q.push(top->left);
                }

                // Enqueue the right
                // child if it exists
                if (top->right != NULL) {
                    q.push(top->right);
                }
            }

            // Add the current
            // level to the result
            ans.push_back(level);
        }

        return ans;
    }
};




int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

        // Get the Right View traversal
    vector<int> rightView = solution.rightsideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftsideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}



// Complexity Analysis
// Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.

// Space Complexity : O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.
