/*213.House Robber ||

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    long long maxSum(vector<int>& nums) {
        if (nums.empty())
            return 0;

        long long prev2 = 0;
        long long prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            long long include = nums[i] + prev2;
            long long exclude = prev;

            long long curr = max(include, exclude);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;

        if (nums.size() == 1)
            return nums[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < nums.size(); i++) {

            // Exclude first house
            if (i != 0)
                temp1.push_back(nums[i]);

            // Exclude last house
            if (i != nums.size() - 1)
                temp2.push_back(nums[i]);
        }

        return max(maxSum(temp1), maxSum(temp2));
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

    cout << obj.rob(nums) << endl;

    return 0;
}