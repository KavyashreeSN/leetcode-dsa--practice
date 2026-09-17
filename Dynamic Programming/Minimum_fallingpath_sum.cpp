/*64.Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 TC -->O(M*N)
 SC -->O(M*N)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // DP table
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Starting cell
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else {

                    // From top
                    int up = grid[i][j];

                    if (i > 0)
                        up += dp[i - 1][j];
                    else
                        up += 1e9;

                    // From left
                    int left = grid[i][j];

                    if (j > 0)
                        left += dp[i][j - 1];
                    else
                        left += 1e9;

                    // Choose minimum path
                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main() {

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution obj;

    cout << "Minimum path sum: "
         << obj.minPathSum(grid) << endl;

    return 0;
}