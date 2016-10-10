/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
  for (var l = 1, h = num; l <= h; ) {
    var m = l + ((h - l) >> 1);
    var sqr = m * m;
    if (sqr == num) return true;
    if (sqr < num) l = m + 1;
    else h = m - 1;
  }
  return false;
};
