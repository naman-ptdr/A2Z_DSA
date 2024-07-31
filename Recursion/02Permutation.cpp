/*Permutation 

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


Explanation
Helper Function recurPermute:

Parameters:
index: The current position in the permutation being built.
nums: The input vector containing numbers.
ans: The result vector storing all permutations.
freq: A frequency vector that keeps track of whether a number is used in the current permutation (1 if used, 0 if not).
ds: A temporary vector to build a single permutation.
Base Case:
If ds contains all numbers (i.e., its size equals nums.size()), it means a complete permutation is formed, so it is added to ans.
Backtracking:
Iterate over all indices of nums.
If a number is not used (i.e., freq[i] is 0), add it to ds, mark it as used (freq[i] = 1), and recursively build the next part of the permutation.
After returning from the recursion, unmark the number as used (freq[i] = 0) and remove it from ds to backtrack and try other possibilities.
Function permute:

Initialization:
ans is used to store all permutations.
ds is used to build a single permutation.
freq is a vector initialized to zero to keep track of used numbers.
Function Call:
Call recurPermute with initial values to start the permutation generation process.
Return Value:
Return the vector ans containing all permutations.
This approach ensures that all possible permutations of the input vector are generated by using recursion and backtracking.
*/


#include <vector>
using namespace std;

class Solution {
public:
    // Recursive function to generate permutations
    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq, vector<int>& ds) {
        // Base case: If the current permutation is of the same length as nums, add it to the results
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        
        // Iterate over all elements in nums
        for (int i = 0; i < nums.size(); i++) {
            // If the element at index i is not yet included in the current permutation
            if (freq[i] == 0) {
                // Include nums[i] in the current permutation
                ds.push_back(nums[i]);
                freq[i] = 1; // Mark nums[i] as used
                
                // Recur to generate the next elements in the permutation
                recurPermute(index + 1, nums, ans, freq, ds);
                
                // Backtrack: remove nums[i] from the current permutation and mark it as unused
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    // Main function to generate all permutations
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // Vector to store all permutations
        vector<int> ds; // Vector to store the current permutation
        vector<int> freq(nums.size(), 0); // Frequency vector to keep track of used elements
        
        // Start the recursion with an empty permutation
        recurPermute(0, nums, ans, freq, ds);
        
        return ans; // Return all generated permutations
    }
};
