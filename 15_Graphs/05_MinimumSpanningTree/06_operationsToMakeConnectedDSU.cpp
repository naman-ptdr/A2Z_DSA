// Number of Operations to Make Network Connected - DSU


// Problem Statement: You are given a graph with n vertices and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to make the graph connected. If it is not possible to make the graph connected, return -1.

// In order to solve this question we will first find out the number of extra-edges and then we will find out the number of components of the graph. We will be using the Disjoint Set data structure to do so.

// The algorithm steps are the following:

// First we need to extract all the edge information (If not already given) in the form of the pair (u, v) where u = starting node and v = ending node. We should store all the edge information in an array.
// Then we will iterate through the array selecting every pair and checking the following:
// If the ultimate parent of u and v(checked using the findPar() method of the Disjoint set) becomes the same,  we should increase the count of extra-edges by 1.
// Because the same ultimate parent means the nodes are already connected and so we can consider the current edge as an extra edge.
// But if the ultimate parents are different, then we should apply the union(either unionBySize() or unionByRank()) method on those two nodes.
// Thus we will get the count of the extra edges. Now it’s time to count the number of components. In order to do so, we will just count the number of the nodes that are the ultimate parent of themselves.
// We will iterate over all the nodes and for each node, we will check the following:
// If the node is the ultimate parent of itself, we will increase the count of components by 1.
// Otherwise, we will continue to the next node.
// This checking will be done using the parent array inside the Disjoint set.

// Finally, we will check the count of extra edges and the number of components. If the count of extra-edges is greater or the same, we will return the answer that is (number of components - 1), and otherwise, we will return -1.

#include <bits/stdc++.h>
using namespace std;

//User function Template for C++
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};

int main() {

    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    Solution obj;
    int ans = obj.Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}