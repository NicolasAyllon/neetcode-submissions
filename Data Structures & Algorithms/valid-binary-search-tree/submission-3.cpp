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
        // A tree is valid if:
        // All values in the left subtree are less than the root's value
        // All values in the right subtree are greater than the root's value
        int min = std::numeric_limits<int>::min();
        int max = std::numeric_limits<int>::max();
        return dfs(root, min, max);
    }

    bool dfs(TreeNode* root, int min, int max) {
        // Base case:
        // An empty tree is valid, vacuously
        if (root == nullptr) return true;

        // Recursive case:
        // Check this node is between the allowable min and max
        bool nodeIsValid = root->val > min && root->val < max;
        // Now we need to check its left & subtrees.
        // All values in the left subtree must be less than or equal to this node's value (the
        // allowable max becomes this node's value) All values in the right subtree must be greater
        // than this node's value (the allowable min becomes this node's value)
        return nodeIsValid && dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
};
