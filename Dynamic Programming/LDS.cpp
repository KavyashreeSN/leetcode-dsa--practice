/*368. Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return {};
        }

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n);

        int bestEnd = 0;

        for (int current = 0; current < n; current++) {
            parent[current] = current;

            for (int previous = 0; previous < current; previous++) {

                bool divisible = nums[current] % nums[previous] == 0;
                bool longer = dp[previous] + 1 > dp[current];

                if (divisible && longer) {
                    dp[current] = dp[previous] + 1;
                    parent[current] = previous;
                }
            }

            if (dp[current] > dp[bestEnd]) {
                bestEnd = current;
            }
        }

        vector<int> answer;

        while (parent[bestEnd] != bestEnd) {
            answer.push_back(nums[bestEnd]);
            bestEnd = parent[bestEnd];
        }

        answer.push_back(nums[bestEnd]);

        reverse(answer.begin(), answer.end());

        return answer;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<int> answer = obj.largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";

    for (int x : answer) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}