/*542.01Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 TC -->O(n*m)*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    // Put all 0s into the queue
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(mat[i][j] == 0) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while(!q.empty()) {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;

        q.pop();

        dist[row][col] = steps;

        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               vis[nrow][ncol] == 0) {

                vis[nrow][ncol] = 1;

                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }

    return dist;
}

int main() {

    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> ans = updateMatrix(mat);

    // Print answer
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}