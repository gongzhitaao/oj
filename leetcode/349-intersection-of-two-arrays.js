/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  var picked = {};
  var i, n;
  var ret = [];

  for (i = 0; i < nums1.length; ++i)
    picked[nums1[i]] = false;

  for (i = 0; i < nums2.length; ++i) {
    n = nums2[i];
    if (n in picked && !picked[n]) {
      picked[n] = true;
      ret.push(n);
    }
  }

  return ret;
};
