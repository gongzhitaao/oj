# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
  def longestConsecutive(self, root):
    """
    :type root: TreeNode
    :rtype: int
    """
    def _dfs(node, maxlen):
      l, r = 1, 1
      if node.left:
        dl = _dfs(node.left, maxlen)
        if node.val+1 == node.left.val:
          l += dl
      if node.right:
        dr = _dfs(node.right, maxlen)
        if node.val+1 == node.right.val:
          r += dr

      if l > r:
        if l > maxlen['val']:
          maxlen['val'] = l
        return l

      if r > maxlen['val']:
        maxlen['val'] = r
      return r

    maxlen = {'val': 0}
    if root:
      _dfs(root, maxlen)
    return maxlen['val']
