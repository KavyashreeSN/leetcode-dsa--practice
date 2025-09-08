/*875.Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

TC -->O(n log(maxPile)).
SC -->O(1)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(vector<int> &piles) {
        int maxi = INT_MIN;
        for (int pile : piles) {
            maxi = max(maxi, pile);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &piles, int hourly) {
        long long totalH = 0;
        for (int pile : piles) {
            totalH += (pile + hourly - 1) / hourly; 
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;  
            if (calculateTotalHours(piles, mid) <= h) {
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

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Minimum eating speed: " 
         << sol.minEatingSpeed(piles, h) << endl;

    return 0;
}
