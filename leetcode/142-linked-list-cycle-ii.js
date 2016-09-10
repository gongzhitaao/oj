/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function(head) {
  if (null === head) return null;
  var slow, fast;
  for (slow = head, fast = head; ; ) {
    if (null === fast.next ||
        null === fast.next.next)
      return null;
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast) break;
  }
  for (slow = head; slow !== fast;
       slow = slow.next, fast = fast.next) ;
  return slow;
};
