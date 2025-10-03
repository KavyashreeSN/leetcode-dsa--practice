/*145.Binart Tree Postorder Traversal
Given the root of a binary tree, return the postorder traversal of its nodes' values.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

private:
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        inorder(node->left, res);      // Visit left
        res.push_back(node->val);      // Visit root
        inorder(node->right, res);     // Visit right
    }
};

int main() {
    // Build a sample tree:
    //        1
    //         \
    //          2
    //         /
    //        3

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Free memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
