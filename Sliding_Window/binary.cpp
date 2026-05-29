/*930.Binary Subarrays with Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.


TC -->O(2*2N)
SC -->O(1)*/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int atMost(vector<int>& nums, int goal) {

        if (goal < 0) return 0;

        int l = 0;
        int sum = 0;
        int cnt = 0;

        for (int r = 0; r < nums.size(); r++) {

            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            cnt += (r - l + 1);
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main() {

    int n, goal;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter binary array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter goal: ";
    cin >> goal;

    Solution obj;

    int ans = obj.numSubarraysWithSum(nums, goal);

    cout << "Number of subarrays with sum " << goal << " = " << ans << endl;

    return 0;
}