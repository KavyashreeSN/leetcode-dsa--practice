/*714. Best Time to Buy and Sell Stock with Transaction Fee

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int aheadNotBuy, aheadBuy;
        int curBuy, curNotBuy;

        aheadNotBuy = aheadBuy = 0;

        for (int ind = n - 1; ind >= 0; ind--) {

            curNotBuy = max(
                prices[ind] + aheadBuy,
                0 + aheadNotBuy
            );

            curBuy = max(
                -prices[ind] - fee + aheadNotBuy,
                0 + aheadBuy
            );

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }

        return aheadBuy;
    }
};

int main() {
    Solution obj;

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    cout << "Maximum Profit: " << obj.maxProfit(prices, fee) << endl;

    return 0;
}