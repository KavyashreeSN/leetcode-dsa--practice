//189 Rotate Array
//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution sol;
    sol.rotate(nums, 3);

    for (int x : nums) cout << x << " ";
    
}
