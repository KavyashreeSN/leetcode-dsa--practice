#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:

    // Calculate GCD of two numbers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    // Build Segment Tree
    void build(int node, int start, int end,
               vector<int>& arr, vector<int>& tree) {

        // Leaf node
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid, arr, tree);
        build(2 * node + 1, mid + 1, end, arr, tree);

        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    // Update arr[index] = value
    void update(int node, int start, int end,
                int index, int value, vector<int>& tree) {

        // Reached the required index
        if (start == end) {
            tree[node] = value;
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid) {
            update(2 * node, start, mid, index, value, tree);
        }
        else {
            update(2 * node + 1, mid + 1, end, index, value, tree);
        }

        // Recalculate current node
        tree[node] = gcd(tree[2 * node],
                          tree[2 * node + 1]);
    }

    // Find GCD from l to r
    int query(int node, int start, int end,
              int l, int r, vector<int>& tree) {

        // Completely outside the range
        if (r < start || end < l) {
            return 0;
        }

        // Completely inside the range
        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        int left = query(2 * node,
                         start, mid,
                         l, r, tree);

        int right = query(2 * node + 1,
                          mid + 1, end,
                          l, r, tree);

        return gcd(left, right);
    }
};


int main() {

    // Initial array
    vector<int> arr = {2, 3, 4, 6, 8, 16};

    // Queries
    vector<vector<int>> queries = {
        {0, 0, 2},
        {1, 3, 8},
        {0, 2, 5}
    };

    int n = arr.size();

    // Segment tree
    vector<int> tree(4 * n);

    SegmentTree st;

    // Build the tree
    st.build(1, 0, n - 1, arr, tree);

    vector<int> answer;

    // Process every query
    for (auto &q : queries) {

        int type = q[0];
        int x = q[1];
        int y = q[2];

        // Type 0 → GCD query
        if (type == 0) {

            int result = st.query(
                1, 0, n - 1,
                x, y, tree
            );

            answer.push_back(result);
        }

        // Type 1 → Update
        else {

            st.update(
                1, 0, n - 1,
                x, y, tree
            );

            // Also update the actual array
            arr[x] = y;
        }
    }

    // Print answer
    cout << "Output: [";

    for (int i = 0; i < answer.size(); i++) {

        cout << answer[i];

        if (i != answer.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}