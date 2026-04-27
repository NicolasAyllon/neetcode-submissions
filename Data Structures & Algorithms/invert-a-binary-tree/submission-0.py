# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # What does it really mean to invert a binary tree?
    # Graphically, when inverted, the resulting binary tree is a reflection of the original
    # So, suppose we have the tree:
    #                 root        reflect            root
    #                /    \         -->             /    \ 
    #             left     right           reflect(right) reflect(left)
    # Notice that to reflect the entire tree:
    # 
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # The reflection of an empty tree is itself
        if not root:
            return None
            
        # Swap left and right children
        root.left, root.right = root.right, root.left

        # Recursively invert the subtrees rooted at the left and right children
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root
        