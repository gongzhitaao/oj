/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
  var ret = [];
  for (var stk = [[root, 0]]; stk.length > 0; ) {
    var ele = stk.pop();
    var node = ele[0];
    var level = ele[1];

    if (node === null) continue;
    if (level >= ret.length) ret.push(node.val);
    stk.push([node.left, level + 1]);
    stk.push([node.right, level + 1]);
  }
  return ret;
};
