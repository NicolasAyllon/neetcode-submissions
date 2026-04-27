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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Recall:
        // preorder: (root, left_preorder, right_preorder)
        // inorder: (left_inorder, root, right_inorder)
        // maps val -> idx in inorder traversal
        std::unordered_map<int, int> indices;
        for (int i = 0; i < inorder.size(); ++i) {
            indices[inorder[i]] = i;
        }
        return dfs(preorder, 0 /*pre_idx*/, inorder, 0 /*left*/, inorder.size() - 1 /*right*/, indices);
    }

private:
    // Invariant: We are considering the inorder traversal over the subarray [l, r] inclusive
    // The root of the tree is at the first index in preorder starting at [pre_idx...]
    TreeNode* dfs(const vector<int>& preorder, int pre_idx,
                  const vector<int>& inorder, int l, int r, unordered_map<int, int>& indices) {
        // Base case: 
        // We are considering the empty subarray [l, r] where l > r
        if (l > r) return nullptr;

        // Get root value and its index inorder traversal (using the hashmap)
        int root_val = preorder[pre_idx];
        int mid = indices[root_val];
        int n_left = mid - l; // nodes in left subtree

        return new TreeNode(root_val,
                            dfs(preorder, pre_idx + 1, inorder, l, mid - 1, indices),
                            dfs(preorder, pre_idx + 1 + n_left, inorder, mid + 1, r, indices));
    }
};
