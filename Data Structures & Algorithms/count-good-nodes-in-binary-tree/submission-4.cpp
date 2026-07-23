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
    int goodNodes(TreeNode* root) {
        int maxVal = std::numeric_limits<int>::min();
        return dfs(root, maxVal);
    }

    // Performs depth first search starting at ROOT and tracks the
    // largest value on the path, MAXVAL of previously visited nodes.
    // Returns the number of "good" nodes in the tree rooted at ROOT
    int dfs(TreeNode* root, int maxVal) {
        // Base case: no tree
        if (root == nullptr) return 0;

        // Recursive case: this node is not null
        // It's counts as "good" if the path contains no nodes greater than this node's value
        // (which means !(maxVal > root->val) or maxVal <= root->val))
        int result = (root->val >= maxVal ? 1 : 0);
        maxVal = std::max(root->val, maxVal);
        return result + dfs(root->left, maxVal) + dfs(root->right, maxVal);
    }
};
