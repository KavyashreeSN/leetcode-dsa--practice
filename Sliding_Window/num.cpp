/*1358.Number of Substrings Containing All Three Characters

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.


TC -->O(N)
SC -->O(1)*/
#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    vector<int> lastSeen(3, -1);
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        lastSeen[s[i] - 'a'] = i;

        if (lastSeen[0] != -1 &&
            lastSeen[1] != -1 &&
            lastSeen[2] != -1) {

            cnt += 1 + min({lastSeen[0],
                            lastSeen[1],
                            lastSeen[2]});
        }
    }

    return cnt;
}

int main() {
    string s;
    cin >> s;

    cout << numberOfSubstrings(s) << endl;

    return 0;
}