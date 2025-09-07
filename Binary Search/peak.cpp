/*162. Find Peak Element
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

TC -->O(logN)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1; 
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Peak index in [1, 2, 3, 1] = " << sol.findPeakElement(nums1) << endl;

    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak index in [1, 2, 1, 3, 5, 6, 4] = " << sol.findPeakElement(nums2) << endl;

    vector<int> nums3 = {10};
    cout << "Peak index in [10] = " << sol.findPeakElement(nums3) << endl;

    return 0;
}
