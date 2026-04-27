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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Empty tree has no nodes
        if (root == nullptr) return {};

        // Require the queue only has non-null nodes
        std::queue<TreeNode*> q;
        q.push(root);

        // The queue initially contains 1 level of nodes.
        // Initially this is the root level.
        std::vector<std::vector<int>> result;
        while (!q.empty()) {
            // Get the number of nodes in this batch and process them
            std::vector<int> level;
            int nodes_in_level = q.size();

            for (int i = 0; i < nodes_in_level; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.emplace_back(node->val);
                // Push non-null children into the queue to make the next level
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            // Now that the level contains the list of node values
            // put it in the result
            result.emplace_back(level);
        }
        // Now the queue is empty, and all levels have been added to the result
        return result;
    }
};
