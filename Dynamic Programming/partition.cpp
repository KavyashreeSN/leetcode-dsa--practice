/*416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<bool> prev(k + 1, 0), cur(k + 1, 0);

        prev[0] = cur[0] = true;

        if (arr[0] <= k)
            prev[arr[0]] = true;

        for (int ind = 1; ind < arr.size(); ind++) {
            for (int target = 1; target <= k; target++) {

                bool notTake = prev[target];

                bool take = false;

                if (arr[ind] <= target)
                    take = prev[target - arr[ind]];

                cur[target] = take || notTake;
            }

            prev = cur;
        }

        return prev[k];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totSum += nums[i];
        }

        if (totSum % 2)
            return false;

        int target = totSum / 2;

        return subsetSumToK(n, target, nums);
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

    if (obj.canPartition(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}