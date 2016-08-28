# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.ret = []

    def dfs(self, node, path, remain):
        if node is None: return
        remain -= node.val
        path.append(node.val)
        if node.left is None and node.right is None and 0 == remain:
            self.ret += [path[:]]
        else:
            self.dfs(node.left, path, remain)
            self.dfs(node.right, path, remain)
        path.pop()

    def pathSum(self, root, sum_):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        self.dfs(root, [], sum_)
        return self.ret
