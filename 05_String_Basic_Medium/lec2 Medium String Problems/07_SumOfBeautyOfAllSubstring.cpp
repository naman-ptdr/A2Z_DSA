
// Sum of Beauty of All Substrings

// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

 

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// Example 2:

// Input: s = "aabcbaa"
// Output: 17


// class Solution {
//     public:
//         int beautySum(string s) {
//             int ans = 0;
//             for(int i=0; i<s.size(); i++){
//                 vector<int> freq(26, 0);
//                 for(int j=i; j<s.size(); j++){
//                     freq[s[j]-'a']++;
//                     int leastFreq = INT_MAX;
//                     int mostFreq = INT_MIN;
//                     for(int k=0; k<26; k++){
//                         if(freq[k]>mostFreq){
//                             mostFreq = freq[k];
//                         }if(freq[k]<leastFreq && freq[k]>0){
//                             leastFreq = freq[k];
//                         }
//                     }
//                     ans += mostFreq - leastFreq;
//                 }
//             }
//             return ans;
//         }
//     };