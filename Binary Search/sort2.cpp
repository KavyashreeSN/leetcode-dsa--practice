/*88. Search In Rotated Sorted Array (duplicates)
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

TC -->O(logN) on average, O(N) in the worst case (when there are many duplicates)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) return true;

            // If duplicates exist at both ends, shrink boundaries
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Example test case with duplicates
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    bool result = sol.search(nums, target);

    if (result) {
        cout << "Target " << target << " found in array." << endl;
    } else {
        cout << "Target " << target << " not found in array." << endl;
    }

    return 0;
}
