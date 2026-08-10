/*662. Maximum Width of Binary Tree 
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

TC -->O(N)
SC -->O(N) -->Queue Data Structure used */

#include <iostream>
#include <queue>
#include <algorithm>
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        unsigned long long maxWidth = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                unsigned long long currIndex = q.front().second - minIndex;
                q.pop();

                if (i == 0)
                    first = currIndex;
                if (i == size - 1)
                    last = currIndex;

                if (node->left)
                    q.push({node->left, 2 * currIndex + 1});

                if (node->right)
                    q.push({node->right, 2 * currIndex + 2});
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return (int)maxWidth;
    }
};

int main() {
    /*
            1
          /   \
         3     2
        / \     \
       5   3     9

    Maximum width = 4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);

    Solution obj;

    cout << "Maximum Width of Binary Tree: "
         << obj.widthOfBinaryTree(root) << endl;

    return 0;
}