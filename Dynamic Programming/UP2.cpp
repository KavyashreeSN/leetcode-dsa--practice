/*63.Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

TC -->O(m*n)
SC -->O((n-1)(m-1))+ O(n*m)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    int func(int m, int n,
             vector<vector<int>>& matrix,
             vector<vector<int>>& dp) {

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If obstacle is present
                if (matrix[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                // Starting point
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                // Paths from above
                if (i > 0)
                    up = dp[i - 1][j];

                // Paths from left
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }

        return dp[m - 1][n - 1];
    }

public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        return func(m, n, obstacleGrid, dp);
    }
};

int main() {

    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));

    cout << "Enter the grid (0 = empty, 1 = obstacle):\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    Solution obj;

    int result = obj.uniquePathsWithObstacles(obstacleGrid);

    cout << "Number of unique paths: " << result << endl;

    return 0;
}