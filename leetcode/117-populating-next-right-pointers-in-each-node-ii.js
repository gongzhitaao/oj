/**
 * Definition for binary tree with next pointer.
 * function TreeLinkNode(val) {
 *     this.val = val;
 *     this.left = this.right = this.next = null;
 * }
 */

/**
 * @param {TreeLinkNode} root
 * @return {void} Do not return anything, modify tree in-place instead.
 */
var connect = function(root) {
  for (var i = root, start = null; i; i = start, start = null) {
    for (var j = i, k = null; j; j = j.next) {
      if (k) {
        if (j.left) k.next = j.left, k = k.next;
        if (j.right) k.next = j.right, k = k.next;
      } else {
        if (j.left) {
          start = k = j.left;
          if (j.right)
            k.next = j.right, k = k.next;
        } else if (j.right)
          start = k = j.right;
      }
    }
  }
};
