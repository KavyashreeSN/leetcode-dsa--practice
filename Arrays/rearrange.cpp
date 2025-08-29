//2149. Rearrange Array Elements by Sign
//You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

//Optimal Approach
//TC -->O(n)
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int posIndex = 0, negIndex = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                ans[negIndex] = nums[i];
                negIndex += 2;  // move to next odd index
            } else {
                ans[posIndex] = nums[i];
                posIndex += 2;  // move to next even index
            }
        }
        return ans;
    }
};
