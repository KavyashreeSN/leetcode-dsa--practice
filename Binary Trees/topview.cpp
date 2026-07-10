/*Top View of BT

Given the root of a binary tree, return the top view of the binary tree.



The top view of a binary tree consists of the set of nodes visible when the tree is observed from above.



Return the values of these nodes ordered from the leftmost to the rightmost position.



If multiple nodes share the same horizontal distance from the root,
 only the node that appears first when traversing from left to right (i.e., the leftmost node) should be included in the result.
 
 TC -->O(N)
 SC -->O(N)*/


#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition of Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> topView(Node* root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }

            if (node->left != NULL)
                q.push({node->left, line - 1});

            if (node->right != NULL)
                q.push({node->right, line + 1});
        }

        for (auto x : mpp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7

    Top View = 4 2 1 3 7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<int> ans = obj.topView(root);

    cout << "Top View: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}