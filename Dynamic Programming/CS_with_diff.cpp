/*722. Count partitions with given difference
Given an array arr of n integers and an integer diff, count the number of ways to partition the array into two subsets S1 and S2 such that:

∣S1−S2∣ = diff and S1 ≥ S2
Where |S1| and |S2| are sum of Subsets S1 and S2 respectively.
Return the result modulo 109 + 7.

*/


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countPartitions(int n, int d, vector<int>& arr) {

    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Check if valid partition is possible
    if (totalSum - d < 0 || (totalSum + d) % 2 != 0) {
        return 0;
    }

    int target = (totalSum + d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base case
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    if (arr[0] <= target) {
        dp[0][arr[0]] = 1;
    }

    // Tabulation
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 1; sum <= target; sum++) {

            int notTake = dp[ind - 1][sum];

            int take = 0;

            if (arr[ind] <= sum) {
                take = dp[ind - 1][sum - arr[ind]];
            }

            dp[ind][sum] = (notTake + take) % MOD;
        }
    }

    return dp[n - 1][target];
}

int main() {

    int n, d;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> d;

    cout << countPartitions(n, d, arr) << endl;

    return 0;
}