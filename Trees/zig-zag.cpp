/*103.Binary Tree ZigZag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

TC -->O(N)
SC -->O(N)*/

#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* Solution class implementing zigzag level order traversal */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                int index = leftToRight ? i : (size - 1 - i);
                row[index] = node->val;

                if (node->left) nodesQueue.push(node->left);
                if (node->right) nodesQueue.push(node->right);
            }

            leftToRight = !leftToRight;
            result.push_back(row);
        }

        return result;
    }
};

/* Helper function to print 2D vector */
void printZigzagOrder(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }
}

/* Main function to test the code */
int main() {
    /*
        Example Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Zigzag Level Order:
        [1]
        [3, 2]
        [4, 5, 6]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";
    printZigzagOrder(result);

    return 0;
}
