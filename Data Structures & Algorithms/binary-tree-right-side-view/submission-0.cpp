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

// The key insight is that the nodes visible from the right, last nodes of each level
// in a level order traversal
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // Perform a level order traversal, adding only the LAST node in each level
        // to the result
        if (root == nullptr) return {};

        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<int> result;
        while (!q.empty()) {
            // Identify the value at the back of the queue since it is furthest right
            // and the one "visible" from the right side of the tree
            int nodes_in_level = q.size();
            TreeNode* visible_node = q.back();
            result.emplace_back(visible_node->val);
            // Process this level, placing the child nodes into the queue
            while (nodes_in_level--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        // Now the queue is empty, and the result has the rightmost node values of each level
        // from top to bottom
        return result;
    }
};
