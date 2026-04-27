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
        // Base case: empty arrays
        if (preorder.empty() || inorder.empty()) return nullptr;
        // Get root of subtree as the first item in preorder traversal
        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);

        auto it = std::find(inorder.begin(), inorder.end(), root_val);
        size_t n_left = it - inorder.begin();

        // Create vectors for the inorder and preorder traversals of the subtrees
        vector<int> left_inorder(inorder.begin(), it);
        vector<int> right_inorder(it + 1, inorder.end());
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + n_left);
        vector<int> right_preorder(preorder.begin() + 1 + n_left, preorder.end());
        // Construct left subtree recursively
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};
