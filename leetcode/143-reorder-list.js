/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
  if (!head) return;

  var slow, fast;
  for (slow = head, fast = head; fast.next && fast.next.next;
       slow = slow.next, fast = fast.next.next) ;

  var tail = null;
  for (var cur = slow.next; cur; ) {
    var next = cur.next;
    cur.next = tail;
    [tail, cur] = [cur, next];
  }

  slow.next = null;
  for (var i = head, j = tail; i && j; ) {
    var a = i.next, b = j.next;
    [i.next, j.next] = [j, a];
    [i, j] = [a, b];
  }
};
