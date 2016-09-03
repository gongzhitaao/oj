/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
  var jumps = 0;
  var a = 0, b = 0;
  for (var i = 0; i < nums.length; ++i) {
    b = Math.max(nums[i] + i, b);
    if (a + 1 >= nums.length) break;
    if (i == a) a = b, ++jumps;
  }
  return jumps;
};
