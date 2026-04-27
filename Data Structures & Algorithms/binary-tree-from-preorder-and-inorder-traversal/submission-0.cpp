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
        // Build a hashmap from val -> idx in the inorder traversal array
        std::unordered_map<int, int> indices;
        for (int i = 0; i < inorder.size(); ++i) {
            indices[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder, 0, preorder.size() - 1, indices);
    }

private:
    // We wish to process the subarray of inorder[l, r] inclusive.
    // Args:
    //   int pre_idx: first index of the preorder traversal (where the root is)
    //   int l: the left index of the inorder traversal (included)
    //   int r: the right index in the inorder traversal (included)
    TreeNode* dfs(vector<int>& preorder, int pre_idx, vector<int>& inorder, int l, int r,  
                  std::unordered_map<int, int>& indices) {
        // Base Case: Inorder traversal subarray is empty
        if (l > r) return nullptr;
        // The root of this subtree for this preorder traversal is the first item.
        int root_val = preorder[pre_idx];
        int mid = indices[root_val];
        int n_left = mid - l; // Nodes in interval [l, mid-1] = (mid-1) - l + 1
        // preorder: (root (index pre_idx), left_preorder, right_preorder)
        //      left_preorder traversal starts at index pre_idx + 1.
        //      right_preorder traversal starts at index pre_idx + 1 + (mid - l)
        //      mid - 1 - l - 1 nodes in left
        //      r - mid nodes in right.
        // inorder: (left_inorder, root, right_inorder)
        TreeNode* root = new TreeNode(root_val);
        root->left = dfs(preorder, pre_idx + 1, inorder, l, mid - 1, indices);
        root->right = dfs(preorder, pre_idx + 1 + n_left, inorder, mid + 1, r, indices);
        return root;
    }

};
