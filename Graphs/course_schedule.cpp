/*207.Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 TC -->O(V+2E)+O(V)*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};

int main() {
    int numCourses, m;

    cout << "Enter number of courses: ";
    cin >> numCourses;

    cout << "Enter number of prerequisite pairs: ";
    cin >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));

    cout << "Enter prerequisite pairs (course prerequisite):\n";
    for (int i = 0; i < m; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    Solution obj;

    if (obj.canFinish(numCourses, prerequisites))
        cout << "True (All courses can be finished)\n";
    else
        cout << "False (Cycle detected, cannot finish all courses)\n";

    return 0;
}