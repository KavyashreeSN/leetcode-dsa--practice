/*Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array.
If the target is not found in the array, return -1*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 4, 6, 8, 10};
    int target = 8;

    int result = sol.linearSearch(nums, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
