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
    // Observe that the maximum depth of the tree is 1 more than than the max of the depths of its left and right subtrees
    // Assuming we compute the depth of the left and right subtrees, to find the depth of the entire tree, we take the max
    // of the left and right depths, and ADD 1 for the depth added by the root.
    int maxDepth(TreeNode* root) {
        // The height of a null tree is 0 (and similarly the height of a leaf node (which has null children) is 1)
        if (root == nullptr) return 0;

        // This TreeNode is not nullptr, so compute the depth of its left and right subtrees recursively
        // Then take the max of the two depths, and add 1.
        int depthLeft = maxDepth(root->left);
        int depthRight = maxDepth(root->right);
        return 1 + std::max(depthLeft, depthRight);
    }
};
