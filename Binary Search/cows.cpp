/* Topic: Binary Search on Answers
Problem: Aggressive Cows

Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. 
Find the maximum possible minimum distance

TC -->O(NlogN) + O(N * log(max(nums[])-min(nums[])))*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool CanwePlace(vector<int> &nums, int dist, int cows) {
        int n = nums.size();
        int cntCows = 1, last = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] - last >= dist) {
                cntCows++;
                last = nums[i];
            }
            if (cntCows >= cows) return true; 
        }
        return false;
    }


    int aggressiveCows(vector<int> &nums, int cows) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1, high = nums[n - 1] - nums[0], ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (CanwePlace(nums, mid, cows)) {
                ans = mid;       
                low = mid + 1;   
            } else {
                high = mid - 1;  
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;

    int result = sol.aggressiveCows(stalls, cows);
    cout << "Largest minimum distance = " << result << endl;

    return 0;
}
