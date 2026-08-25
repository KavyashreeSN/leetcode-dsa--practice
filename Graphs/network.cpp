/*1319.Number of Operations to Make Network Connected

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

*/


#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int cntExtras = 0;

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }

        int cntComponents = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) {
                cntComponents++;
            }
        }

        int required = cntComponents - 1;

        if (cntExtras >= required)
            return required;

        return -1;
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> connections(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }

    Solution obj;

    cout << obj.makeConnected(n, connections) << endl;

    return 0;
}