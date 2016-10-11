/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
  var pos = {};
  for (var i = 0; i < inorder.length; ++i)
    pos[inorder[i]] = i;

  function build(p, q, len) {
    if (0 === len) return null;
    if (1 === len) return new TreeNode(inorder[p]);

    var val = postorder[q + len - 1];
    var k = pos[val];

    var d = k - p;
    var par = new TreeNode(val);
    par.left = build(p, q, d);
    par.right = build(p + d + 1, q + d, len - d - 1);

    return par;
  }

  return build(0, 0, inorder.length);
};
