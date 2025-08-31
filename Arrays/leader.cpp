/*Leaders in an Array
Given an integer array nums, return a list of all the leaders in the array.
A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. 
The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
    vector<int>ans;
      int n = nums.size();
      int maxi = INT_MIN;
      for(int i = n-1;i>=0;i--){
        if(nums[i]>maxi){
            ans.push_back(nums[i]);
        }
        maxi = max(maxi,nums[i]);
      }
      sort(ans.begin(),ans.end());
      return ans;


    }
};

int main(){
    Solution sol;
    vector<int> nums = {10,22,12,3,0,6};
    vector<int>result = sol.leaders(nums);
    cout<<"Leaders in the array are";
    for(int val:result){
        cout << val << "";
    }


}