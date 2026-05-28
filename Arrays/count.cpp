/*Count subarrays with given xor K

Given an array of integers nums and an integer k, 
return the total number of subarrays whose XOR equals to k.

TC -->O(N)or O(logN)
SC -->O(N) (worst case when all the elements in the map is unique)
*/



#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int> &nums, int k) {

        int xr = 0;
        int cnt = 0;

        map<int, int> mpp;

        mpp[xr]++;

        for (int i = 0; i < nums.size(); i++) {

            xr = xr ^ nums[i];

            int x = xr ^ k;

            cnt += mpp[x];

            mpp[xr]++;
        }

        return cnt;
    }
};

int main() {

    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    int ans = obj.subarraysWithXorK(nums, k);

    cout << "Number of subarrays with XOR " << k << " = " << ans << endl;

    return 0;
}