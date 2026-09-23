/*188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(k + 1, 0))
        );

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {

                    if (buy) {
                        // Buy OR skip
                        dp[ind][buy][cap] = max(
                            -prices[ind] + dp[ind + 1][0][cap],
                            dp[ind + 1][1][cap]
                        );
                    }
                    else {
                        // Sell OR skip
                        dp[ind][buy][cap] = max(
                            prices[ind] + dp[ind + 1][1][cap - 1],
                            dp[ind + 1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};

int main() {
    Solution obj;

    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    cout << "Maximum Profit: "
         << obj.maxProfit(k, prices) << endl;

    return 0;
}