/*123.Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

//3D - DP Tabulation code 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[ind][buy][cap]
        // buy = 1 -> can buy
        // buy = 0 -> can sell
        // cap = transactions remaining

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, 0))
        );

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    if (buy) {
                        // Buy or skip
                        dp[ind][buy][cap] = max(
                            -prices[ind] + dp[ind + 1][0][cap],
                            dp[ind + 1][1][cap]
                        );
                    }
                    else {
                        // Sell or skip
                        dp[ind][buy][cap] = max(
                            prices[ind] + dp[ind + 1][1][cap - 1],
                            dp[ind + 1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

int main() {
    Solution obj;

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << "Maximum Profit: "
         << obj.maxProfit(prices) << endl;

    return 0;
}