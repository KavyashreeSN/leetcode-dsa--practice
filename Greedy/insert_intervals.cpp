/*57. insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

TC -->O(N)*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        // Add intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add the merged interval
        res.push_back(newInterval);

        // Add remaining intervals
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals (start end):\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);
    cout << "Enter new interval: ";
    cin >> newInterval[0] >> newInterval[1];

    Solution obj;
    vector<vector<int>> ans = obj.insert(intervals, newInterval);

    cout << "Intervals after insertion:\n";
    for (auto interval : ans) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}