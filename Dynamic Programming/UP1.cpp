/*62.Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

TC -->O(m*n)
SC -->O((n-1)(m-1))+ O(n*m)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(int i, int j, vector<vector<int>>& dp) {

        // Base case
        if (i == 0 && j == 0)
            return 1;

        // Outside the grid
        if (i < 0 || j < 0)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Move up
        int up = func(i - 1, j, dp);

        // Move left
        int left = func(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(m - 1, n - 1, dp);
    }
};

int main() {

    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter number of columns: ";
    cin >> n;

    Solution obj;

    int ans = obj.uniquePaths(m, n);

    cout << "Number of unique paths: " << ans << endl;

    return 0;
}