// Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false



// class Solution {
    // public:
    //     bool isAnagram(string s, string t) {
    //         if(s.size()!=t.size()) return false;
    //         int hash[26] = {0};
    //         for(int i=0; i<s.size(); i++){
    //             hash[s[i]-'a']++;
    //             hash[t[i]-'a']--;
    //         }
    //         for(int i=0; i<26; i++){
    //             if(hash[i]!=0) return false;
    //         }
    //         return true;
    //     }
    // };