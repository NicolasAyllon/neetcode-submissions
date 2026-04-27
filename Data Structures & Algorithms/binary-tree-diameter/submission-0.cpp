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

using std::max;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Base Case:
        // A tree with 0 nodes has diameter 0
        if (root == nullptr) return 0;
        
        int maxDiameter = 0;
        dfs(root, &maxDiameter);
        return maxDiameter;
    }

private:
    // Return the HEIGHT of the tree rooted at ROOT
    int dfs(TreeNode* root, int* maxDiameter) {
        // A tree with 0 nodes has diameter 0
        if (root == nullptr) return 0;

        // A non-null TreeNode:
        // A diameter for a path through ROOT has length 1 + heightOfLeftSubtree + heightOfRightSubtree
        int leftHeight = dfs(root->left, maxDiameter);
        int rightHeight = dfs(root->right, maxDiameter);
        int diameterThroughRoot = leftHeight + rightHeight;
        // Update max diameter found so far
        *maxDiameter = std::max(diameterThroughRoot, *maxDiameter);
        // Now return the height of the tree rooted at ROOT,
        // which is 1 more than the max of the left- and right- heights
        return 1 + std::max(leftHeight, rightHeight);
    }
};
