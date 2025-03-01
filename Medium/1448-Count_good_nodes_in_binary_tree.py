# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def __init__(self):
        self.good_nodes = 0
        self.max = -10000

    def goodNodes(self, root: TreeNode) -> int:   

        if root == None:
            return 0

        if root.val > self.max:
            self.max = root.val

        temp_max = self.max
        
        self.goodNodes(root.left)

        self.max = temp_max
        self.good_nodes += root.val >= self.max

        self.goodNodes(root.right)

        return self.good_nodes


        
        