/*1049. Last Stone Weight II
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed.
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left-over stone. If there are no stones left, return 0.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += stones[i];
        }

        int target = totSum / 2;

        vector<vector<bool>> dp(
            n, vector<bool>(target + 1, false)
        );

        // Target 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // First stone
        if (stones[0] <= target) {
            dp[0][stones[0]] = true;
        }

        // Fill DP
        for (int ind = 1; ind < n; ind++) {
            for (int sum = 1; sum <= target; sum++) {

                bool notTake = dp[ind - 1][sum];

                bool take = false;

                if (stones[ind] <= sum) {
                    take = dp[ind - 1][sum - stones[ind]];
                }

                dp[ind][sum] = take || notTake;
            }
        }

        // Find the largest possible subset sum <= target
        int s1 = 0;

        for (int sum = target; sum >= 0; sum--) {
            if (dp[n - 1][sum]) {
                s1 = sum;
                break;
            }
        }

        int s2 = totSum - s1;

        return s2 - s1;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<int> stones(n);

    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    int ans = obj.lastStoneWeightII(stones);

    cout << ans << endl;

    return 0;
}