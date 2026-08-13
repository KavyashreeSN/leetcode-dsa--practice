/*210. Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    // [a, b] means b -> a
    for (auto it : prerequisites) {
        int course = it[0];
        int prerequisite = it[1];

        adj[prerequisite].push_back(course);
        indegree[course]++;
    }

    queue<int> q;

    // Courses with no prerequisites
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If all courses are completed
    if (topo.size() == numCourses) {
        return topo;
    }

    // Cycle exists
    return {};
}

int main() {

    int numCourses;
    cin >> numCourses;

    int n;
    cin >> n;

    vector<vector<int>> prerequisites(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<int> ans = findOrder(numCourses, prerequisites);

    if (ans.empty()) {
        cout << "No valid order exists" << endl;
    }
    else {
        cout << "Course order: ";

        for (auto it : ans) {
            cout << it << " ";
        }

        cout << endl;
    }

    return 0;
}