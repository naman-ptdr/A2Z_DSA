
// Maximum Nesting Depth of the Parentheses
// 

// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

// Example 1:

// Input: s = "(1+(2*3)+((8)/4))+1"

// Output: 3

// Explanation:

// Digit 8 is inside of 3 nested parentheses in the string.


// class Solution {
//     public:
//         int maxDepth(string s) {
//             int maxDepth = 0;
//             stack<char> st;
//             for(char ch : s){
//                 if(ch=='('){
//                     st.push('(');
//                     maxDepth = max(maxDepth, static_cast<int>(st.size()));
//                 }else if(ch==')') if(!st.empty())st.pop();
//             }
//             return maxDepth;
//         }
//     };