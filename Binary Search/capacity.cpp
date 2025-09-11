/*1011. Capacity to shift pakages within D days.
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

TC --> log((sum - max +1) *O(N)
SC -->O(1)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDays(vector<int> &weights , int cap) {
        int day = 1, load = 0;
        int n = weights.size();
        for(int i = 0; i < n; i++) {
            if(load + weights[i] > cap) {
                day++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0); 
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int numberofdays = findDays(weights, mid);
            if(numberofdays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << "Minimum ship capacity to ship within " << days << " days is: " 
         << sol.shipWithinDays(weights, days) << endl;

    return 0;
}
