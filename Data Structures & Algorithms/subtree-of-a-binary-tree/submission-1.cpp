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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // The tree rooted at SUBROOT is a subtree of the one with root ROOT if
        // for some node in ROOT, say NODE, we have isSameTree(NODE, SUBROOT) == true
        // Base Case:
        // If exactly 1 node is null then subRoot can't be a subtree of root
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr || subRoot == nullptr) return false;
        
        // SUBROOT is a subtree of ROOT if they are the same
        if (isSameTree(root, subRoot)) return true;

        // They are not the same, so see if SUBROOT is a subtree 
        // of either ROOT->LEFT or ROOT->RIGHT
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }

    // Helping function: returns whether two trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Cases:
        if (p == q) return true; // Literally the same node
        if (p == nullptr && q == nullptr) return true; // Empty trees are identical
        if (p == nullptr || q == nullptr) return false; // Exactly 1 empty tree: not identical to a nonempty tree

        // Recursive Case:
        // Two trees are identical if: 
        // - their left subtrees are the same, 
        // - right subtrees are the same, 
        // - their roots have the same value
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right) && 
               p->val == q->val;
    }
};
