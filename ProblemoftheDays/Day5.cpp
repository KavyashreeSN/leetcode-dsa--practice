/*Leetcode POTD 1541.Minimum Insertions to Balance a Parentheses String

Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    insertions++;
                }

                if (open > 0) {
                    open--;
                } 
                else {
                    insertions++;
                }
            }
        }

        return insertions + 2 * open;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.minInsertions(s) << endl;

    return 0;
}
