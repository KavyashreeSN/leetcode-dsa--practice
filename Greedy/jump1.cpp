/*55.Jump Game 

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

TC -->O(N)
SC -->O(1)*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;

        for (int i = 0; i < n; i++) {
            if (i > maxInd)
                return false;

            maxInd = max(maxInd, i + nums[i]);
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, 1, 1, 4};

    if (obj.canJump(nums))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}