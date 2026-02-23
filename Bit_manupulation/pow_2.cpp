/*231.Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (obj.isPowerOfTwo(n)) {
        cout << n << " is a power of two" << endl;
    } else {
        cout << n << " is NOT a power of two" << endl;
    }

    return 0;
}