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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // In advance, we don't know whether p or q is deeper in the tree.
        // Without loss of generality assume p <= q
        // Notes:
        // when traversing from the root, then it is the lowest common ancestor
        
        // Require p <= q
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);

        // Base cases:
        if (root == nullptr) return nullptr;
        if (p == q) return p;

        // Recursive case:
        // a < p <= q, then we also have a p <= p <= q OR p <= q <= q, so p or q is a lower common ancestor than a
        if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        } 
        // if p <= q < a, then we also have p <= q <= q OR p <= p <= q so p or q is a lower common ancestor than a
        else if (root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } 
        // if p <= a <= q, then p lies in a's left subtree and q lies in a's right subtree, and this is the first such a
        else {
            return root;
        }
    }
};
