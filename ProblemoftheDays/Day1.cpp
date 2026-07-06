/*1288. Remove Covered Intervals

Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

TC -->O(N log N + N)
SC --.O(1)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        int covered = 0;
        int maxEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= maxEnd) {
                covered++;
            } else {
                maxEnd = intervals[i][1];
            }
        }

        return intervals.size() - covered;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> intervals = {{1,4}, {3,6}, {2,8}};

    cout << obj.removeCoveredIntervals(intervals);

    return 0;
}