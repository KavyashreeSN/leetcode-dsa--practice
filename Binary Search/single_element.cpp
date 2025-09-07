/*540. Single Element in Sorted Array 

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

TC --> O(logN)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }
            if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
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

    vector<int> nums1 = {1,1,2,2,3,4,4,5,5};
    cout << "Single element in [1,1,2,2,3,4,4,5,5] = " << sol.singleNonDuplicate(nums1) << endl;

    vector<int> nums2 = {3,3,7,7,10,11,11};
    cout << "Single element in [3,3,7,7,10,11,11] = " << sol.singleNonDuplicate(nums2) << endl;

    vector<int> nums3 = {42};
    cout << "Single element in [42] = " << sol.singleNonDuplicate(nums3) << endl;

    return 0;
}
