/*45.Jump Game 2

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1.
The test cases are generated such that you can reach index n - 1.

TC -->O(N)

 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, l = 0, r = 0;

        while (r < n - 1) {
            int farthest = 0;

            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Minimum jumps required: " << obj.jump(nums) << endl;

    return 0;
}