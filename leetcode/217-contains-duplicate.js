/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
  var dic = {};
  for (var i = 0; i < nums.length; ++i) {
    if (dic[nums[i]]) return true;
    dic[nums[i]] = true;
  }
  return false;
};
