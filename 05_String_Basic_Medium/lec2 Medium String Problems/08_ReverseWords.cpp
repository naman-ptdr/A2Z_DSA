// Reverse Words in a String

// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string


// class Solution {
//     public:
//         string reverseWords(string s) {
//             reverse(s.begin(), s.end());
//             int i=0 , left = 0, right = 0;
//             int n = s.size();
//             while(i<n){
//                 while(i<n && s[i]==' '){
//                     i++;
//                 }
//                 if(i==n) break;
//                 while(i<n && s[i]!=' '){
//                     s[right++] = s[i++];
//                 }
//                 reverse(s.begin()+left, s.begin()+right);
//                 s[right++] = ' ';
//                 left = right;
//                 i++;
//             }
//             s.resize(right-1);
//             return s;
//         }
//     };