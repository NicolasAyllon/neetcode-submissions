/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // If the tree is empty, there is nothing to do
        if (root == nullptr) return root;

        // For a nonempty node, swap its children
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        // Recursively swap all nodes in the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
