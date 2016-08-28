/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
  var ret = [];

  var dfs = function(node, path, remain) {
    path.push(node.val);
    remain -= node.val;
    if (null === node.left && null === node.right && !remain)
      ret.push(path.slice());
    else {
      if (null !== node.left) dfs(node.left, path, remain);
      if (null !== node.right) dfs(node.right, path, remain);
    }
    path.pop();
  };

  if (root) dfs(root, [], sum);
  return ret;
};
