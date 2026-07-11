/*Bottom view of BT

Given root of binary tree, return the bottom view of the binary tree.



The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the node that appears later in level traversal.

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
    vector<int> bottomView(Node* root) {
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

            // Always update the value
            mpp[line] = node->data;

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

    Bottom View = 4 2 6 3 7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<int> ans = obj.bottomView(root);

    cout << "Bottom View: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}