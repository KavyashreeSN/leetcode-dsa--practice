/*Leetcode 543. Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

TC -->O(N)
SC -->O(N)*/

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        Height(root, diameter);
        return diameter;
    }

private:
    int Height(TreeNode* root, int& diameter) {
        if (!root) return 0;
        int lh = Height(root->left, diameter);
        int rh = Height(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};

int main() {
    // Example tree:
    //
    //          1
    //         / \
    //        2   3
    //       / \
    //      4   5
    //
    // Longest path = 4 -> 2 -> 1 -> 3 or 5 -> 2 -> 1 -> 3
    // Diameter = 3 edges

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of the Binary Tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
