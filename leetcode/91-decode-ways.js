/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
  if (!s.length) return 0;

  var a = 1, b = +(s[0] !== '0');
  for (var i = 1; i < s.length; ++i) {
    var n0 = parseInt(s[i]);
    var n1 = parseInt(s.slice(i - 1, i + 1));

    var c = 0;
    if (0 < n0) c += b;
    if (9 < n1 && n1 < 27) c += a;

    a = b, b = c;
  }

  return b;
};
