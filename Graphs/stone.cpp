/*947. Number of Stones Removed with Same Row or Column

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 */

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    // Find ultimate parent
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 0;
        }

        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Union two nodes
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;

        // Connect row and column nodes
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;

            dsu.unite(row, col);
        }

        unordered_set<int> components;

        // Count connected components
        for (auto& stone : stones) {
            components.insert(dsu.find(stone[0]));
        }

        // Stones that can be removed
        return stones.size() - components.size();
    }
};

int main() {
    Solution obj;

    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    cout << obj.removeStones(stones) << endl;

    return 0;
}