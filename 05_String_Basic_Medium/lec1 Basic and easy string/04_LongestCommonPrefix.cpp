// Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// class Solution {
//     public:
//         string longestCommonPrefix(vector<string>& strs) {
//             string ans = "";
//             int i=0;
//             int n = strs[0].size();
//             while(i<n){
//                 char ch = '0';
//                 for(auto str : strs){
//                     if(ch=='0'){
//                         ch = str[i];
//                     }
//                     else if(str[i]!=ch){
//                         ch = '0';
//                         break;
//                     }
//                 }
//                 if(ch=='0') break;
//                 ans += ch;
//                 i++;
//             }
//             return ans;
//         }
//     };