//31 Next Permutation
//A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
//TC --> ~O(3n)
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Step 1: Find the first index "ind" from the right
        // where nums[ind] < nums[ind+1]
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If no such index exists, it's the last permutation
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find element just larger than nums[ind] from the right side
        for(int i = n - 1; i > ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: Reverse the subarray from ind+1 to end
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
