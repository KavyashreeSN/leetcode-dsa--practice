/*17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string curr;

        function<void(int)> backtrack = [&](int idx) {
            if (idx == digits.size()) {
                ans.push_back(curr);
                return;
            }

            string letters = mp[digits[idx] - '0'];

            for (char ch : letters) {
                curr.push_back(ch);
                backtrack(idx + 1);
                curr.pop_back();
            }
        };

        backtrack(0);
        return ans;
    }
};

int main() {
    Solution sol;
    string digits;
    cin >> digits;

    vector<string> ans = sol.letterCombinations(digits);

    for (string s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
