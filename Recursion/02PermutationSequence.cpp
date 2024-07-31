// Permutation sequence
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// Explanation:
// Initialization:

// A vector numbers is created to store the numbers from 1 to n.
// fact is initialized to 1 and is used to store the factorial values.
// Populate the numbers vector and calculate factorial values:

// We calculate factorial values for n-1 elements and store numbers from 1 to n in the vector.
// The factorial of n-1 is computed because each position in the permutation is determined by dividing the problem into (n-1)! permutations.
// Adjust k to be zero-based:

// Since the algorithm is easier to handle with zero-based indexing, k is decremented by 1.
// Generate the permutation:

// The loop continues until there are no numbers left to permute.
// Determine the index of the number to be added to the result using k / fact.
// Add the number at this index to the result string and remove it from the list of available numbers.
// 





#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Step 1: Initialize a vector to store numbers from 1 to n
        vector<int> numbers;
        int fact = 1;
        
        // Step 2: Compute the factorials and fill the numbers vector
        for(int i = 1; i < n; i++) {
            fact = fact * i; // Compute (n-1)! for the first (n-1) elements
            numbers.push_back(i); // Push numbers from 1 to n-1
        }
        numbers.push_back(n); // Add the nth number
        
        k = k - 1; // Convert k to 0-based index
        
        string ans = ""; // To store the final permutation result
        
        while(true) {
            // Determine the index of the current number to be added to the result
            int index = k / fact;
            ans += to_string(numbers[index]); // Add the number at index to the result
            numbers.erase(numbers.begin() + index); // Remove the used number
            
            // If no more numbers are left, exit the loop
            if(numbers.size() == 0) break;
            
            // Update k and fact for the next iteration
            k = k % fact; // Update k for the remaining permutations
            fact = fact / numbers.size(); // Update fact to reflect the permutations of the remaining numbers
        }
        
        return ans; // Return the k-th permutation sequence
    }
};


