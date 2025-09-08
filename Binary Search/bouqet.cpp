/*1482.Minimum Number of days to make m bouquets.

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

TC--> O(N *log(min - max +1))
SC --> O(1)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int> &arr, int day, int m, int k) {
        int n = arr.size(); 
        int cnt = 0;
        int noOfB = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++;
            } else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = 1LL * m * k;
        int n = bloomDay.size();
        if (val > n) return -1; 

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << "Minimum days: " 
         << sol.minDays(bloomDay, m, k) << endl;

    return 0;
}
