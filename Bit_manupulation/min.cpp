/*2220.Minimum Bit flips to convert number 

A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

*/
#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;   // XOR to find differing bits
        int cnt = 0;

        for (int i = 0; i < 32; i++) {
            if (ans & (1 << i)) {
                cnt = cnt + 1;
            }
        }

        return cnt;
    }
};

int main() {
    int start, goal;

    cout << "Enter start number: ";
    cin >> start;

    cout << "Enter goal number: ";
    cin >> goal;

    Solution obj;
    int result = obj.minBitFlips(start, goal);

    cout << "Minimum Bit Flips Required: " << result << endl;

    return 0;
}