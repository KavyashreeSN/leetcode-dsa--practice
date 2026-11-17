/*312.Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Tabulation
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {

                if (i > j)
                    continue;

                int maxi = INT_MIN;

                for (int ind = i; ind <= j; ind++) {

                    int cost = nums[i - 1] * nums[ind] * nums[j + 1]
                             + dp[i][ind - 1]
                             + dp[ind + 1][j];

                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << obj.maxCoins(nums) << endl;

    return 0;
}