//121. Best Time to Buy and Sell Stocks
/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.*/

//TC -->O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);          
            maxPro = max(maxPro, prices[i] - minPrice);   
        }
        
        return maxPro;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Max Profit: " << sol.maxProfit(prices) << endl;

    return 0;
}
