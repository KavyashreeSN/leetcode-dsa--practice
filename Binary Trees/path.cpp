#include <iostream>
#include <vector>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    bool getPath(TreeNode* root, vector<int>& path, int x) {
        if (root == NULL)
            return false;

        path.push_back(root->data);

        if (root->data == x)
            return true;

        if (getPath(root->left, path, x) || getPath(root->right, path, x))
            return true;

        path.pop_back();
        return false;
    }

public:
    vector<int> solve(TreeNode* root, int B) {
        vector<int> path;
        getPath(root, path, B);
        return path;
    }
};

int main() {
    // Creating the binary tree
    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int B;
    cout << "Enter the node value: ";
    cin >> B;

    Solution obj;
    vector<int> ans = obj.solve(root, B);

    if (ans.empty()) {
        cout << "Node not found.";
    } else {
        cout << "Path from root to node " << B << " : ";
        for (int x : ans)
            cout << x << " ";
    }

    return 0;
}