/*Detect a cycle in an undirected graph -->BFS 
Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. 
Determine if the graph contains any cycles.

TC -->O(V +2E)*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool bfs(int src, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int, int>> q; // {node, parent}

        vis[src] = 1;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent) {
                    return true; // Cycle detected
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;

    if (obj.isCycle(V, adj))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}