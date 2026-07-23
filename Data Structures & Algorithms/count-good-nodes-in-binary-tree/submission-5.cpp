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
    // Challenge: use BFS (breadth first search)
    int goodNodes(TreeNode* root) {
        // Handle empty tree
        if (root == nullptr) return 0;

        // The queue holds pairs:
        // -pointer to the node
        // -max value seen so far on the path
        std::queue<std::pair<TreeNode*, int>> q;
        int num_good_nodes = 0;

        q.push({root, std::numeric_limits<int>::min()});

        while (!q.empty()) {
            // pop (node, maxVal) pair
            auto [node, maxVal] = q.front();
            q.pop();

            // If this node is "good" add it to the count
            if (node->val >= maxVal)
                num_good_nodes++;

            // Add its non-null children to the queue,
            // with an max value on the path, that includes this node
            maxVal = std::max(node->val, maxVal);
            if (node->left != nullptr) {
                q.push({node->left, maxVal});
            }
            if (node->right != nullptr) {
                q.push({node->right, maxVal});
            }
        }

        return num_good_nodes;
    }
};
