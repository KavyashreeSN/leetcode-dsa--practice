/*678.Valid Parenthesis String 

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

TC -->O(N)
SC -->O(1)*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                minOpen++;
                maxOpen++;
            }
            else if (s[i] == ')') {
                minOpen--;
                maxOpen--;
            }
            else { // '*'
                minOpen--;
                maxOpen++;
            }

            if (minOpen < 0)
                minOpen = 0;

            if (maxOpen < 0)
                return false;
        }

        return (minOpen == 0);
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    if (obj.checkValidString(s))
        cout << "Valid Parenthesis String" << endl;
    else
        cout << "Invalid Parenthesis String" << endl;

    return 0;
}