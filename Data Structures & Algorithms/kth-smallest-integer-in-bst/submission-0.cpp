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
    int kthSmallest(TreeNode* root, int k) {
        // For safety, return -1 if root is null
        if (root == nullptr) return -1;

        // To iterate through the nodes in ascending order,
        // use an inorder traversal.
        // Initially pass i == 0 and target rank (by smallest) k.
        int count = 0;
        TreeNode* kth_node = inorderTraverseGetNode(root, count, k);
        return kth_node->val;
    }

private:
    TreeNode* inorderTraverseGetNode(TreeNode* node, int& count, int k) {
        // Base case: if the root is null, do nothing.
        if (node == nullptr) return nullptr;
        
        // Recursively explore left subtree
        TreeNode* result = inorderTraverseGetNode(node->left, count, k);
        if (result != nullptr)
            return result;

        // Count this node
        count += 1;
        if (count == k) return node;

        // Recursively explore right subtree
        return inorderTraverseGetNode(node->right, count, k);
    }
};
