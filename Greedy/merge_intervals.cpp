/*56.Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

TC -->O(NlogN + N)
SC -->O(N)*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeInterval;

        if (intervals.empty()) {
            return mergeInterval;
        }

        sort(intervals.begin(), intervals.end());

        vector<int> tempInt = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= tempInt[1]) {
                tempInt[1] = max(tempInt[1], intervals[i][1]);
            } else {
                mergeInterval.push_back(tempInt);
                tempInt = intervals[i];
            }
        }

        // Add the last interval
        mergeInterval.push_back(tempInt);

        return mergeInterval;
    }
};

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter the intervals (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution obj;
    vector<vector<int>> ans = obj.merge(intervals);

    cout << "Merged Intervals:\n";
    for (auto interval : ans) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}