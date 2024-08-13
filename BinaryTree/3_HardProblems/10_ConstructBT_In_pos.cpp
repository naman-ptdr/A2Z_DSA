// Construct Binary Tree from Inorder and PostOrder Traversal

// Problem Statement: Given the Postorder and Inorder traversal of a Binary Tree, construct the Unique Binary Tree represented by them.

// Algorithm / Intuition
// Construct Binary Tree from Inorder and Preorder is a prerequisite to this problem as the core approach remains recursively focusing on creating one node at a time We identify a node from the postorder array, locate it in the inorder traversal which splits the array into the left and right subtree.


// To avoid unnecessary array duplication, we use variables (inStart, inEnd) and (postStart, postEnd) on the inorder and postorder arrays, respectively. These variables effectively define the boundaries of the current subtree within the original inorder and postorder traversals.

// Similar to the previous algorithm, we employ a hashmap to store the index of each element in the inorder traversal, transforming the search operation into a constant-time lookup.

// Algorithm
// Step 1:Create an empty map to store the indices of elements in the inorder traversal. Iterate through each element in the inorder traversal and store its index in the map (inMap) using the element as the key and its index as the value.


// Step 2: Create a recursive helper function buildTree with the following parameters:

// Postorder vector
// Start index of postorder (postStart), initially set to 0
// End index of postorder (postEnd), initially set to postorder.size() - 1
// Inorder vector
// Start index of inorder (inStart), initially set to 0
// End index of inorder (inEnd), initially set to inorder.size() - 1
// Map for efficient root index lookup in the inorder traversal.
// Step 3: Base Case: Check if postStart is greater than postEnd or inStart is greater than inEnd. If true, return NULL, indicating an empty subtree/node.

// Step 4: The root node for the current subtree is the last element in the postorder traversal (postorder[postEnd]).

// Step 5: Find the index of this root node in the inorder traversal using the map (inMap[rootValue]). This is the rootIndex.

// Step 6: Hence, the left subtree ranges from inStart to rootIndex. Subtracting these indexes gives us the leftSubtreeSize.

// Step 7: Make two recursive calls to buildTree to build the left and right subtrees:

// For the left subtree:

// Update postStart to postEnd - leftSubtreeSize (moving to the next element in postorder)
// Update postEnd to postEnd - 1 (end of left subtree in postorder)
// Update inEnd to rootIndex - 1 (end of left subtree in inorder)
// For the right subtree:

// Update postStart to postStart (moving to the next element in postorder)
// Update postEnd to postEnd - leftSubtreeSize - 1 (end of right subtree in postorder)
// Update inStart to rootIndex + 1 (start of right subtree in inorder)
// Step 8: Return the root node constructed for the current subtree.



                            
#include<bits/stdc++.h>

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
    // Function to build a binary tree
    // from inorder and postorder traversals
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }

        // Create a map to store the indices
        // of elements in the inorder traversal
        map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }

        // Call the recursive function
        // to build the binary tree
        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
            postorder.size() - 1, hm);
    }

    // Recursive function to build a binary
    // tree from inorder and postorder traversals
    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie,
        vector<int>& postorder, int ps, int pe, map<int, int>& hm) {

        // Base case: If the subtree
        // is empty, return NULL
        if (ps > pe || is > ie) {
            return NULL;
        }

        // Create a new TreeNode
        // with the root value from postorder
        TreeNode* root = new TreeNode(postorder[pe]);

        // Find the index of the root
        // value in inorder traversal
        int inRoot = hm[postorder[pe]];
        
        // Number of nodes in the left subtree
        int numsLeft = inRoot - is; 

        // Recursively build the
        // left and right subtrees
        root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder,
            ps, ps + numsLeft - 1, hm);

        root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder,
            ps + numsLeft, pe - 1, hm);

        // Return the root of
        // the constructed subtree
        return root;
    }
};

// Function to print the
// inorder traversal of a tree
void printInorder(TreeNode* root) {
    if (!root) {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Function to print the given vector
void printVector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example input vectors
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    // Display the input vectors
    cout << "Inorder Vector: ";
    printVector(inorder);

    cout << "Postorder Vector: ";
    printVector(postorder);

    Solution sol;

    // Build the binary tree and
    // print its inorder traversal
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder of Unique Binary Tree Created: " << endl;
    printInorder(root);
    cout << endl;

    return 0;
}

                            


// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This is because each node is processed and visited exactly once.

// The algorithm processes each element in the inorder traversal and for each element it performs constant-time operations (lookup in the hashmap, recursive calls and variable operations).
// Space Complexity: O(N + log2N) where N is the number of elements in the iwhere N is the number of nodes in the Binary Tree.

// This complexity arises from the space used by the recursion stack during the recursive calls. In the worst case, the maximum depth of the recursion stack would be equal to the height of the Binary Tree and in the optimal case the recursion stack complexity would be O(log2N).