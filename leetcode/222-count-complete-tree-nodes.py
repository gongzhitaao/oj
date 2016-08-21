# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def _height(node):
            h = 0
            n = node
            while n is not None:
                h += 1
                n = n.left
            return h

        cnt = 0
        node = root
        while node is not None:
            lh = _height(node.left)
            rh = _height(node.right)
            if lh > rh:
                cnt += 1 << rh
                node = node.left
            else:
                cnt += 1 << lh
                node = node.right
        return cnt
