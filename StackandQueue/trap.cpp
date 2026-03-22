/*42.Trapping Rain Water.

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

TC -->O(N)
SC -->O(1)*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0, total = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < lmax)
                    total += lmax - height[l];
                else
                    lmax = height[l];
                l++;
            } else {
                if (height[r] < rmax)
                    total += rmax - height[r];
                else
                    rmax = height[r];
                r--;
            }
        }
        return total;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = obj.trap(height);

    cout << "Trapped Rain Water: " << result << endl;

    return 0;
}