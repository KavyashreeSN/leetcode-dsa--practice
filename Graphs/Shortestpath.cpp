#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest path from source to all vertices
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> adj[N]; 

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        int dist[N];
        for (int i = 0; i < N; i++) 
            dist[i] = 1e9;

        dist[src] = 0;
        queue<int> q;

        q.push(src); 
        //BFS traversal 
        while (!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        vector<int> ans(N, -1);

        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }

        
        return ans; 
    }
};

// Driver code
int main() {

    // Number of vertices and edges
    int N = 9, M = 10;

    // Edge list representing the undirected graph
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
        {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };

    // Create object of Solution class
    Solution obj;

    // Call the shortestPath function with source as node 0
    vector<int> ans = obj.shortestPath(edges, N, M, 0);

    // Print the shortest distances from source to each node
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
