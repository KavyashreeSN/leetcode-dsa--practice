/*Shortest Path in Directed Acyclic Graph Topological Sort

 Given a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a directed edge from vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.
Find the shortest path from source vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. The source vertex is assumed to be 0.

*/

#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<vector<pair<int, int>>> &adj,
              vector<int> &vis, stack<int> &st) {

    vis[node] = 1;

    for (auto it : adj[node]) {
        int next = it.first;

        if (!vis[next]) {
            topoSort(next, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {

    vector<vector<pair<int, int>>> adj(N);

    // Create adjacency list
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    // Topological sort
    vector<int> vis(N, 0);
    stack<int> st;

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            topoSort(i, adj, vis, st);
        }
    }

    // Distance array
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    // Process vertices in topological order
    while (!st.empty()) {

        int node = st.top();
        st.pop();

        if (dist[node] == INT_MAX)
            continue;

        for (auto it : adj[node]) {

            int next = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[next]) {
                dist[next] = dist[node] + wt;
            }
        }
    }

    // Replace unreachable vertices with -1
    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }

    return dist;
}

int main() {

    int N = 6;
    int M = 7;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {2, 3, 6},
        {4, 2, 2},
        {4, 5, 4},
        {5, 3, 1}
    };

    vector<int> ans = shortestPath(N, M, edges);

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}