/*130.Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 TC -->O(n*m)
 SC -->O(n*m)*/


#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>>& mat,
         vector<vector<int>>& vis) {

    int n = mat.size();
    int m = mat[0].size();

    vis[row][col] = 1;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++) {

        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >= 0 && nrow < n &&
           ncol >= 0 && ncol < m &&
           mat[nrow][ncol] == 'O' &&
           vis[nrow][ncol] == 0) {

            dfs(nrow, ncol, mat, vis);
        }
    }
}

void solve(vector<vector<char>>& mat) {

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    // First and last row
    for(int j = 0; j < m; j++) {

        if(mat[0][j] == 'O' && vis[0][j] == 0)
            dfs(0, j, mat, vis);

        if(mat[n-1][j] == 'O' && vis[n-1][j] == 0)
            dfs(n-1, j, mat, vis);
    }

    // First and last column
    for(int i = 0; i < n; i++) {

        if(mat[i][0] == 'O' && vis[i][0] == 0)
            dfs(i, 0, mat, vis);

        if(mat[i][m-1] == 'O' && vis[i][m-1] == 0)
            dfs(i, m-1, mat, vis);
    }

    // Flip surrounded O's
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(mat[i][j] == 'O' && vis[i][j] == 0)
                mat[i][j] = 'X';
        }
    }
}

int main() {

    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    solve(mat);

    // Print result
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}