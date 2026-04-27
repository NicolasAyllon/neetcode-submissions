# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # The diameter of a binary tree is the length of the longest path (number of edges) in the tree
        # The longest path has to go through some node, let's say it's named ROOT, and so the longest path
        # through ROOT will be the HEIGHT of the left subtree PLUS the HEIGHT of the right subtree
        # (since recall that the height is the number of nodes from root to the deepest child,
        # and there is 1 outgoing edge "UP" the tree from each)
        maxDiameter = 0

        # Define a nested function to the depth first search starting at node CURR
        # and we will return the HEIGHT of the tree rooted at CURR
        def dfs(curr):
            if curr is None:
                return 0
            # Recursively calculate the height of the left and right subtrees,
            # noting that the height of this tree is 1 more than the max height of its two children
            leftHeight = dfs(curr.left)
            rightHeight = dfs(curr.right)
            # The diameter of the path through CURR is the sum of these heights, update maxDiameter if bigger
            nonlocal maxDiameter
            maxDiameter = max(maxDiameter, leftHeight + rightHeight)
            # Return the HEIGHT of the tree rooted at CURR, which is 1 more than the taller subtree's height
            return 1 + max(leftHeight, rightHeight)

        dfs(root)
        return maxDiameter