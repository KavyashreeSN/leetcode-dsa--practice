/*3756. Concatenate Non Zero Digits by Sum ||

You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

For each queries[i], extract the substring s[li..ri]. Then, perform the following:

Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7.

TC -->O(N+q)
SC -->O(N)*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const long long MOD = 1000000007;

        int n = s.size();

        vector<int> nonZeroCount(n + 1, 0);
        vector<int> digits;

        // Store non-zero digits and their count
        for (int i = 0; i < n; i++) {
            nonZeroCount[i + 1] = nonZeroCount[i];

            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                nonZeroCount[i + 1]++;
            }
        }

        int m = digits.size();

        vector<long long> power10(m + 1, 1);
        vector<long long> number(m + 1, 0);
        vector<long long> digitSum(m + 1, 0);

        // Preprocessing
        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
            number[i] = (number[i - 1] * 10 + digits[i - 1]) % MOD;
            digitSum[i] = digitSum[i - 1] + digits[i - 1];
        }

        vector<int> ans;

        // Answer each query
        for (auto q : queries) {

            int left = nonZeroCount[q[0]];
            int right = nonZeroCount[q[1] + 1];

            long long sum = digitSum[right] - digitSum[left];

            long long x = (number[right] -
                          (number[left] * power10[right - left]) % MOD
                          + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "10203004";

    vector<vector<int>> queries = {
        {0, 7},
        {1, 3},
        {4, 6}
    };

    vector<int> ans = obj.sumAndMultiply(s, queries);

    cout << "Output: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}