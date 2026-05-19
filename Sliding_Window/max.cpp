/*1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

TC -->O(N)+O(N) = O(2N)
SC -->O(1)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0, z = 0, maxlen = 0;

        for(int r = 0; r < nums.size(); r++) {

            if(nums[r] == 0)
                z++;

            while(z > k) {
                if(nums[l] == 0)
                    z--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << obj.longestOnes(nums, k);

    return 0;
}