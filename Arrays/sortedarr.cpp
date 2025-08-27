//1752. Check if Array is Sorted or Rotated
/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero).
Otherwise, return false.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

       
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                count++;
            }
        }

        
        if (arr[n - 1] > arr[0]) {
            count++;
        }

        return count <= 1;
    }
};

int main() {
    Solution s;

    vector<int> arr1 = {3,4,5,1,2};
    vector<int> arr2 = {2,1,3,4};
    vector<int> arr3 = {1,2,3};

    cout << (s.check(arr1) ? "true" : "false") << endl; 
    cout << (s.check(arr2) ? "true" : "false") << endl; 
    cout << (s.check(arr3) ? "true" : "false") << endl; 

    return 0;
}
