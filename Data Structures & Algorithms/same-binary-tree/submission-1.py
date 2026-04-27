# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Base Cases:
        # Two trees are the same if they are both empty
        if not p and not q:
            return True
        if not p or not q: # Is exactly 1 tree not null? Then the two trees are not the same
            return False
        
        # Recursive Case:
        # Two trees are the same if:
        # - their left subtrees are the same
        # - their right subtrees are the same
        # - the nodes p and q have the same value
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right) and p.val == q.val