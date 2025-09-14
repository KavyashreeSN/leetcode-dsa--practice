/*4.Median of two sorted array
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
Level : Hard


TC -->O(log(min(n1 , n2)))
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1 =  nums1.size();
       int n2 = nums2.size();
       if(n1 > n2) return findMedianSortedArrays(nums2, nums1); // perform the binary search on smaller array
       
       int low = 0, high = n1;
       int left = (n1 + n2 + 1) / 2;
       int n = n1 + n2;
       
       while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1; // number of elements that i require on the left
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2); // odd condition
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) {
                high = mid1 - 1; // high condition
            }
            else {
                low = mid1 + 1;
            }
       }
       return 0;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median is: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Median is: " << sol.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}
