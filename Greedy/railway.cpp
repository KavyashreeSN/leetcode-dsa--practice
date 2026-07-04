#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
        int n = Arrival.size();

        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int i = 0, j = 0;
        int cnt = 0, maxcnt = 0;

        while (i < n && j < n) {
            if (Arrival[i] <= Departure[j]) {
                cnt++;
                maxcnt = max(maxcnt, cnt);
                i++;
            } else {
                cnt--;
                j++;
            }
        }

        return maxcnt;
    }
};

int main() {
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    vector<int> Arrival(n), Departure(n);

    cout << "Enter arrival times:\n";
    for (int i = 0; i < n; i++) {
        cin >> Arrival[i];
    }

    cout << "Enter departure times:\n";
    for (int i = 0; i < n; i++) {
        cin >> Departure[i];
    }

    Solution obj;
    int ans = obj.findPlatform(Arrival, Departure);

    cout << "Minimum number of platforms required = " << ans << endl;

    return 0;
}