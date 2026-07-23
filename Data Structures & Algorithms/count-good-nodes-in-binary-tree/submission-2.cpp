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
        // Track the maximum value that we've seen on our current path in the DFS
        // Initialize it to the smallest representable value of int
        int max_val_on_path = std::numeric_limits<int>::min();
        int num_good_nodes = dfs(root, max_val_on_path);
        return num_good_nodes;
    }

    int dfs(TreeNode* root, int max_val_on_path) {
        // Base case:
        // If there are no nodes at all (empty tree) there are 0 good nodes
        if (root == nullptr) {
            return 0;
        }
        // Recurisve case:
        // This node (root) is not null, so...
        // If the path contains no nodes with a value greater than this node, this is a good node!
        // Count it as 1 for the return value, plus the number of good nodes in the left & right
        // subtrees Also update the max on the path as the parameter
        if (root->val >= max_val_on_path) {
            return 1 + dfs(root->left, std::max(root->val, max_val_on_path)) +
                   dfs(root->right, std::max(root->val, max_val_on_path));
        }
        // Similarly, if this node's value is less (<) than the path max, it's not a good node.
        // It adds 0 to the returned good nodes, plus the good nodes in the left and right subtrees
    
        else {
            return 0 + dfs(root->left, std::max(root->val, max_val_on_path)) +
                   dfs(root->right, std::max(root->val, max_val_on_path));
        }
    }
};
