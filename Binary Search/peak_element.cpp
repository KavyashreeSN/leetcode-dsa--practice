/*1901.Find Peak Element ||

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

TC -->O(logm*n)
SC -->O(1)*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
        int maxVal = -1;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxVal) {
                maxVal = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = findMaxIndex(mat, n, m, mid);

            int left  = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } 
            else if (mat[row][mid] < left) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    vector<int> ans = sol.findPeakGrid(mat);

    if (ans[0] != -1)
        cout << "Peak found at position: (" << ans[0] << ", " << ans[1] << ") "
             << "with value = " << mat[ans[0]][ans[1]] << endl;
    else
        cout << "No peak found" << endl;

    return 0;
}
