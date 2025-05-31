// Sliding Window Maximum

// Problem Statement: Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

// Examples:

// Example 1:

// Input: arr = [4,0,-1,3,5,3,6,8], k = 3

// Output: [4,3,5,5,6,8]

// Explanation: 

// Window position                   Max
// ------------------------         -----
// [4  0  -1] 3  5  3  6  8           4
//  4 [0  -1  3] 5  3  6  8           3
//  4  0 [-1  3  5] 3  6  8           5
//  4  0  -1 [3  5  3] 6  8           5
//  4  0  -1  3 [5  3  6] 8           6
//  4  0  -1  3  5 [3  6  8]          8

// For each window of size k=3, we find the maximum element in the window and add it to our output array.

// Example 2:

// Input: arr= [20,25], k = 2

// Output: [25]

// Explanation: There’s just one window is size 2 that is possible and the maximum of the two elements is our answer.
// Solution:

//  Optimized Solution

// Intuition : Can we do something better?
// To understand this, we would first need to check whether we are doing any repetitions. To understand this, consider the following scenario:

// Window : [1,2,3]  and the next incoming value is 2

// For this state, we get a maximum of 3. However, when our state changes to, [2,3,2] we again check what is the largest element even though we know that the outgoing element is not the largest one. Hence, the point of concern lies only when the outgoing element was the largest. 

// Approach
// We address this problem with the help of a data structure that keeps checking whether the incoming element is larger than the already present elements. This could be implemented with the help of a de-queue. When shifting our window, we push the new element in from the rear of our de-queue. Following is a sample representation of our dequeue:



#include<bits/stdc++.h>

using namespace std;

vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();

    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {4,0,-1,3,5,3,6,8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}