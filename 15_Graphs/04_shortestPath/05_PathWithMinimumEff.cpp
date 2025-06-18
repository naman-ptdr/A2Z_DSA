// G-37: Path With Minimum Effort

// Approach:
// Brute Force: We can figure out the effort for all the paths and return the minimum effort among them.

// Optimised (Using Dijkstra) : 
// In this particular problem, since there is no adjacency list we can say that the adjacent cell for a coordinate is that cell which is either on the top, bottom, left, or right of the current cell i.e, a cell can have a maximum of 4 cells adjacent to it and can only move in these directions.


// Initial configuration:

// Queue: Define a Queue which would contain pairs of the type {diff, (row, col) }, where ‘dist’ indicates the currently updated value of difference from source to the cell.
// Distance Matrix: Define a distance matrix that would contain the minimum difference from the source cell to that particular cell. If a cell is marked as ‘infinity’ then it is treated as unreachable/unvisited.
// The Algorithm consists of the following steps :

// Start by creating a queue that stores the distance-node pairs in the form {dist,(row, col)} and a dist matrix with each cell initialized with a very large number ( to indicate that they’re unvisited initially) and the source cell marked as ‘0’.
// We push the source cell to the queue along with its distance which is also 0.
// Pop the element at the front of the queue and look out for its adjacent nodes (left, right, bottom, and top cell). Also, for each cell, check the validity of the cell if it lies within the limits of the matrix or not.
// If the current d


// ifference value of a cell from its parent is better than the previous difference indicated by the distance matrix, we update the difference in the matrix and push it into the queue along with cell coordinates.
// A cell with a lower difference value would be at the front of the queue as opposed to a node with a higher difference. The only difference between this problem and Dijkstra’s Standard problem is that there we used to update the value of the distance of a node from the source and here we update the absolute difference of a node from its parent.
// We repeat the above three steps until the queue becomes empty or until we encounter the destination node.
// Return the calculated difference and stop the algorithm from reaching the destination node. If the queue becomes empty and we don’t encounter the destination node, return ‘0’ indicating there’s no path from source to destination.
// Here’s a quick demonstration of the Algorithm’s 1st iteration ( all the further iterations would be done in a similar way ) :

// Note: Updating the value of difference will only yield us the effort for the path traversed.

// Note: If you wish to see the dry run of the above approach, you can watch the video attached to this article. 

// Intuition:

// In this problem, we need to minimize the effort of moving from the source cell (0,0) to the destination cell (n - 1,m - 1). The effort can be calculated as the maximum value of the difference between the node and its next node in the path from the source to the destination. Among all the possible paths, we have to minimize this effort. So, for these types of minimum path problems, there’s one standard algorithm that always comes to our mind and that is Dijkstra’s Algorithm which would be used in solving this problem also. We update the distance every time we encounter a value of difference less than the previous value. This way, whenever we reach the destination we finally return the value of difference which is also the minimum effort.



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {

        // Create a priority queue containing pairs of cells 
        // and their respective distance from the source cell in the 
        // form {diff, {row of cell, col of cell}}.
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the dist for source cell (0,0) as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the matrix by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Check if we have reached the destination cell,
            // return the current value of difference (which will be min).
            if (row == n - 1 && col == m - 1)
                return diff;
           
            for (int i = 0; i < 4; i++)
            {
                // row - 1, col
                // row, col + 1
                // row - 1, col
                // row, col - 1
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Checking validity of the cell.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    // Effort can be calculated as the max value of differences 
                    // between the heights of the node and its adjacent nodes.
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    // If the calculated effort is less than the prev value
                    // we update as we need the min effort.
                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; // if unreachable
    }
};

int main()
{
    // Driver Code.

    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    int ans = obj.MinimumEffort(heights);

    cout << ans;
    cout << endl;

    return 0;
}