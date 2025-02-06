
// Introduction to Graph


// 372

// 3
// What is a graph data structure?
// There are two types of data structures

// Linear
// Non - linear
// We are aware of linear data structures such as arrays, stacks, queues, and linked lists. They are called linear because data elements are arranged in a linear or sequential manner.

// The only non-linear data structure that we’ve seen so far is Tree. In fact, a tree is a special type of graph with some restrictions. Graphs are data structures that have a wide-ranging application in real life. These include analysis of electrical circuits, finding the shortest routes between two places, building navigation systems like Google Maps, even social media using graphs to store data about each user, etc. To understand and use the graph data structure, let’s get familiar with the definitions and terms associated with graphs. 


#include <bits/stdc++.h>
using namespace std;
// class Solution {
//   public:
//     const int MOD = 1e9+7;

//     long long power(long long base, long long exp, long long mod) {
//         long long result = 1;
//         while (exp > 0) {
//             if (exp % 2 == 1) {
//                 result = (result * base) % mod;
//             }
//             base = (base * base) % mod;
//             exp /= 2;
//         }
//         return result;
//     }

//     long long count(int n) {
//         long long edge = (1LL * n * (n - 1)) / 2;  // Avoid integer overflow
//         return power(2, edge, MOD);
//     }
// };

class Solution {
  public:
    long long count(int n) {
        // your code here
        long long edge = n*(n-1)/2;
        long long ans = pow(2, edge);
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.count(n) << endl;
    return 0;
}
