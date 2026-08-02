/*Check for Children Sum Property in a Binary Tree

Problem Statement: Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property. The Children Sum Property in a binary tree states that for every node, the sum of its children's values (if they exist) should be equal to the node's value. 
If a child is missing, it is considered as having a value of 0.*/

#include <iostream>
using namespace std;

// Definition for a binary tree node
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
    void changeTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        int child = 0;

        if (root->left)
            child += root->left->val;

        if (root->right)
            child += root->right->val;

        if (child >= root->val) {
            root->val = child;
        }
        else {
            if (root->left)
                root->left->val = root->val;
            else if (root->right)
                root->right->val = root->val;
        }

        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;

        if (root->left)
            tot += root->left->val;

        if (root->right)
            tot += root->right->val;

        if (root->left || root->right)
            root->val = tot;
    }
};

// Inorder Traversal
void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    /*
             50
            /  \
           7    2
          / \  / \
         3  5 1  30
    */

    TreeNode* root = new TreeNode(50);

    root->left = new TreeNode(7);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);

    cout << "Inorder before conversion:\n";
    inorder(root);

    Solution obj;
    obj.changeTree(root);

    cout << "\n\nInorder after conversion:\n";
    inorder(root);

    cout << endl;

    return 0;
}