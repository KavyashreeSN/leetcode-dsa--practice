/*
731. Count subsets with sum K

Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K. 
Return the result modulo (109 + 7).*/



#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int findWays(vector<int>& num, int tar) {
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    // Base case
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    if (num[0] <= tar) {
        dp[0][num[0]] = 1;
    }

    // Tabulation
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 1; sum <= tar; sum++) {

            int notTake = dp[ind - 1][sum];

            int take = 0;
            if (num[ind] <= sum) {
                take = dp[ind - 1][sum - num[ind]];
            }

            dp[ind][sum] = (notTake + take) % MOD;
        }
    }

    return dp[n - 1][tar];
}

int main() {
    int n, tar;

    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cin >> tar;

    cout << findWays(num, tar) << endl;

    return 0;
}