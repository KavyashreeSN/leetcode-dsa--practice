/*Single Number - III

Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.



For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].


Example 1

Input : nums = [1, 2, 1, 3, 5, 2]

Output : [3, 5]

Explanation : The integers 3 and 5 have appeared only once.

Example 2

Input : nums = [-1, 0]

Output : [-1, 0]

Explanation : The integers -1 and 0 have appeared only once.

TC -->O(2N)
SC-->O(1)*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0;

        // Step 1: XOR all elements
        for(int i = 0; i < nums.size(); i++){
            xorr = xorr ^ nums[i];
        }

        // Step 2: Find rightmost set bit
        int rightmost = (xorr&(xorr-1))&xorr;

        int b1 = 0, b2 = 0;

        // Step 3: Divide numbers into two groups
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & rightmost)
                b1 ^= nums[i];
            else
                b2 ^= nums[i];
        }
        if(b1<b2)return {b1,b2};


        return {b2, b1};
    }
};

int main() {
    Solution obj;

    // Test case
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    vector<int> result = obj.singleNumber(nums);

    cout << "The two single numbers are: ";
    cout << result[0] << " " << result[1] << endl;

    return 0;
}