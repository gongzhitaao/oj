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
        def _dfs(node, level, q):
            if node is None: return

            if level >= len(q):
                q += [node.val]

            _dfs(node.right, level+1, q)
            _dfs(node.left, level+1, q)

        ret = []
        _dfs(root, 0, ret)
        return ret
