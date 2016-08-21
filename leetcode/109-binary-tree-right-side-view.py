# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        if root is None:
            return ret

        q = [root]
        while len(q) > 0:
            ret += [q[-1].val]
            q = [child
                 for node in q
                 for child in [node.left, node.right]
                 if child is not None]
        return ret
