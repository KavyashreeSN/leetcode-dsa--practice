#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> &nums, int x) {
        int n = nums.size();
        int ans = n;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (n == 0) return -1;
        int m = matrix[0].size();
        int cnt_max = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            int cnt_ones = m - lowerBound(matrix[i], 1);
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 1}
    };
    Solution s;
    int result = s.rowWithMax1s(matrix);
    cout << "Row with maximum 1's is: " << result << endl;
}

