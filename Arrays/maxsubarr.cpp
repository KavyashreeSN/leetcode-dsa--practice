//Given an integer array nums, find the subarray with the largest sum, and return its sum.
//Used Kadhane's Algorithm
// Time Complexity: O(n)
//Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution obj;
    int ans = obj.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << ans << endl;

    return 0;
}
