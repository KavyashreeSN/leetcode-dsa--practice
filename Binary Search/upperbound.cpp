/*Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
If no such index is found, return the size of the array.

TC -->O(logN)*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> &nums, int x) {
        int n = nums.size();
        int ans = n; 
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; 

            if (nums[mid] > x) {
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
    vector<int> nums = {1, 2, 4, 6, 8};
    
    int x;
    cout << "Enter value to find lower bound of: ";
    cin >> x;

    int index = sol.lowerBound(nums, x);

    if (index < nums.size())
        cout << "Lower bound of " << x << " is at index " << index 
             << " with value " << nums[index] << endl;
    else
        cout << "No element >= " << x << " found, returning size " << index << endl;

    return 0;
}
