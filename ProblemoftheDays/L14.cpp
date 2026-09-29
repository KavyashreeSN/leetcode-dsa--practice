#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;

        while (j < prefix.length() &&
               j < strs[i].length() &&
               prefix[j] == strs[i][j]) {
            j++;
        }

        prefix = prefix.substr(0, j);

        if (prefix == "")
            return "";
    }

    return prefix;
}

int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter strings: ";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << "Longest Common Prefix: "
         << longestCommonPrefix(strs) << endl;

    return 0;
}