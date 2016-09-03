/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
  var ret = [];
  nums.sort(function(a, b) { return a - b; });
  var a, b, c;
  for (var i = 0; i < nums.length - 2; ++i) {
    if (i > 0 && a == nums[i]) continue;
    a = nums[i];

    for (var j = i + 1, k = nums.length - 1; j < k; ) {
      var s = nums[i] + nums[j] + nums[k];
      if (0 == s) {
        ret.push([nums[i], nums[j], nums[k]]);
        b = nums[j];
        while (j < k && b == nums[j]) ++j;
        c = nums[k];
        while (j < k && c == nums[k]) --k;
      } else if (s > 0) {
        c = nums[k];
        while (j < k && c == nums[k]) --k;
      } else /* if (s < 0) */ {
        b = nums[j];
        while (j < k && b == nums[j]) ++j;
      }
    }
  }
  return ret;
};
