//1. Two SUM 

/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

//Optimal solution using Hash Map
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // number -> index
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int current = nums[i];
            int moreneeded = target - current;
            
            if (mp.find(moreneeded) != mp.end()) {
                return {mp[moreneeded], i}; // found pair
            }
            
            mp[current] = i; // store current number with index
        }
        return {}; 
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call function
    vector<int> result = sol.twoSum(nums, target);

    // Output result
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
