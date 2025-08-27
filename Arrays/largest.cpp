//Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& arr, int n) {
        int largest = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }
        return largest;
    }
};

int main() {
    vector<int> arr = {3, 5, 1, 8, 2};
    Solution sol;
    cout << sol.largestElement(arr, arr.size());  
}
