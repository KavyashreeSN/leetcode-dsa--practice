/*Leetcode 128. Longest Consecutive Sequence (Google Interview Question)
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

TC --> ~O(3N) 
SC--> O(N)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n ==0) return 0;
        int longest = -1;
        unordered_set<int>st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    x = x+1;
                    cnt = cnt+1;
                }
                longest = max(longest , cnt);
            }
        }
        return longest;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {102,4,100,1,101,3,2,1,1};
    cout << "Length of Longest Consecutive Sequence :" << sol.longestConsecutive(nums);

}