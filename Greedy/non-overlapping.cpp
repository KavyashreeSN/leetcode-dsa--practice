/*435 Non - Overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi],
 return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


 TC -->O(NlogN + N)
 SC -->O(1)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(vector<int>& val1, vector<int>& val2) {
        return val1[1] < val2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), comp);

        int cnt = 1;
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastEndTime) {
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }

        return intervals.size() - cnt;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };

    cout << obj.eraseOverlapIntervals(intervals);

    return 0;
}