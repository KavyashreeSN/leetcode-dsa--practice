/*76. Minimum Window Substring


Given two strings s and t of lengths m and n respectively,
 return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

TC -->O(2N)+0(M)
SC -->O(256)*/






#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);

        int n = s.size();
        int m = t.size();

        for (char c : t) {
            hash[c]++;
        }

        int l = 0, r = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int sIndex = -1;

        while (r < n) {
            if (hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};

int main() {
    Solution sol;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = sol.minWindow(s, t);

    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}