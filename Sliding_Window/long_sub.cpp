/*Longest Substring With At Most K Distinct Characters

Given a string s and an integer k.
Find the length of the longest substring with at most k distinct characters.

TC -->O(2N)
SC -->O(256)*/



#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        if (k == 0 || s.empty()) return 0;

        int maxlen = 0, l = 0;
        unordered_map<char, int> mpp;

        for (int r = 0; r < s.size(); r++) {
            mpp[s[r]]++;

            while (mpp.size() > k) {
                mpp[s[l]]--;

                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);

                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    cout << "Length of longest substring with at most "
         << k << " distinct characters = "
         << obj.kDistinctChar(s, k) << endl;

    return 0;
}