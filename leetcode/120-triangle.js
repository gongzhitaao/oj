/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  var n = triangle.length;
  if (!n) return [];

  var imax = Number.MAX_SAFE_INTEGER;

  var sum = Array(n).fill(imax);
  sum[0] = 0;
  for (var i = 0; i < n; ++i) {
    var p = imax;
    for (var j = 0; j <= i; ++j) {
      var t = sum[j];
      sum[j] = Math.min(p, sum[j]) + triangle[i][j];
      p = t;
    }
  }
  return Math.min(...sum);
};
