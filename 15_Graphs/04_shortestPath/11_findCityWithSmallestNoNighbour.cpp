// Find the City With the Smallest Number of Neighbours at a Threshold Distance

// Problem Statement: There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.

// Note: that the distance of a path, connecting cities i and j are equal to the sum of the edges' weights along that path.

// Approach: 

// Initial Configuration:

// Adjacency Matrix(dist): All the cells of the matrix are initially set to infinity(∞).

// cntCity: Initially set to V(no. of nodes) i.e. the maximum value possible. It will store the minimum number of cities whose distance is at most distanceThreshold.

// cityNo: Initially set to -1. It will store the answer i.e. the node with the largest value and the minimum ‘cntCity’ value. 

// The algorithm steps are as follows:

// First, we will iterate over the edges, and set the value of dist[fromi][toi] and dist[toi][fromi] to weighti as the edges are bidirectional.
// After having set the adjacency matrix accordingly, we will run a loop from 0 to V-1(V = no. of vertices). In the kth iteration, this loop will help us to check the path via node k for every possible pair of nodes. Basically, this loop will change the value of k in the formula(given in step 4).
// Inside the loop, there will be two nested loops for generating every possible pair of nodes(Nothing but to visit each cell of a 2D matrix using the nested loop). Among these two loops, the first loop will change the value of i and the second one will change the value of j in the formula(given in step 4).
// Inside these nested loops, we will apply the following formula to calculate the shortest distance between the pair of nodes:dist[i][j] =min(dist[i][j], dist[i ][k]+dist[k][j]), where i = source node, j = destination node, and k = the node via which we are reaching from i to j.
// The adjacency matrix will store all the shortest paths for each node. For example, dist[i][j] will store the shortest path from node i to node j.
// After that, we will count the nodes(cnt) with a distance lesser or equal to distanceThreshold and check if it is lesser than the current value of cntCity.
// If it is lesser, we will update cntCity with the count of nodes and cityNo with the value of the current city.
// Finally, we will return cityNo as our answer.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges,
	             int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;

	}
};


int main() {

	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}