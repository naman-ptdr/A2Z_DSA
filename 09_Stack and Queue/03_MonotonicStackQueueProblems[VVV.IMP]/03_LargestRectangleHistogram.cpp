// Area of largest rectangle in Histogram

// Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.

// Example:

// Input: N =6, heights[] = {2,1,5,6,2,3}

// Output: 10

// Explanation:


// Solution
// Disclaimer: Don't jump directly to the solution, try it out yourself first.

// Practice:
// Solve Problem
// Solution 1: Brute Force Approach

// Intuition: The intuition behind the approach is taking different bars and finding the maximum width possible using the bar.



// Similarly for other bars, we will find the areas possible:-

// Considering the width of each bar as 1 unit.

// For first bar, area possible = 2* 1 =2 sq . units

// For second  bar, area possible = 1 * 6 =6 sq . units

// For third bar , area possible = 5 *2 = 10 sq . units

// For fourth bar , area possible = 6 * 1 = 6 sq . units

// For Fifth bar , area possible = 2 * 4 = 8 sq . units


// For Sixth bar , area possible = 3 * 1 =3 sq . units

// So, the maximum area possible = 10 sq units.

// Approach:

// The approach is to find the right smaller and left smaller element and find the largest Rectangle area in Histogram.



// Code:



#include <bits/stdc++.h>

using namespace std;
// Brute Force Approach to find largest rectangle area in Histogram
int largestarea(int arr[], int n) {
  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int minHeight = INT_MAX;
    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, arr[j]);
      maxArea = max(maxArea, minHeight * (j - i + 1));
    }
  }
  return maxArea;
}
int main() {
  int arr[] = {2, 1, 5, 6, 2, 3, 1};
  int n = 7;
  cout << "The largest area in the histogram is " << largestarea(arr, n); // Printing the largest rectangle area
  return 0;
}