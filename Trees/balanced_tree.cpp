/*110 . Balanced Binary Tree.

Given a binary tree, determine if it is height-balanced.

TC -->O(N)
SC -->O(N)

🧠 Explanation

Problem:
A binary tree is height-balanced if,
for every node,
|height(left) - height(right)| ≤ 1.

Approach:
Use recursion to compute the height, but:

If a subtree is unbalanced, return -1 immediately.

Otherwise, return its height normally.*/


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    // Example 1: Balanced Tree
    //
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    Solution sol;
    cout << "Tree 1 is balanced? " 
         << (sol.isBalanced(root1) ? "Yes" : "No") << endl;

    // Example 2: Unbalanced Tree
    //
    //        1
    //       /
    //      2
    //     /
    //    3
    //
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    cout << "Tree 2 is balanced? " 
         << (sol.isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}
