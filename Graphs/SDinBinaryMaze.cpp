/*1091. Shortest Path in Binary Matrix

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {

        int n = grid.size();

        // Edge Case: source or destination is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        // 8 possible directions
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Start BFS traversal
        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == n - 1)
                return dis;

            for (int i = 0; i < 8; i++) {

                int newr = r + dr[i];
                int newc = c + dc[i];
                if (newr >= 0 && newr < n &&
                    newc >= 0 && newc < n &&
                    grid[newr][newc] == 0 &&
                    dis + 1 < dist[newr][newc]) {

                    
                    dist[newr][newc] = dis + 1;

                    
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        
        return -1;
    }
};

int main() {

    // Define the grid
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };

    Solution obj;

    // Call the method
    int res = obj.shortestPathBinaryMatrix(grid);

    // Output result
    cout << res << endl;

    return 0;
}