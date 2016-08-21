# Definition for binary tree with next pointer.
# class TreeLinkNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution(object):
    def connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """
        i = root
        while i:
            if i.left is None:
                break
            j = i
            while j:
                j.left.next = j.right
                if j.next is not None:
                    j.right.next = j.next.left
                j = j.next
            i = i.left
