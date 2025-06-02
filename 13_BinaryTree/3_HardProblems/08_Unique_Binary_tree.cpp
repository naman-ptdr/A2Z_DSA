
// Geek wants to know the traversals required to construct a unique binary tree. Given a pair of traversal, return true if it is possible to construct unique binary tree from the given traversals otherwise return false.

// Each traversal is represented with an integer: preorder - 1, inorder - 2, postorder - 3.   

// Example 1:

// Input:
// a = 1, b=2
// Output: 1
// Explanation: We can construct binary tree using inorder traversal and preorder traversal. 
// Example 2:

// Input: a = 1, b=3
// Output: 0 
// Explanation: We cannot construct binary tree using preorder traversal and postorder traversal. 




class Solution
{
public:
    bool isPossible(int a, int b)
    {
        // Check if both a and b are 2
        if (a == 2 && b == 2)
        {
            return false; // Special case: both are 2
        }
        
        // Check if at least one of a or b is 2
        if (a == 2 || b == 2)
        {
            return true; // One is 2, but not both
        }
        
        return false; // Neither is 2
    }
};
