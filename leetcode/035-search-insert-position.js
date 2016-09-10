/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  var l = 0;
  for (var cnt = nums.length; cnt > 0; ) {
    var step = cnt >> 1;
    var m = l + step;
    if (nums[m] < target) {
      l = m + 1;
      cnt -= step + 1;
    } else cnt = step;
  }
  return l;
};
