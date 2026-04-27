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
        // Use helper functiom that takes both the root and depth as a parameter
        std::vector<int> result = {};
        dfs(root, 0, &result);
        return result;
    }

private:
    void dfs(TreeNode* root, int depth, std::vector<int>* result) {
        // Base case: for an empty tree just return
        if (root == nullptr) return;

        // Recursive case:
        // If the length of our list is equal to the current depth,
        // then this is the first node we've seen at this depth
        // We can ensure it's the rightmost node by doing an preorder traversal
        // visiting right children first
        if (result->size() == depth) {
            result->emplace_back(root->val);
        }
        // Then recursively visit right children first
        dfs(root->right, depth + 1, result);
        dfs(root->left, depth + 1, result);
    }
};
