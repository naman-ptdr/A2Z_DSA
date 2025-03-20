// Dynamic Programming: Frog Jump with k Distances (DP 4)

// In this article, we will learn about "Dynamic Programming: Frog Jump with k Distances (DP 4)"

// Problem Statement:  Frog Jump with K Distance/ Learn to write 1D DP

// Problem Statement:

// This is a follow-up question to “Frog Jump” discussed in the previous article. In the previous question, the frog was allowed to jump either one or two steps at a time. In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.

// Pre-req: Frog Jump



#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {
    dp[0] = 0;

    // Loop through the array to fill in the dp array
    for (int i = 1; i < n; i++) {
        int mmSteps = INT_MAX;

        // Loop to try all possible jumps from '1' to 'k'
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1]; // The result is stored in the last element of dp
}

// Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    return solveUtil(n, height, dp, k);
}

int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1); // Initialize a memoization array for the main function
    cout << solve(n, height, k) << endl; // Print the result of the solve function
    return 0;
}

