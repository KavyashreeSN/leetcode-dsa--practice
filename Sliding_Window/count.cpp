/*1248.Count number of nice subarrays

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.


TC --> O(2*2N)
SC -->O(1)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to count subarrays with at most k odd numbers
    int helper(vector<int>& nums, int k) {

        if (k < 0) return 0;

        int l = 0;
        int oddCount = 0;
        int cnt = 0;

        for (int r = 0; r < nums.size(); r++) {

            oddCount += nums[r] % 2;

            while (oddCount > k) {
                oddCount -= nums[l] % 2;
                l++;
            }

            cnt += (r - l + 1);
        }

        return cnt;
    }

    // Function to count subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {

        return helper(nums, k) - helper(nums, k - 1);
    }
};

int main() {

    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    Solution obj;

    int ans = obj.numberOfSubarrays(nums, k);

    cout << "Number of nice subarrays = " << ans << endl;

    return 0;
}