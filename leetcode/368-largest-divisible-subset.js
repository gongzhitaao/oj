/**
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
  var n = nums.length;

  if (0 === n) return [];

  nums.sort((a, b) => a - b);

  var i, j;

  var v = [];
  for (i = 0; i < n; ++i)
    v.push([nums[i]]);

  var maxcnt = 1, maxpos = 0;
  for (i = 1; i < n; ++i) {
    var cnt = 0, pos = -1;
    for (j = 0; j < i; ++j) {
      if (0 === nums[i] % nums[j] && v[j].length > cnt)
        cnt = v[j].length, pos = j;
    }
    if (pos >= 0) {
      v[i] = v[i].concat(v[pos]);
      if (v[i].length > maxcnt)
        maxcnt = v[i].length, maxpos = i;
    }
  }

  return v[maxpos];
};
