/*309. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[ind][buy]
        // buy = 1 -> can buy
        // buy = 0 -> can sell

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {

            // Can buy
            dp[ind][1] = max(
                -prices[ind] + dp[ind + 1][0],
                dp[ind + 1][1]
            );

            // Can sell
            dp[ind][0] = max(
                prices[ind] + dp[ind + 2][1],
                dp[ind + 1][0]
            );
        }

        return dp[0][1];
    }
};

int main() {
    Solution obj;

    vector<int> prices = {1, 2, 3, 0, 2};

    cout << "Maximum Profit: "
         << obj.maxProfit(prices) << endl;

    return 0;
}