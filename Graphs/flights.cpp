/*787. Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});

        // dist[i] = minimum cost to reach i
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // More than k stops are not allowed
            if (stops > k)
                continue;

            for (auto iter : adj[node]) {

                int adjNode = iter.first;
                int edgeWeight = iter.second;

                // If cheaper route is found
                if (cost + edgeWeight < dist[adjNode] && stops <= k) {

                    dist[adjNode] = cost + edgeWeight;

                    q.push({
                        stops + 1,
                        {adjNode, cost + edgeWeight}
                    });
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};

int main() {

    Solution obj;

    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    int ans = obj.findCheapestPrice(n, flights, src, dst, k);

    cout << "Cheapest Price: " << ans << endl;

    return 0;
}