# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]

        :rtype: TreeNode
        """
        pos = {v: i for i, v in enumerate(inorder)}

        def build(p, q, n):
            if 0 == n: return None
            if 1 == n: return TreeNode(inorder[p])

            val = postorder[q+n-1]
            k = pos[val]

            d = k - p
            par = TreeNode(val)
            par.left = build(p, q, d)
            par.right = build(p+d+1, q+d, n-d-1)

            return par

        return build(0, 0, len(inorder))
