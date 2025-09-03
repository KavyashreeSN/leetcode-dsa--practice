/*704. Binary Search
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
 If target exists, then return its index. Otherwise, return -1.
 
 TC -->O(logN)*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; 

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int result = sol.search(nums, target);
    if (result != -1)
        cout << "Target " << target << " found at index: " << result << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;

    return 0;
}
