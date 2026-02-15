/*50.Pow(x,n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

TC -->O (Log n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long long nn = n;   // copy of n (so original n is safe)
        
        // handle negative power
        if (nn < 0) nn = -1 * nn;

        while (nn) {
            // if power is odd
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            }
            // if power is even
            else {
                x = x * x;
                nn = nn / 2;
            }
        }

        // if original n was negative
        if (n < 0) ans = 1.0 / ans;

        return ans;
    }
};

int main() {
    Solution obj;

    cout << obj.myPow(2.0, 10) << endl;   // 1024
    cout << obj.myPow(2.0, -2) << endl;   // 0.25
    cout << obj.myPow(3.0, 3) << endl;    // 27
    cout << obj.myPow(5.0, 0) << endl;    // 1

    return 0;
}
