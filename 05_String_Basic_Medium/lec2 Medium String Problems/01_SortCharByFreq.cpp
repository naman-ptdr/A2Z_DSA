
// Sort Characters By Frequency
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.



// class Solution {
//     public:
//         string frequencySort(string s) {
//             unordered_map<char, int> freq;
//             string ans;
//             vector<pair<int, char>> sorted;
//             for(auto ch : s) freq[ch]++;
//             for(auto it : freq) sorted.push_back({it.second, it.first});
//             sort(sorted.rbegin(), sorted.rend());
//             for(auto it : sorted) ans+= string(it.first, it.second);
//             return ans;
//         }
//     };