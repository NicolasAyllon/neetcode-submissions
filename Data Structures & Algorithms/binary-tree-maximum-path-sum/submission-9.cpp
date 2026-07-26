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
    // Returns the maximum path sum ENDING at this node.
    // (We can also call this the DOWNWARD path, starting here and going down)
    int dfs(TreeNode* node, int& globalMaxSum) {
        // Base Case: if this node is null, do nothing
        if (node == nullptr) return 0;

        // Recursive Case: node is not null
        // The return value, the maximum downward path from this node is:
        int leftMax = std::max(dfs(node->left, globalMaxSum), 0); // max sum of 0 or more nodes from the left subtree
        int rightMax = std::max(dfs(node->right, globalMaxSum), 0); // max sum of 0 or more nodes from the right subtree
        
        // The maximum path through this node contains 
        // -this node (always)
        // -the maximum left downward path (if positive)
        // -maximum right downward path (if positive)
        int maxPathSumThruThisNode = node->val + leftMax + rightMax;
        globalMaxSum = std::max(globalMaxSum, maxPathSumThruThisNode);

        // Return the maximum downward path containing this node, it goes through either the left or right subtree
        return node->val + std::max(leftMax, rightMax);
    }
public:
    // Approach:
    // We can use DFS (depth first search) to explore all nodes in the tree
    // Suppose we're considering one node like this:
    //
    //       node
    //      /    \
    //    left   right
    // 
    // There are 3 cases for the maximum sum path
    // NODE is not on the path
    // 1. it lies entirely in the left subtree
    //    sum = max_path_through_node->left
    // 2. it lies entirely in the right subtree
    //    sum = max_path_through_node->right
    // NODE is on the path
    // 3. sum = node->val 
    //        + max_path_ending_at_node->left
    //        + max_path_ending_at_node->right
    int maxPathSum(TreeNode* root) {
        int globalMaxSum = std::numeric_limits<int>::min();
        dfs(root, globalMaxSum);
        return globalMaxSum;
    }
};
