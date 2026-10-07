/*1059. Print Longest Increasing Subsequence
Given an array of n integers arr, return the Longest Increasing Subsequence (LIS) that is Index-wise Lexicographically Smallest.

The Longest Increasing Subsequence (LIS) is the longest subsequence where all elements are in strictly increasing order.

A subsequence A1 is Index-wise Lexicographically Smaller than another subsequence A2 if, at the first position where A1 and A2 differ, the element in A1 appears earlier in the array arr than corresponding element in S2.

Your task is to return the LIS that is Index-wise Lexicographically Smallest from the given array.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
        int n = arr.size();

        if (n == 0) {
            return {};
        }

        vector<int> dp(n, 1);
        vector<int> parent(n);
        int longestEnd = 0;

        for (int current = 0; current < n; current++) {
            parent[current] = current;

            for (int previous = 0; previous < current; previous++) {
                if (arr[previous] < arr[current] &&
                    dp[previous] + 1 > dp[current]) {
                    dp[current] = dp[previous] + 1;
                    parent[current] = previous;
                }
            }

            if (dp[current] > dp[longestEnd]) {
                longestEnd = current;
            }
        }

        vector<int> answer;

        while (parent[longestEnd] != longestEnd) {
            answer.push_back(arr[longestEnd]);
            longestEnd = parent[longestEnd];
        }

        answer.push_back(arr[longestEnd]);

        reverse(answer.begin(), answer.end());

        return answer;
    }
};

int main() {
    vector<int> arr = {5, 1, 6, 2, 3, 4};

    Solution obj;
    vector<int> answer = obj.longestIncreasingSubsequence(arr);

    for (int value : answer) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}