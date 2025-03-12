// Problem Statement:

// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Note: Start the array with positive elements.

// Examples: 

// Example 1:

// Input:
// arr[] = {1,2,-4,-5}, N = 4
// Output:
// 1 -4 2 -5

// Explanation: 

// Positive elements = 1,2
// Negative elements = -4,-5
// To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.

// Example 2:
// Input:
// arr[] = {1,2,-3,-1,-2,-3}, N = 6
// Output:
// 1 -3 2 -1 3 -2
// Explanation: 

// Positive elements = 1,2,3
// Negative elements = -3,-1,-2
// To maintain relative ordering, 1 must occur before 2, and 2 must occur before 3.
// Also, -3 should come before -1, and -1 should come before -2.
#include<bits/stdc++.h>


using namespace std;

vector<int> RearrangebySign(vector<int>A){
  
int n = A.size();

// Define array for storing the ans separately.
vector<int> ans(n,0);

// positive elements start from 0 and negative from 1.
int posIndex = 0, negIndex = 1;
for(int i = 0;i<n;i++){
    
    // Fill negative elements in odd indices and inc by 2.
    if(A[i]<0){
        ans[negIndex] = A[i];
        negIndex+=2;
    }
    
    // Fill positive elements in even indices and inc by 2.
    else{
        ans[posIndex] = A[i];
        posIndex+=2;
    }
}

return ans;
  
}

int main() {
  
// Array Initialisation.

vector<int> A = {1,2,-4,-5};

vector<int> ans = RearrangebySign(A);

for (int i = 0; i < ans.size(); i++) {
  cout << ans[i] << " ";
}

return 0;
}