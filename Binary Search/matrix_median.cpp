/*Matrix Median
Given a 2D array matrix that is row-wise sorted.
 The task is to find the median of the given matrix.
 
 TC -->O(log(10^9)*n*logm)
 SC -->O(1)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += upperBound(matrix[i], x, n);
        }
        return cnt;
    }

    int findMedian(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = INT_MAX, high = INT_MIN;
        // find minimum and maximum elements in the matrix
        for (int i = 0; i < m; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n - 1]);
        }

        int req = (n * m) / 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(matrix, m, n, mid);

            if (smallEqual <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Median: " << sol.findMedian(matrix) << endl;
    return 0;
}
