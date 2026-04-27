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
        // Base case:
        // If the root is null, then there are no good nodes (because no nodes at all)
        if (root == nullptr)
            return 0;
        
        // Recursive case
        return goodNodes(root, root->val);
    }

    int goodNodes(TreeNode* root, int current_max) {
        // Base Case
        if (root == nullptr)
            return 0;

        // Recursive Case
        // If this node is greater than or equal to the max on this path, it's a good node.
        // Contributes 1 to the total count.
        bool good = root->val >= current_max;
        int path_max = std::max(current_max, root->val);
        return (good ? 1 : 0) + goodNodes(root->left, path_max) + goodNodes(root->right, path_max);
    }
};
