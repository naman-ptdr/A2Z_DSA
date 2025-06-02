// Lowest Common Ancestor for two given Nodes

// Problem Statement: Given a binary tree, Find the Lowest Common Ancestor for two given Nodes (x,y).

// Lowest Common Ancestor(LCA): The lowest common ancestor is defined between two nodes x and y as the lowest node in T that has both x and y as descendants (where we allow a node to be a descendant of itself.

// Intuition:

// The very first thing we can observe from the question is that we can find the LCA of 2 given nodes from 

//         i) Left subtree or in

//        ii)Right subtree, if not in both the subtrees then root will be the  LCA.

// Approach:

// If root is null or if root is x or if root is y then return root
// Made a recursion call for both
// i) Left subtree 

// ii)Right subtree

// Because we would find LCA in the left or right subtree only.

// If the left subtree recursive call gives a null value that means we haven’t found LCA in the left subtree, which means we found LCA on the right subtree. So we will return right.
// If the right subtree recursive call gives null value, that means we haven’t found LCA on the right subtree, which means we found LCA on the left subtree. So we will return left .
//  If both left & right calls give values (not null)  that means the root is the LCA.
// Let’s take an example and will try to understand the approach more clearly:

// LCA of (x,y) = > (4,5) = ? (from above given example)
// Root is 1 which is not null and x,y is not equal to root, So the 1st statement in approach  will not execute.
// i) Call left subtree, While calling recursively it will find 4 and this call will return 4 to its parent 
// Point to Note: At present, the root is 2 ( Look at below recursion tree for better understanding)

// i) Call the right subtree ( i.e right of 2), While calling recursively it will find 5  and this call will return 5 to its parent.

// Now the left recursive  call returns value (not null) i.e 4 and also the right recursive call returns value (not null) i.e 5 to its root ( at present root is 2) , and this 2 will return itself to its root i.e to 1 (main root).
// Point to Note: At present, the root is 1 ( Look at below recursion tree for better understanding)

// Now, the left subtree gives a value i.e 2.
// Right recursive call will give null value .because x,y are not present in the right subtree.
// As we know if the right recursive call gives null then we return the answer which we got from the left call, So we will return 2.
//  Hence LCA of (4,5) is 2.
// For a better understanding of the above example (LCA OF 4,5) :



#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the current node is NULL or matches one of the target nodes (p or q), return the current node
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Recur on the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are not NULL, then p and q are found in different subtrees of root,
        // so root is their lowest common ancestor
        if (left != NULL && right != NULL) {
            return root;
        }

        // If one of left or right is NULL, return the non-NULL one
        // This means both p and q are in the same subtree
        return (left != NULL) ? left : right;
    }
};

int main() {
    // Example usage:
    // Construct a simple binary tree:
    //       3
    //      / \
    //     5   1
    //    / \ / \
    //   6  2 0  8
    //     / \
    //    7   4

    TreeNode* root = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(4);

    root->left = n5;
    root->right = n1;
    n5->left = n6;
    n5->right = n2;
    n1->left = n0;
    n1->right = n8;
    n2->left = n7;
    n2->right = n4;

    Solution sol;
    TreeNode* p = n5;  // Node with value 5
    TreeNode* q = n1;  // Node with value 1
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        std::cout << "The LCA of node " << p->val << " and node " << q->val << " is node " << lca->val << std::endl;
    } else {
        std::cout << "LCA not found" << std::endl;
    }

    // Clean up dynamically allocated memory (not shown here for simplicity)

    return 0;
}


// Time complexity: O(N) where n is the number of nodes.

// Space complexity: O(N), auxiliary space.
