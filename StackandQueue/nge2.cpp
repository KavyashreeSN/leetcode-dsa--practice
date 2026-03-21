/*503. Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number.
 If it doesn't exist, return -1 for this number.
 
 TC -->O(4N)
 SC -->O(2N)*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        stack<int> st;
        for(int i = 2*n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if(i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    
    vector<int> nums = {1, 2, 1};  // You can change input here
    
    vector<int> result = obj.nextGreaterElements(nums);
    
    cout << "Next Greater Elements: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}