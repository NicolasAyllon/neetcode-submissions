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
    // Challenge: use breadth first search (BFS) instead of depth first search
    // Recall every value in the left subtree is less than the root
    // and every value in the right subtree is greater than the root
    // (This is true for every node in the tree)
    bool isValidBST(TreeNode* root) {
        // Now we use BFS to iterate through nodes of the tree starting at the top
        // and going down level by level.
        // This queue will hold (node, min_allowed_value, max_allowed_value) tuples
        std::queue<std::tuple<TreeNode*, int, int>> q;

        // Put the first node in the queue
        q.push({root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()});

        // While the queue is not empty, we'll check each node to see
        // if it's in the allowable range of values
        while (!q.empty()) {
            auto [node, min, max] = q.front();
            q.pop();

            // Null nodes cannot invalidate a binary tree, so just continue
            if (node == nullptr) continue;

            // Check to see if this node is within the allowable range
            // If it is, enqueue its children
            if (node->val > min && node->val < max) {
                q.push({node->left, min, node->val});
                q.push({node->right, node->val, max});
            }
            // Detected an invalid node in the tree
            else {
                return false;
            }
        }
        // We checked every node in the tree and never found an invalid node
        // So, the whole tree is valid
        return true;
    }
};
