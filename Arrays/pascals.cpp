/*118.Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

TC -->O(N)


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int numRows;

    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> numRows;

    vector<vector<int>> result = sol.generate(numRows);

    cout << "\nPascal's Triangle:\n";
    for (auto &row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
