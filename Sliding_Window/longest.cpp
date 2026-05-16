/*3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

TC -->O(N)
SC -->O(256)*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> hash(256, -1);

        int l = 0;
        int maxlen = 0;

        for (int r = 0; r < s.size(); r++) {

            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            int len = r - l + 1;

            maxlen = max(maxlen, len);

            hash[s[r]] = r;
        }

        return maxlen;
    }
};

int main() {

    string s;

    cout << "Enter the string: ";
    cin >> s;

    Solution obj;

    int ans = obj.lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: " 
         << ans << endl;

    return 0;
}