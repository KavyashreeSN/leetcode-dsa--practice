/*1021. Remove Outermost Parenthesis

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

TC -->O(N)
SC -->O(1)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";  
        int level = 0;       
        for (char ch : s) {
            if (ch == '(') {
                if (level > 0) result += ch;
                level++;  
            } 
            else if (ch == ')') {
                level--;  
                if (level > 0) result += ch;
            }
        }

        return result;
    }
};

int main() {
    string s = "(()())(())";  
    Solution sol;             
    string ans = sol.removeOuterParentheses(s);

    cout << "The result is: " << ans << endl;

    return 0;
}