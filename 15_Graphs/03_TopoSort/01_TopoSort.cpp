// Topological Sort Algorithm | DFS: G-21

// Problem Statement: Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

// Note: In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

// Example 1:

// Input: V = 6, E = 6


// Output: 5, 4, 2, 3, 1, 0
// Explanation: A graph may have multiple topological sortings. 
// The result is one of them. The necessary conditions 
// for the ordering are:
// According to edge 5 -> 0, node 5 must appear before node 0 in the ordering.
// According to edge 4 -> 0, node 4 must appear before node 0 in the ordering.
// According to edge 5 -> 2, node 5 must appear before node 2 in the ordering.
// According to edge 2 -> 3, node 2 must appear before node 3 in the ordering.
// According to edge 3 -> 1, node 3 must appear before node 1 in the ordering.
// According to edge 4 -> 1, node 4 must appear before node 1 in the ordering.

// The above result satisfies all the necessary conditions. 
// [4, 5, 2, 3, 1, 0] is also one such topological sorting 
// that satisfies all the conditions.
// Example 2:

// Input: V = 4, E = 3


// Result: 3, 2, 1, 0
// Explanation: The necessary conditions for the ordering are:
// For edge 1 -> 0 node 1 must appear before node 0.
// For edge 2 -> 0 node 1 must appear before node 0.
// For edge 3 -> 0 node 1 must appear before node 0.

// [2, 3, 1, 0] is also another topological sorting for the graph.
// Solution
// Disclaimer: Don't jump directly to the solution, try it out yourself first.

// Problem link

// Topological sorting only exists in Directed Acyclic Graph (DAG). If the nodes of a graph are connected through directed edges and the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 

// The topological sorting of a directed acyclic graph is nothing but the linear ordering of vertices such that if there is an edge between node u and v(u -> v), node u appears before v in that ordering.

// Now, let's understand Why topological sort only exists in DAG:

// Case 1 (If the edges are undirected): If there is an undirected edge between node u and v, it signifies that there is an edge from node u to v(u -> v) as well as there is an edge from node v to u(v -> u). But according to the definition of topological sorting, it is practically impossible to write such ordering where u appears before v and v appears before u simultaneously. So, it is only possible for directed edges.
// Case 2(If the directed graph contains a cycle): The following directed graph contains a cycle:


// If we try to get topological sorting of this cyclic graph, for edge 1->2, node 1 must appear before 2, for edge 2->3, node 2 must appear before 3, and for edge 3->1, node 3 must appear before 1 in the linear ordering. But such ordering is not possible as there exists a cyclic dependency in the graph. Thereby, topological sorting is only possible for a directed acyclic graph.
// Approach: 

// We will be solving it using the DFS traversal technique. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes.

// The algorithm steps are as follows:

// We must traverse all components of the graph.
// Make sure to carry a visited array(all elements are initialized to 0) and a stack data structure, where we are going to store the nodes after completing the DFS call.
// In the DFS call, first, the current node is marked as visited. Then DFS call is made for all its adjacent nodes.
// After visiting all its adjacent nodes, DFS will backtrack to the previous node and meanwhile, the current node is pushed into the stack.
// Finally, we will get the stack containing one of the topological sortings of the graph.
// Note: If you wish to see the dry run of the above approach, you can watch the video attached to this article.

// Let’s quickly understand the algorithm considering the following graph:


// DFS will start from node 0 and mark it as visited. But it has no adjacent nodes. So the DFS will return putting node 0 into the stack( stack: {0} ).
// Then DFS will again start from node 1 and mark it as visited, but it also has no adjacent nodes. So node 1 is pushed into the stack( stack: {1, 0} ) and the DFS call will be over.
// Then DFS will start from node 2 and mark it as visited as well. It will again call DFS for its adjacent node 3 and mark 3 as visited. After visiting node 3, it will find out that only adjacent node 1 is previously visited.
// So it will backtrack to node 2, putting node 3 first and then node 2 into the stack ( stack: {2, 3, 1, 0} ).
// Again, DFS will start from node 4 and mark it as visited. It will find all its adjacent nodes 0 and 1 have been previously visited. So, node 4 will be pushed into the stack( stack: {4, 2, 3, 1, 0} ).
// Lastly, DFS will start from node 5 and mark it as visited. Again, it will find all its adjacent nodes 0 and 2 are previously visited. So, it will return putting node 5 into the stack( stack: {5, 4, 2, 3, 1, 0} ).
// Finally, the stack will contain {5, 4, 2, 3, 1, 0}, which is one of the topological sortings of the graph.
// Let’s understand how the linear orderings are maintained considering the following simple graph:


// The linear ordering for the above graph can be 1, 2, 3, 4, 5, 6 or 1, 2, 3, 4, 6, 5. If we closely observe this algorithm, it is designed in such a way that when the DFS call for a node is completed, the node is always kept in the stack. So for example, if the DFS call for 3 is over, we must have the nodes 3, 4, 5, and 6 linearly ordered in the stack. And this is true for every other node. Thus the linear ordering is always maintained for each node of the graph.

// Intuition: 

// Since we are inserting the nodes into the stack after the completion of the traversal, we are making sure, there will be no one who appears afterward but may come before in the ordering as everyone during the traversal would have been inserted into the stack. 

// Note: Points to remember, that node will be marked as visited immediately after making the DFS call and before returning from the DFS call, the node will be pushed into the stack.

// Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void dfs(int node, int vis[], stack<int> &st,
	         vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int vis[V] = {0};
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}