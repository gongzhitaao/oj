# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        pos = {v: p for p, v in enumerate(inorder)}

        def build(p, q, n):
            if 0 == n: return None
            if 1 == n: return TreeNode(preorder[p])

            v = preorder[p]
            k = pos[v]
            d = k - q

            par = TreeNode(v)
            par.left = build(p+1, q, d)
            par.right = build(p+d+1, q+d+1, n-d-1)

            return par

        return build(0, 0, len(preorder))
