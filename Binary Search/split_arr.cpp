/*410.Split Array Largest Sum.
Given an integer array nums and an integer k, 
split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

TC -->O(n * log(sum(nums)))
SC -->O(1)*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPartitions(vector<int> &nums, long long maxSum) {
        int partitions = 1;
        long long subarraySum = 0;

        for (int num : nums) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);  // sum as long long

        while (low <= high) {
            long long mid = (low + high) / 2;
            int partitions = countPartitions(nums, mid);

            if (partitions > k) {
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }
        return (int)low; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    int result = sol.splitArray(nums, k);

    cout << "Minimum largest subarray sum when split into " << k << " parts = " << result << endl;

    return 0;
}
