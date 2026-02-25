/*136.Single Number 
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i = 0; i < nums.size(); i++){
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> nums = {4, 1, 2, 1, 2};

    int result = obj.singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}