# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def addlevel(self, root, curr, val, depth):
        if not root:
            return None
        
        if curr == depth - 1:
            templeft = root.left
            tempright = root.right
            
            root.left = TreeNode(val)
            root.right = TreeNode(val)
            
            root.left.left = templeft
            root.right.right = tempright
            
            return root
        
        root.left = self.addlevel(root.left, curr+1, val, depth)
        root.right = self.addlevel(root.right, curr+1, val, depth)
        
        return root
        
    
    def addOneRow(self, root, val, depth):
        """
        :type root: TreeNode
        :type val: int
        :type depth: int
        :rtype: TreeNode
        """
        if(depth == 1):
            newRoot = TreeNode(val)
            newRoot.left = root
            
            return newRoot
        
        curr = 1
        return self.addlevel(root, curr, val, depth)
        