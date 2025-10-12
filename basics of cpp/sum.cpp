#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums)
            freq[num]++;

        int sum = 0;
        // Add numbers whose frequency is divisible by k
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (it->second % k == 0)
                sum += it->first * it->second;
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 3, 3, 3, 3, 4};
    int k1 = 2;
    cout << sol.sumDivisibleByK(nums1, k1) << endl;  // Output: 16

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    cout << sol.sumDivisibleByK(nums2, k2) << endl;  // Output: 0

    vector<int> nums3 = {4, 4, 4, 1, 2, 3};
    int k3 = 3;
    cout << sol.sumDivisibleByK(nums3, k3) << endl;  // Output: 12

    return 0;
}
