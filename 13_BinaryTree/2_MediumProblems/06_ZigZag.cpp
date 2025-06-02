// Zig Zag Traversal Of Binary Tree

// Problem Statement: Given a Binary Tree, print the zigzag traversal of the Binary Tree. Zigzag traversal of a binary tree is a way of visiting the nodes of the tree in a zigzag pattern, alternating between left-to-right and right-to-left at each level.

// Algorithm / Intuition
// Zigzag traversal is a modification of the traditional level order traversal in a binary tree. Level Order Traversal explores does at each level from left or right but zigzag traversal adds a twist by alternating the direction of exploration. At odd levels, we proceed from left to right but for even levels the order is reversed, from right to left. This is achieved by introducing a `leftToRight` flag which controls the order in which nodes are processed at each level. When `leftToRight` is true, nodes are inserted into the level vector from left to right and when its false, nodes are inserted right to left.


// Algorithm:

// Step 1: Initialise an empty queue data structure to store the nodes during traversal. Create a 2D array or a vector of a vector to store the level order traversal. If the tree is empty, return this empty 2D vector.

// Step 2: Create a `leftToRight` flag to keep track of the direction of traversal. When `leftToRight` is true, nodes are inserted into the level vector from left to right and when its false, nodes are inserted right to left.


// Step 3: Enqueue the root node ie. Add the root node of the binary tree to the queue.

// Step 4: Iterate until the queue is empty:

// Get the current size of the queue. This size indicates the number of nodes at the current level.
// Create a vector ‘level’ to store the nodes at the current level.
// Step 5: Iterate through ‘size’ number of nodes at the current level:

// Pop the front node from the queue.
// Store the node’s value in the level vector. Determine the index to insert the node’s value based on the traversal direction ‘leftToRight’.
// If ‘leftToRight’ is true, the index is set to ‘i’ which means the node’s value will be inserted form left to right. If ‘rightToLeft’ is false, the index is set to size - 1 - i, meaning the node’s value will be inserted from right to left.
// Step 6: Enqueue the left and right child nodes of the current node (if they exist) into the queue.


// Step 7: After processing all the nodes at the current level, add the ‘level’ vector to the ‘ans’ 2D vector, representing the current level. Reverse the direction of traversal for the next level by updating the ‘leftToRight’ flag to its opposite value. This toggling ensures that the nodes at the next level will be processed in the opposite direction, alternating between left-to-right and right-to-left.

// Step 8: Once the traversal loop completes ie. all levels have been processed, return the ‘ans’ 2D vector containing the level-order traversal.

                            
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

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
    // Function to perform zigzag level
    // order traversal of a binary tree
    vector<vector<int>> ZigZagLevelOrder(Node* root){
        // Vector to store the
        // result of zigzag traversal
        vector<vector<int>> result;
        
        // Check if the root is NULL,
        // return an empty result
        if(root == NULL){
            return result;
        }
        
        // Queue to perform
        // level order traversal
        queue<Node*> nodesQueue;
        nodesQueue.push(root);
        
        // Flag to determine the direction of
        // traversal (left to right or right to left)
        bool leftToRight = true;
        
        // Continue traversal until
        // the queue is empty
        while(!nodesQueue.empty()){
            // Get the number of nodes
            // at the current level
            int size = nodesQueue.size();
            
            // Vector to store the values
            // of nodes at the current level
            vector<int> row(size);
            
            // Traverse nodes at 
            // the current level
            for(int i = 0; i < size; i++){
                // Get the front node
                // from the queue
                Node* node = nodesQueue.front();
                nodesQueue.pop();
                
                // Determine the index to insert the node's
                // value based on the traversal direction
                int index = leftToRight ? i : (size - 1 - i);
                
                // Insert the node's value at
                // the determined index
                row[index] = node->data;
                
                // Enqueue the left and right
                // children if they exist
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            
            // Switch the traversal
            // direction for the next level
            leftToRight = !leftToRight;
            
            // Add the current level's
            // values to the result vector
            result.push_back(row);
        }
        
        // Return the final result of
        // zigzag level order traversal
        return result;
    }
};



// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
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

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);

    // Print the result
    printResult(result);

    return 0;
}
                            



// Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.

// Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.