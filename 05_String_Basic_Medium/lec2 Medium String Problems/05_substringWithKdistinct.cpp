

// Substrings with K Distinct


// Given a string s of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

// Examples :

// Input: s = "aba", k = 2
// Output: 3
// Explanation: The substrings are: "ab", "ba" and "aba".
// Input: s = "abaaca", k = 1
// Output: 7
// Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a".
// Input: s = "cdad", k = 4
// Output: 0


// //{ Driver Code Starts
// // Initial template for C++

// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends

// // User function template for C++

// class Solution {
//   public:
//     long calcCount(string& s , int k ){
//       int i=0, j=0;
//       int cnt = 0;
//       long ans = 0;
//       int freq[26] = {0};
//       int n = s.size();
//       while(j<n){
//           freq[s[j]-'a']++;
//           if(freq[s[j]-'a']==1) cnt++;
//           while(cnt>k){
//               freq[s[i]-'a']--;
//               if(freq[s[i]-'a']==0) cnt--;
//               i++;
//           }
//           ans += j-i+1;
//           j++;
//       }
//       return ans;
//   }
//     int countSubstr(string& s, int k) {
//         // code here.
//         return calcCount(s, k) - calcCount(s, k-1);
        
//     }
// };


// //{ Driver Code Starts.

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         string s;
//         cin >> s;
//         int k;
//         cin >> k;
//         Solution ob;
//         cout << ob.countSubstr(s, k) << endl;

//         cout << "~"
//              << "\n";
//     }
// }
// // } Driver Code Ends