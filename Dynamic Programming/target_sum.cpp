/*494.Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Tabulation Code */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countPartitions(vector<int>& nums, int d) {

        int n = nums.size();

        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }

        if (totalSum + d < 0)
            return 0;

        if ((totalSum + d) % 2 != 0)
            return 0;

        int target = (totalSum + d) / 2;

        vector<vector<int>> dp(
            n, vector<int>(target + 1, 0)
        );

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= target)
            dp[0][nums[0]] = 1;

      
        for (int ind = 1; ind < n; ind++) {

            for (int sum = 0; sum <= target; sum++) {
                int notTake = dp[ind - 1][sum];
                int take = 0;

                if (nums[ind] <= sum) {
                    take = dp[ind - 1][sum - nums[ind]];
                }

                dp[ind][sum] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return countPartitions(nums, target);
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << obj.findTargetSumWays(nums, target) << endl;

    return 0;
}