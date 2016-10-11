/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
  var pos = {};
  for (var i = 0; i < inorder.length; ++i)
    pos[inorder[i]] = i;

  function build(p, q, len) {
    if (0 === len) return null;
    if (1 === len) return new TreeNode(preorder[p]);

    var v = preorder[p];
    var k = pos[v];
    var d = k - q;

    var par = new TreeNode(v);
    par.left = build(p + 1, q, d);
    par.right = build(p + d + 1, q + d + 1, len - d - 1);

    return par;
  }

  return build(0, 0, preorder.length);
};
