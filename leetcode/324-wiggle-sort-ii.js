/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function(nums) {
  var n = nums.length;
  nums.sort(function(a, b) { return a - b; });
  var m = nums[n >> 1];
  var idx = function(i) { return (1 + 2 * i) % (n | 1); };
  for (var i = 0, j = 0, k = n - 1; j <= k; ) {
    var I = idx(i), J = idx(j), K = idx(k);
    if (nums[J] > m) {
      [nums[I], nums[J]] = [nums[J], nums[I]];
      ++i, ++j;
    } else if (nums[J] < m) {
      [nums[J], nums[K]] = [nums[K], nums[J]];
      --k;
    } else ++j;
  }
};
