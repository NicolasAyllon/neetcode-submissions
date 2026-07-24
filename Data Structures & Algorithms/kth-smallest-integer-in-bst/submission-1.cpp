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
      // Let's use DFS to traverse the BST in INORDER traversal (left subtree, root, right subtree)
      // And we'll increment the count for each node that we visit
      // When the count equals k, we've found the k'th smallest value
      int count = 0;
      TreeNode* result = nullptr;
      dfs(root, k, &count, &result);
      return result->val;   
    }

    void dfs(TreeNode* root, int k, int* const count, TreeNode** result) {
        // Base case: empty node does not contribute to the node count
        if (root == nullptr) return;

        // Recursive case:
        // Inorder traversal will go through the nodes in sorted order:
        // 1. Process all nodes smaller than this one
        dfs(root->left, k, count, result);
        // 2. Process this node
        //    - If we already found the result return
        if (*result != nullptr) return;
        (*count)++; // Warning: we are incrementing the pointer address, it's possible we may write to result instead
        if (*count == k) {
            *result = root;
        }
        // 3. Process the right subtree
        dfs(root->right, k, count, result);
    }
}; 