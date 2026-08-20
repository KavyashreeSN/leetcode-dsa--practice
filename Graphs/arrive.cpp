/*1976. Number of ways to arrive at destination

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        // Adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            // Undirected graph
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Shortest distance from source
        vector<long long> dist(n, LLONG_MAX);

        // Number of shortest paths
        vector<int> ways(n, 0);

        // Min heap: {distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        // Source = 0
        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            pair<long long, int> current = pq.top();
            long long dis = current.first;
            int node = current.second;
            pq.pop();

            // Ignore outdated entries
            if (dis > dist[node])
                continue;

            for (auto it : adj[node]) {

                int adjNode = it.first;
                int edgeWeight = it.second;

                long long newDist = dis + edgeWeight;

                // Found a shorter path
                if (newDist < dist[adjNode]) {

                    dist[adjNode] = newDist;

                    // Number of ways is same as current node
                    ways[adjNode] = ways[node];

                    pq.push({newDist, adjNode});
                }

                // Found another shortest path
                else if (newDist == dist[adjNode]) {

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};

int main() {

    Solution obj;

    int n = 7;

    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    int ans = obj.countPaths(n, roads);

    cout << "Number of shortest paths: " << ans << endl;

    return 0;
}