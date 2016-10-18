/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
  function dfs(cands, i0, target, path, ret) {
    if (0 > target)
      return;
    if (0 === target) {
      ret.push(path);
      return;
    }
    for (var i = i0; i < cands.length; ++i)
      dfs(cands, i, target-cands[i], path.concat(cands[i]), ret);
  }

  var ret = [];
  dfs(candidates, 0, target, [], ret);
  return ret;
};
