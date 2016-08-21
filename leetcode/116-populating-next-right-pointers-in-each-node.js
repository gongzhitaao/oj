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
  for (var i = root; i !== null; i = i.left) {
    if (i.left === null) break;
    for (var j = i; j; j = j.next) {
      j.left.next = j.right;
      if (j.next !== null)
        j.right.next = j.next.left;
    }
  }
};
