/*8.String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

TC --.O(n)
SC -->o(n)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;

    int helper(const string &s, int i, long long num, int sign) {
        // stop if end or non-digit
        if (i >= s.size() || !isdigit(s[i]))
            return (int)(sign * num);

        // build number
        num = num * 10 + (s[i] - '0');

        // clamp overflow
        if (sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
        if (sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

        return helper(s, i + 1, num, sign);
    }

public:
    int myAtoi(string s, int i = 0) {
        // skip spaces
        while (i < s.size() && s[i] == ' ') i++;

        // sign check
        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
};

int main() {
    Solution obj;

    string s1 = "   -12345";
    string s2 = "42";
    string s3 = "4193 with words";
    string s4 = "-91283472332"; // overflow test

    cout << obj.myAtoi(s1) << endl;  // -12345
    cout << obj.myAtoi(s2) << endl;  // 42
    cout << obj.myAtoi(s3) << endl;  // 4193
    cout << obj.myAtoi(s4) << endl;  // INT_MIN

    return 0;
}
