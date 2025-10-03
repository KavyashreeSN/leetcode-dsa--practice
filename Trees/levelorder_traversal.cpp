/*102.Binary Tree Level Order Traversal.
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 */


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main() {
    // Build a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level Order Traversal:" << endl;
    for (auto &level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
