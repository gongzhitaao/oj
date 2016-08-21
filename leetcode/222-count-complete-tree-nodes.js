/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var countNodes = function(root) {
  var _height = function(node) {
    var h = 0;
    for (var n = node; n !== null; n = n.left) ++h;
    return h;
  };

  var cnt = 0;
  for (var n = root; n !== null; /* empty */) {
    var lh = _height(n.left);
    var rh = _height(n.right);
    if (lh > rh) {
      cnt += 1 << rh;
      n = n.left;
    } else {
      cnt += 1 << lh;
      n = n.right;
    }
  }
  return cnt;
};
