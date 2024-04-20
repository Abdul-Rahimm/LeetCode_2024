# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    result = ""
    def solve(self, root, curr):
        if(root == None):
            return
        
        curr = chr((root.val) + ord('a')) + curr
        
        if(root.left == None and root.right == None):
            if self.result == "" or curr < self.result:
                # update result
                self.result = curr
            
            return
        
        self.solve(root.left, curr)
        self.solve(root.right, curr)
    
    def smallestFromLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: str
        """
        
        self.solve(root, "")
        
        return self.result