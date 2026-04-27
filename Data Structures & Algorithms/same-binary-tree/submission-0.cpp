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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Perform DFS simultaneously through trees p and q
        // Two trees are the same if their subtrees are the same, and the current nodes/roots p and q are the same

        // Base cases: empty trees are the same
        if (p == nullptr && q == nullptr) return true;
        // Exactly 1 tree is not null
        if (p == nullptr || q == nullptr) return false;

        // Recursive case:
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
    }
};
