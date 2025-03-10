// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
// Algorithm / Intuition
// Optimal Approach (Using 2 pointers): 
// Approach:
// The steps are as follows:

// First, we will take two pointers: left and right, initially pointing to the index 0.
// The sum is set to a[0] i.e. the first element initially.
// Now we will run a while loop until the right pointer crosses the last index i.e. n-1.
// Inside the loop, we will do the following:
// We will use another while loop and it will run until the sum is lesser or equal to k.
// Inside this second loop, from the sum, we will subtract the element that is pointed by the left pointer and increase the left pointer by 1.
// After this loop gets completed, we will check if the sum is equal to k. If it is, we will compare the length of the current subarray i.e. (right-left+1) with the existing one and consider the maximum one.
// Then we will move forward the right pointer by 1. If the right pointer is pointing to a valid index(< n) after the increment, we will add the element i.e. a[right] to the sum.
// Finally, we will return the maximum length.
// Intuition: We are using two pointers i.e. left and right. The left pointer denotes the starting index of the subarray and the right pointer denotes the ending index. Now as we want the longest subarray, we will move the right pointer in a forward direction every time adding the element i.e. a[right] to the sum. But when the sum of the subarray crosses k, we will move the left pointer in the forward direction as well to shrink the size of the subarray as well as to decrease the sum. Thus, we will consider the length of the subarray whenever the sum becomes equal to k.
// The below dry run will clarify the intuition.




#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

