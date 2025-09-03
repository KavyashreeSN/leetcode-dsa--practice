/*35.Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

TC -->O(logN)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = n; 
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; 

            if (nums[mid] >= x) {
                ans = mid;      
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};

    int x;
    cout << "Enter value to search/insert: ";
    cin >> x;

    int index = sol.searchInsert(nums, x);
    cout << "Insert position of " << x << " is: " << index << endl;

    return 0;
}
