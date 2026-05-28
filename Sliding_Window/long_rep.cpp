/*424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

TC -->O(N)
SC -->O(26)*/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0, r = 0;
        int maxlen = 0;
        int maxf = 0;

        vector<int> freq(26, 0);

        while (r < s.size()) {

            freq[s[r] - 'A']++;

            maxf = max(maxf, freq[s[r] - 'A']);

            // Shrink window if replacements exceed k
            while ((r - l + 1) - maxf > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};

int main() {

    Solution obj;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    int ans = obj.characterReplacement(s, k);

    cout << "Longest length = " << ans << endl;

    return 0;
}