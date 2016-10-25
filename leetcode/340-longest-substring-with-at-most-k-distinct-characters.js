/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var lengthOfLongestSubstringKDistinct = function(s, k) {
  if (k <= 0) return 0;

  var n = s.length;
  if (k >= n) return n;

  var maxlen = 0;
  var len = {}, c;
  for (var i = 0, j = 0; j < n; ++j) {
    c = s[j];
    if (!(c in len)) len[c] = 0;
    ++len[c];
    while (Object.keys(len).length > k) {
      c = s[i++];
      if (0 === --len[c])
        delete len[c];
    }
    if (j - i + 1 > maxlen)
      maxlen = j - i + 1;
  }
  return maxlen;
};
