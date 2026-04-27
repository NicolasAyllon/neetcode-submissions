# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        if root:
            q.append(root) # Add root to right
        res = []

        # Enqueue all nodes that will be part of the next level
        while q:
            nodes_in_level = len(q)
            level = []
            for _ in range(nodes_in_level):
                # Add node to the list for this level
                # and enqueue its children for the next level
                node = q.popleft()
                level.append(node.val)
                
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            # Now that all nodes in this level have been added to the list 'level'
            # Append the list to the result
            res.append(level)
        
        # Queue is empty
        return res

        