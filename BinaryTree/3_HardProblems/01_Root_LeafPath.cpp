#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void getPath(Node* root, vector<vector<int>>& ans, vector<int> path) {
        if (!root) return;

        // Add the current node's data to the path
        path.push_back(root->data);
        
        // If it's a leaf node, add the path to the answer
        if (!root->left && !root->right) {
            ans.push_back(path);
        } else {
            // Recur for left and right subtrees
            getPath(root->left, ans, path);
            getPath(root->right, ans, path);
        }
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;
        if (root != nullptr) {
            getPath(root, ans, path);
        }
        return ans;
    }
};
