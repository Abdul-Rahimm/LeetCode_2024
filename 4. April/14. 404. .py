# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def noChild(self, root):
        return root.left == None and root.right == None
    
    def leftsum(self, root, myList):
        if(root == None):
            return
        if(root.left != None and self.noChild(root.left)):
            myList.append(root.left.val)
            
        self.leftsum( root.left, myList)
        self.leftsum( root.right, myList)
        
            
    
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        value = 0
        myList = []
        self.leftsum(root, myList)
        
        for i in myList:
            value = value + i
        
        return value
        