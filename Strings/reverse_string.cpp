/*151.Reverse Words in a  String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

TC -->O(N)
SC -->O(N)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());

        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "  the sky   is blue  ";
    cout << sol.reverseWords(s);
    // Output: "blue is sky the"
    return 0;
}
