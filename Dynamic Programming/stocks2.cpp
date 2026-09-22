/*122.Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

*/

//Tabulation code 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {

                if (buy) {
                    // Buy or skip
                    dp[ind][buy] = max(
                        -prices[ind] + dp[ind + 1][0],
                        dp[ind + 1][1]
                    );
                }
                else {
                    // Sell or skip
                    dp[ind][buy] = max(
                        prices[ind] + dp[ind + 1][1],
                        dp[ind + 1][0]
                    );
                }
            }
        }

        return dp[0][1];
    }
};

int main() {
    Solution obj;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit: "
         << obj.maxProfit(prices) << endl;

    return 0;
}