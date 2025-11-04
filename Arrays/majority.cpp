/*229.Majority Element 2
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

TC -->O(N)
SC-->O(1)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Step 1: Find potential candidates
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify actual counts
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
        }

        int mini = (int)(nums.size() / 3) + 1;
        vector<int> result;
        if (cnt1 >= mini) result.push_back(el1);
        if (cnt2 >= mini) result.push_back(el2);

        sort(result.begin(), result.end());
        return result;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3, 2, 2, 1, 1};
    
    vector<int> ans = sol.majorityElement(nums);
    
    cout << "Majority elements (> n/3): ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
