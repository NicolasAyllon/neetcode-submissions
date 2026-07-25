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
    TreeNode* dfs(const vector<int>& preorder, const vector<int>& inorder, int& preIdx, int& inIdx,
                  const int limit) {
        // If we ran out of nodes to process, return nullptr
        if (inIdx >= inorder.size()) return nullptr;
        // If we finished adding nodes in this subtree, there are
        // no more nodes to add, so any calls to create more nodes should return nullptr
        if (inorder[inIdx] == limit) {
            inIdx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = dfs(preorder, inorder, preIdx, inIdx, root->val);
        root->right = dfs(preorder, inorder, preIdx, inIdx, limit);
        return root;
    }

   public:
    // Recall prorder traversal shows (root)(left_preorder)(right_preorder)
    // Recall inorder traversal shows (left_inorder)(root)(right_inorder)
    // We can identify the current root as the as the first value in the preorder traversal
    // Then, in the preorder traversal, the left_preorder starts right after
    // and the right_preorder starts after that
    // Then, in the inorder traversal, the left_inorder is left of the root, and the right_inorder
    // is right of the root
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Handle empty vectors
        if (preorder.empty() || inorder.empty()) return nullptr;
        // The first value in preorder is the node's value
        int preIdx = 0;
        int inIdx = 0;
        int limit = std::numeric_limits<int>::max();
        return dfs(preorder, inorder, preIdx, inIdx, limit);
    }
};
