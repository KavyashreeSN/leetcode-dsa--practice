/*402 Remove K Digits

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

TC -->O(3N) +O(k)
SC -->O(N)+O(N)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && st.back() > num[i]) {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        // remove remaining k digits
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        if (st.empty()) return "0";

        // build result
        string res = "";
        while (!st.empty()) {
            res += st.back();
            st.pop_back();
        }

        reverse(res.begin(), res.end());

        // remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        if (res.empty()) return "0";

        return res;
    }
};


// ---------- MAIN ----------
int main() {
    Solution sol;

    string num = "10200";
    int k = 1;

    cout << "Result: " << sol.removeKdigits(num, k) << endl;

    return 0;
}