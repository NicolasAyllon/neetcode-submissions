# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # Recall the properties of a BST (Binary Search Tree):
        # For any node NODE in the tree:
        # - all nodes in the left subtree are LESS THAN or equal to NODE's value
        # - all nodes in the right subtree are GREATER THAN or equal to NODE's value

        # Without loss of generality, we require p.val <= q.val
        if p.val > q.val:
            return self.lowestCommonAncestor(root, q, p)

        # Base cases: if any node is None, return None
        if not root or not p or not q:
            return None

        # Recursive case:
        # if root.val < p.val <= q.val then we also know p.val <= p.val <= q.val and p.val <= q.val <= q.val.
        # and since p and q are in root's right subtree, either p or q is a lower common ancestor than root
        # so make a recursive call with root's right child.
        if root.val < p.val:
            return self.lowestCommonAncestor(root.right, p, q)

        # if p.val <= q.val < root.val then also p.val <= q.val <= q.val or p.val <= p.val <= q.val
        # and since p anad q are in root's left subtree, either p or q is a lower common ancestor than root.
        # so make a recursive call with root's left child.
        elif root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
            
        # p.val <= root.val <= q.val and this is the first such ancestor 'root'
        # Since we traversed down in DFS and this is the first such ancestor, it is the lowest common ancestor
        else: 
            return root
        

        