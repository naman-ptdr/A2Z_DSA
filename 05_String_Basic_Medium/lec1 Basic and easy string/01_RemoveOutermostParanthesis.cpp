

// 1021. Remove Outermost Parentheses

// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.





// class Solution {
//     public:
//         string removeOuterParentheses(string s) {
//             string ans = "";
//             int depth = 0;
//             for(char c : s){
//                 if(c == '('){
//                     if(depth>0){
//                         ans += c;
//                     }
//                     depth++;
//                 }else{
//                     depth--;
//                     if(depth>0){
//                         ans += c;
//                     }
//                 }
//             }
//             return ans;
//         }
//     };