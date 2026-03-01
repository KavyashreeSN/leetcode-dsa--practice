/*78.Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int total = 1 << nums.size();
        vector<vector<int>> ans;
         
        for(int n = 0; n < total; n++){
            vector<int> list;
            for(int i = 0; i < nums.size(); i++){
                if(n & (1 << i)){
                    list.push_back(nums[i]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = obj.subsets(nums);

    cout << "Subsets are:\n";
    for(auto subset : result){
        cout << "{ ";
        for(auto val : subset){
            cout << val << " ";
        }
        cout << "}\n";
    }

    return 0;
}