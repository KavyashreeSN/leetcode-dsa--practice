//Given an array nums of size n, return the majority element.

//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
//TC -->O(n)
//SC --> O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = 0;

        // Step 1: Find candidate
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                el = nums[i];
                cnt = 1;
            }
            else if (nums[i] == el) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        // Step 2: Verify candidate
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el) cnt1++;
        }

        if (cnt1 > nums.size() / 2) {
            return el;
        }
        return -1; // No majority element
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};

    Solution obj;
    int ans = obj.majorityElement(nums);

    if (ans != -1)
        cout << "Majority element: " << ans << endl;
    else
        cout << "No majority element found." << endl;

    return 0;
}
