#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Empty string matches empty pattern
    dp[0][0] = true;

    // Handle patterns like a*, a*b*, a*b*c*
    for (int j = 2; j <= m; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // Characters match or pattern has '.'
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }

            // Pattern has '*'
            else if (p[j - 1] == '*') {

                // '*' matches zero occurrences
                dp[i][j] = dp[i][j - 2];

                // '*' matches one or more occurrences
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s, p;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter pattern: ";
    cin >> p;

    if (isMatch(s, p))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}