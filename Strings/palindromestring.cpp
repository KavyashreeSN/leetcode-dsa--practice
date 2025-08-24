#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindromeHelper(string &s, int i, int j) {
        if (i >= j) return true;  // base case

        if (!isalnum(s[i])) return isPalindromeHelper(s, i + 1, j);
        if (!isalnum(s[j])) return isPalindromeHelper(s, i, j - 1);

        if (tolower(s[i]) != tolower(s[j])) return false;

        return isPalindromeHelper(s, i + 1, j - 1);
    }

    bool isPalindrome(string s) {
        return isPalindromeHelper(s, 0, s.size() - 1);
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (sol.isPalindrome(s))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is NOT a palindrome." << endl;

    return 0;
}
