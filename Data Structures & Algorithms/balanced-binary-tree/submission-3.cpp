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
    // Note: A tree is balanced if its left and right subtrees' heights do not differ by more than 1
    // AND the left and right subtrees are, themselves, balanced.

    // Returns whether the tree rooted at ROOT is balanced
    bool isBalanced(TreeNode* root) {
        // Calculate the height of the left and right subtrees
        auto [balanced, height] = dfs(root);
        return balanced;
    }

    // Returns a pair where the first value is a boolean indicating if the tree is balanced
    // and the second value is an int which gives the height of the tree
    std::pair<bool, int> dfs(TreeNode* root) {
        // Base case: an empty tree is balanced and its height is 0
        if (root == nullptr) return {true, 0};
        // Recursive case: first check if the left and right subtrees are balanced
        auto [leftIsBalanced, leftHeight] = dfs(root->left);
        auto [rightIsBalanced, rightHeight] = dfs(root->right);
        bool rootIsBalanced = std::abs(leftHeight - rightHeight) <= 1;
        int height = 1 + std::max(leftHeight, rightHeight);

        return {leftIsBalanced && rightIsBalanced && rootIsBalanced, 
                height};
    }
};
