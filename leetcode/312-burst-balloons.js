/**
 * @param {number[]} nums
 * @return {number}
 */
var maxCoins = function(nums) {
  var n = nums.length;
  if (0 === n) return 0;
  if (1 === n) return nums[0];

  var i, j, k;

  var v = [];
  for (i = 0; i < n+1; ++i)
    v.push(Array(n+2).fill(0));

  var A = [1].concat(nums, [1]);
  for (i = n-1; i >= 0; --i) {
    for (j = i+2; j <= n+1; ++j) {
      var max = Number.MIN_SAFE_INTEGER;
      for (k = i+1; k <= j-1; ++k) {
        var cur = v[i][k] + v[k][j] + A[i]*A[k]*A[j];
        if (cur > max) max = cur;
      }
      v[i][j] = max;
    }
  }

  return v[0][n+1];
};
