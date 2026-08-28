/*994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

TC -->O(m*n)*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        int days = 0;
        int tot = 0;
        int cnt = 0;

        queue<pair<int, int>> rotten;

        // Count total oranges and store initially rotten oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0)
                    tot++;

                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!rotten.empty()) {
            int k = rotten.size();
            cnt += k;

            while (k--) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }

            if (!rotten.empty())
                days++;
        }

        return (tot == cnt) ? days : -1;
    }
};

int main() {
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter the grid elements (0, 1, 2):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << "Minimum time to rot all oranges: "
         << obj.orangesRotting(grid) << endl;

    return 0;
}