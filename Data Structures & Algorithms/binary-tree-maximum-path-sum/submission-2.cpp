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
    int maxPathSum(TreeNode* root) {
        // result is the max path in the whole tree with root 'root'
        int result = std::numeric_limits<int>::min();
        int max_path_ending_at_root = dfs(root, result);
        return result;
    }

private:
    // Returns the maximum sum ending at 'root' without split
    int dfs(TreeNode* root, int& result) {
        // Base case: Leaf node
        if (root == nullptr) return 0;

        // Recursive case: Non-null node.
        // We need to update the path ending here.
        // The max-sum-path ending at ROOT is:
        int max_sum_ending_at_left = std::max(dfs(root->left, result), 0);
        int max_sum_ending_at_right = std::max(dfs(root->right, result), 0);

        // The max path ending at 'root' is. Update result if greater
        int max_sum_thru = max_sum_ending_at_left + root->val + max_sum_ending_at_right;
        result = std::max(max_sum_thru, result);

        // Compute the max_sum_ending at the root (possibly empty)
        int max_sum_ending_at_root = std::max(max_sum_ending_at_left, max_sum_ending_at_right) + root->val;
        return max_sum_ending_at_root;
    }
};
