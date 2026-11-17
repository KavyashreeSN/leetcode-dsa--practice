//MCM Problem 

//Pattern : Partition dp 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& arr,
              vector<vector<int>>& dp) {

        // Base case
        if (i == j)
            return 0;

        //memoization

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k < j; k++) {

            int steps = arr[i-1] * arr[k] * arr[j]
                      + solve(i, k, arr, dp)
                      + solve(k+1, j, arr, dp);

            mini = min(mini, steps);
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int>& arr) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(1, n-1, arr, dp);
    }
};

int main() {

    Solution obj;

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << obj.matrixMultiplication(arr);

    return 0;
}