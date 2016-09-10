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
        i, start = root, None
        while i:
            j, k = i, None
            while j:
                if k is None:
                    if j.left is not None:
                        start = k = j.left
                        if j.right is not None:
                            k.next = j.right
                            k = k.next
                    elif j.right is not None:
                        start = k = j.right
                else:
                    if j.left is not None:
                        k.next = j.left
                        k = k.next
                    if j.right is not None:
                        k.next = j.right
                        k = k.next
                j = j.next
            i = start
            start = None
