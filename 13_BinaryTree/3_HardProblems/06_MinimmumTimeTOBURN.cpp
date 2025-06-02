// Mapping Parents: bfsTomapParent function to map each node to its parent and find the target node.
// Finding Maximum Time: findMaxTime function to compute the time it takes to burn the entire tree starting from the target node.
// We need to ensure that the Node structure and all functions are properly defined and that the minTime function correctly integrates these functions.




// Explanation:
// Node Structure:

// Defined with data, left, and right pointers.
// bfsTomapParent Function:

// Performs BFS to populate mpp with parent-child relationships.
// Finds and returns the target node.
// findMaxTime Function:

// Uses BFS to traverse the tree from the target node, keeping track of visited nodes.
// Computes the maximum time required to burn the entire tree from the target node.
// minTime Function:

// Initializes the parent map with bfsTomapParent.
// Calculates the maximum time using findMaxTime.
// Key Points:
// Edge Cases: Handle scenarios where the root is NULL or the target node does not exist in the tree.
// Complexity: The BFS traversal ensures that both parent mapping and distance computation are efficient, running in linear time relative to the number of nodes.


#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to find the maximum time required to burn the tree from the target node
    int findMaxTime(unordered_map<Node*, Node*>& mpp, Node* target) {
        queue<Node*> q;
        q.push(target);
        unordered_map<Node*, bool> visited;
        visited[target] = true;
        int maxi = 0;
        
        while (!q.empty()) {
            int size = q.size();
            int flag = 0;
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    flag = 1;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    flag = 1;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if (mpp[node] && !visited[mpp[node]]) {
                    flag = 1;
                    visited[mpp[node]] = true;
                    q.push(mpp[node]);
                }
            }
            if (flag) maxi++;
        }
        return maxi;
    }

    // Function to map parent nodes and find the target node
    Node* bfsTomapParent(Node* root, unordered_map<Node*, Node*>& mpp, int target) {
        queue<Node*> q;
        q.push(root);
        Node* res = NULL;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->data == target) res = node;
            if (node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    // Function to find the minimum time to burn the binary tree starting from the target node
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> mpp; // Map to store parent of each node
        Node* targetNode = bfsTomapParent(root, mpp, target);
        int maxTime = findMaxTime(mpp, targetNode);
        return maxTime;
    }
};
