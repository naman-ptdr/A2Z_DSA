// Power Set: Print all the possible subsequences of the String

// Problem Statement: Given a string, find all the possible subsequences of the string.

// Examples:

// Example 1:
// Input: str = "abc"
// Output: a ab abc ac b bc c
// Explanation: Printing all the 7 subsequence for the string "abc".

// Example 2:
// Input: str = "aa"
// Output: a a aa 
// Explanation: Printing all the 3 subsequences for the string "aa"
// Solution
// Disclaimer: Don't jump directly to the solution, try it out yourself first.

// Practice:
// Solve Problem
// Solution 1: Using bit manipulation
// Approach: Prerequisites: To check whether the ith bit is set or not.If n&(1<<i) != 0,then the ith bit is set.
// First, write down all the numbers from 0 to 2^(n)-1 and their bit representation.0 means I am not picking the character in my subsequence, and 1 means I am picking the character.



#include<bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main()
{


	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

}