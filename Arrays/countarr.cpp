/*Count Occurrences in a Sorted Array
You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.
Return the count of occurrences of target in the array.

TC -->2*O(logN)
SC -->O(1)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstOccurence(const vector<int>& nums, int n , int x) {
        int low = 0 , high = n-1;
        int first = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == x){
                first = mid;
                high = mid - 1; 
            }
            else if(nums[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }  
        return first;
    }

    int lastOccurence(const vector<int>& nums, int n , int x) {
        int low = 0 , high = n-1;
        int last = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == x){
                last = mid;
                low = mid + 1; 
            }
            else if(nums[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return last;
    }

    int countOccurrences(const vector<int>& arr, int target) {
        int n = arr.size();
        int first = firstOccurence(arr, n, target);
        if (first == -1) return 0; 
        int last = lastOccurence(arr, n, target);
        return last - first + 1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,2,2,2,3,4,5,5,5,6};
    int target = 5;
    cout << "Count of " << target << " = " << sol.countOccurrences(arr, target) << endl;
    return 0;
}
