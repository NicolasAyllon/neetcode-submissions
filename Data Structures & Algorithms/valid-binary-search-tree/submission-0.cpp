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
    bool isValidBST(TreeNode* root) {
        // A null tree is valid.
        if (root == nullptr)
            return true;
        // Left and right subtrees are valid.
        // all nodes in the left subtree are between INT_MIN and root->val
        // and all nodes in the right subtree are between root->val and INT_MAX
        return isValidBST(root->left, std::numeric_limits<int>::min(), root->val) &&
               isValidBST(root->right, root->val, std::numeric_limits<int>::max());
    }

private:
    // Require that the node's value is between lower_bound and upper_bound
    bool isValidBST(TreeNode* node, int lower_bound, int upper_bound) {
        // For a null node, the condition is vacuously true.
        if (node == nullptr)
            return true;

        // We need the node's value to be between the bounds passed in,
        // and we need to recursively check the subtrees.
        return node->val > lower_bound && node->val < upper_bound &&
               isValidBST(node->left, lower_bound, node->val) &&
               isValidBST(node->right, node->val, upper_bound);
    }
};
