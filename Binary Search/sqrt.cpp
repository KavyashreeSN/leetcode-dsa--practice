#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long floorSqrt(long long n) {
        long long low = 1, high = n;
        while (low <= high) {
            long long mid = (low + high) / 2;

            if (mid * mid <= n) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return high;
    }
};

int main() {
    Solution sol;

    cout << "floorSqrt(1) = " << sol.floorSqrt(1) << endl;
    cout << "floorSqrt(10) = " << sol.floorSqrt(10) << endl;
    cout << "floorSqrt(25) = " << sol.floorSqrt(25) << endl;
    cout << "floorSqrt(1000000000) = " << sol.floorSqrt(1000000000LL) << endl;

    return 0;
}
