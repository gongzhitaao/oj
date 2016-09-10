# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if head is None:
            return

        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        tail = None
        cur = slow.next
        while cur:
            nex = cur.next
            cur.next = tail
            tail, cur = cur, nex

        slow.next = None
        i, j = head, tail
        while i and j:
            a, b = i.next, j.next
            i.next, j.next = j, a
            i, j = a, b
