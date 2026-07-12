/*199.Binary Tree Right Side View 
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


TC -->O(N)*/


#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (root == NULL)
            return;

        // First node visited at this level
        if (res.size() == level)
            res.push_back(root->val);

        // Visit right first
        recursion(root->right, level + 1, res);

        // Then left
        recursion(root->left, level + 1, res);
    }
};

int main() {
    /*
            1
           / \
          2   3
           \   \
            5   4

    Right View: 1 3 4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> ans = obj.rightSideView(root);

    cout << "Right Side View: ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}