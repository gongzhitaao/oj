/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
  var ret = [[]];
  for (var i = 0; i < nums.length; ++i)
    for (var j = 0, n = ret.length; j < n; ++j)
      ret.push(ret[j].concat(nums[i]));
  return ret;
};
