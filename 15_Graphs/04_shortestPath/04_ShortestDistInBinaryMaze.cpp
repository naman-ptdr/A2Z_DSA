// G-36: Shortest Distance in a Binary Maze

// Approach:
// We’ll solve this problem by Dijkstra's Algorithm using a simple queue. Since, there is no adjacency list for this particular problem we can say that the adjacent cell for a coordinate is that cell which is either on the top, bottom, left, or right of the current cell i.e, a cell can have a maximum of 4 cells adjacent to it.


// Initial configuration:

// Source Node and Destination Node: Before starting off with the Algorithm, we need to define a source node and a destination node, between which we need the shortest possible distance.
// Queue: Define a Queue which would contain pairs of the type {dist, pair of coordinates of cell }, where ‘dist’ indicates the currently updated value of the shortest distance from the source to the cell.
// Distance Matrix: Define a distance matrix that would contain the distance from the source cell to that particular cell. If a cell is marked as ‘infinity’ then it is treated as unreachable/unvisited.
// The Algorithm consists of the following steps :

// Start by creating a queue that stores the distance-node pairs in the form {dist, coordinates of cell pair} and a dist matrix with each cell initialized with a very large number ( to indicate that they’re unvisited initially) and the source cell marked as ‘0’.
// We push the source cell to the queue along with its distance which is also 0.
// Pop the element at the front of the queue and look out for its adjacent nodes (left, right, bottom, and top cell). Also, for each cell, check the validity of the cell if it lies within the limits of the matrix or not.
// If the current reachable distance to a cell from the source is better than the previous distance indicated by the distance matrix, we update the distance and push it into the queue along with cell coordinates.
// A cell with a lower distance would be at the front of the queue as opposed to a node with a higher distance. We repeat the above two steps until the queue becomes empty or until we encounter the destination node.
// Return the calculated distance and stop the algorithm from reaching the destination node. If the queue becomes empty and we don’t encounter the destination node, return ‘-1’ indicating there’s no path from source to destination.
// Here’s a quick demonstration of the algorithm :


// Note: If you wish to see the dry run of the above approach, you can watch the video attached to this article. 

// Intuition: Here in this problem, instead of a graph we have a 2D binary matrix in which we have to reach a destination cell from a source cell. So, we can see that this problem is easily approachable by Dijkstra’s Algorithm. Now, here we use a queue instead of a priority queue for storing the distance-node pairs. Let’s understand through an illustration why a queue is better here:


// We can see clearly in the above illustration that the distances are increasing monotonically (because of constant edge weights). Since greater distance comes at the top automatically, so we do not need the priority queue as the pop operation will always pop the smaller distance which is at the front of the queue. This helps us to eliminate an additional log(N) of time needed to perform insertion-deletion operations in a priority queue.



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] 
                == 1 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;

                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if (newr == destination.first &&
                        newc == destination.second)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }
};

int main()
{
    // Driver Code.

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
}