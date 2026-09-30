/*322.Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Tabulation code */


#include <bits/stdc++.h>
using namespace std;

class Solution {

    int f(int ind, int T, vector<int>& nums, vector<vector<int>>& dp) {

        // Base case
        if (ind == 0) {
            if (T % nums[0] == 0)
                return T / nums[0];

            return 1e9;
        }

        // Already calculated
        if (dp[ind][T] != -1)
            return dp[ind][T];

        // Not take
        int notTake = f(ind - 1, T, nums, dp);

        // Take
        int take = 1e9;

        if (nums[ind] <= T)
            take = 1 + f(ind, T - nums[ind], nums, dp);

        return dp[ind][T] = min(take, notTake);
    }

public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};

int main() {

    int n, amount;

    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cin >> amount;

    Solution obj;

    cout << obj.coinChange(coins, amount) << endl;

    return 0;
}