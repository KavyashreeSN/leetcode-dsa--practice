#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;   
        int prefixSum = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];     
            int remove = prefixSum - k; 

            if (mpp.find(remove) != mpp.end()) {
                cnt += mpp[remove];    
            }

            mpp[prefixSum]++;         
        }

        return cnt;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;

    Solution sol;
    int result = sol.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << " = " << result << endl;
    return 0;
}
