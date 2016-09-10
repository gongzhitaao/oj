# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None

        slow, fast = head, head
        while True:
           if (fast.next is None or
               fast.next.next is None):
               return None
           slow = slow.next
           fast = fast.next.next
           if slow is fast:
               break
        slow = head
        while slow is not fast:
            slow = slow.next
            fast = fast.next
        return slow
