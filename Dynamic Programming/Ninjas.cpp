/*Ninja's training

A ninja has planned a n-day training schedule. 
Each day he has to perform one of three activities - running, stealth training, or fighting practice. 
The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, 
based on the activity and the given day.

Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively.
 Return the maximum possible merit points that the ninja can earn.*/


#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        vector<int> temp(4, 0);

        for (int last = 0; last < 4; last++) {
            for (int task = 0; task <= 2; task++) {
                if (task != last) {
                    temp[last] = max(temp[last],
                                     points[day][task] + prev[task]);
                }
            }
        }

        prev = temp;
    }

    return prev[3];
}

int main() {
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    int n = points.size();

    cout << ninjaTraining(n, points);
}