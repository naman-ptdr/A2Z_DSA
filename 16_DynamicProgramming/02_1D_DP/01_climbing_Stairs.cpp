// Dynamic Programming : Climbing Stairs

// How to write 1-D Recurrence relation / Climbing Stairs
// In this article, we will learn to write 1-D Recurrence relations using the problem “Climbing Stairs”

// Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.


// Pre-req: Recursion, Dynamic Programming Introduction

// Solution :
// How to Identify a DP problem?

// When we see a problem, it is very important to identify it as a dynamic programming problem. Generally (but not limited to) if the problem statement asks for the following:

// Count the total number of ways
// Given multiple ways of doing a task, which way will give the minimum or the maximum output.
// We can try to apply recursion. Once we get the recursive solution, we can go ahead to convert it to a dynamic programming one.

// Steps To Solve The Problem After Identification

// Once the problem has been identified, the following three steps comes handy in solving the problem:

// Try to represent the problem in terms of indexes.
// Try all possible choices/ways at every index according to the problem statement.
// If the question states
// Count all the ways - return sum of all choices/ways.
// Find maximum/minimum- return the choice/way with maximum/minimum output.
// Using these steps to solve the problem “Climbing Stairs”

// Step 1: We will assume n stairs as indexes from 0 to N.


// Step 2: At a single time, we have 2 choices: Jump one step or jump two steps. We will try both of these options at every index.


// Step 3: As the problem statement asks to count the total number of distinct ways, we will return the sum of all the choices in our recursive function.

// The base case will be when we want to go to the 0th stair, then we have only one option.

// The basic pseudo-code for the problem will be given as:


// There will be one more edge-case when n=1, if we call f(n-2) we will reach stair numbered -1 which is not defined, therefore we add an extra test case to return 1 ( the only way) when n=1.


// If we clearly observe the pseudo-code, we see that it almost matches the problem “fibonacci numbers” discussed in Dynamic Programming Introduction ! So the readers can follow that article to understand the approach used for the dynamic programming solution after the recursive solution.

// Steps for the Tabulation approach.

// Declare a dp[] array of size n+1.
// First initialize the base condition values, i.e i=0 and i=1 of the dp array as 1.
// Set an iterative loop that traverses the array( from index 2 to n) and for every index set its value as dp[i-1] + dp[i-2]. 
// Code:

// C++

#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}