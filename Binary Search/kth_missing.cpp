/*1539.Kth Missing Positive Number.
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

TC --> O(N)
SC -->O(N)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0 , high = n-1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1); 
            
            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high + 1 + k;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "The " << k << "th missing positive number is: " 
         << sol.findKthPositive(arr, k) << endl;

    return 0;
}
