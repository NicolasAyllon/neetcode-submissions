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
        int num_good_nodes = 0;
        int path_max = std::numeric_limits<int>::min();
        dfs(root, path_max, &num_good_nodes);
        return num_good_nodes;
    }

private:
    void dfs(TreeNode* node, int path_max, int* num_good_nodes) {
        // Base Case: for a null node just return
        if (node == nullptr) return;

        std::cout << "node->val = " << node->val << '\n';

        // Recursive Case:
        // This node is good if we never saw a value greater than it.
        if (node->val >= path_max) {
            (*num_good_nodes)++;
            std::cout << "num_good_nodes = " << num_good_nodes << '\n';
        }
        // Now search both subtrees, keeping in mind the max on the path
        // is the maximum of the path_max and the most recent node on the path (this one)
        dfs(node->left, std::max(node->val, path_max), num_good_nodes);
        dfs(node->right, std::max(node->val, path_max), num_good_nodes);
    }
};
