/*907.Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

TC -->O(5N)
SC -->O(5N)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int mod = 1e9 + 7;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }

        return (int)total;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {3, 1, 2, 4};

    int result = sol.sumSubarrayMins(arr);

    cout << "Sum of Subarray Minimums: " << result << endl;

    return 0;
}