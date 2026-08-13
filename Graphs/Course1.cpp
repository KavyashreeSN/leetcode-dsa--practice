/*207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[it]) {
            return true;   // Cycle found
        }
    }

    pathVis[node] = 0;      // Backtrack
    return false;
}

int main() {

    int numCourses;
    cin >> numCourses;

    int n;
    cin >> n;   // number of prerequisites

    vector<vector<int>> prerequisites(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    // Create adjacency list
    vector<vector<int>> adj(numCourses);

    // [a,b] means b -> a
    for (auto it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(numCourses, 0);
    vector<int> pathVis(numCourses, 0);

    bool cycle = false;

    for (int i = 0; i < numCourses; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathVis)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Cannot finish all courses" << endl;
    else
        cout << "Can finish all courses" << endl;

    return 0;
}