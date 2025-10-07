#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> preInPostTraversal(TreeNode* root) {
        vector<int> pre, in, post;
        if (root == nullptr) return {pre, in, post};
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            if (it.second == 1) {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->left != nullptr) {
                    st.push({it.first->left, 1}); // fixed missing semicolon
                }
            }
            else if (it.second == 2) {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->right != nullptr) {
                    st.push({it.first->right, 1});
                }
            }
            else {
                post.push_back(it.first->val);
            }
        }
        return {pre, in, post}; // return all traversals
    }
};

int main() {
    /*
           1
          / \
         2   3
        / \
       4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    vector<vector<int>> result = obj.preInPostTraversal(root);

    cout << "Preorder: ";
    for (int x : result[0]) cout << x << " ";
    cout << "\nInorder: ";
    for (int x : result[1]) cout << x << " ";
    cout << "\nPostorder: ";
    for (int x : result[2]) cout << x << " ";
    cout << endl;

    return 0;
}