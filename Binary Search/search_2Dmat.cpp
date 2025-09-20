/*74.Search a 2D Matrix.
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

TC -->O(log m*n )
SC -->O(1)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;

        int low = 0, high = m * n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            //Formula for converting 1D index to 2D index
            int row = mid / n;   
            int col = mid % n;   

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    int target = 3;

    if(sol.searchMatrix(matrix, target)) 
        cout << "Target found in the matrix." << endl;
    else
        cout << "Target not found in the matrix." << endl;

    return 0;
}
