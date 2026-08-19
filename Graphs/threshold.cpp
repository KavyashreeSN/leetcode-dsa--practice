/*1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Add edges
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // Distance from a city to itself = 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    // Avoid INT_MAX addition
                    if (dist[i][k] == INT_MAX ||
                        dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }

        // Find city with minimum reachable cities
        int cntCity = n;
        int cityNo = -1;

        for (int city = 0; city < n; city++) {

            int cnt = 0;

            for (int adjCity = 0; adjCity < n; adjCity++) {

                if (dist[city][adjCity] <= distanceThreshold) {
                    cnt++;
                }
            }

            // <= ensures larger city number is selected in a tie
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

int main() {

    int n = 4;

    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    int distanceThreshold = 4;

    Solution obj;

    int ans = obj.findTheCity(n, edges, distanceThreshold);

    cout << "City: " << ans << endl;

    return 0;
}