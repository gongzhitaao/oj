/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
  var n = t.length, m = s.length;
  var d = new Array(n+1).fill(0).map(row => new Array(m+1).fill(0));
  var i, j;
  for (j = 0; j <= m; ++j) d[0][j] = 1;
  for (i = 1; i <= n; ++i) {
    for (j = i; j <= m; ++j) {
      d[i][j] = d[i][j - 1];
      if (t[i - 1] == s[j - 1])
        d[i][j] += d[i - 1][j - 1];
    }
  }
  return d[n][m];
};
