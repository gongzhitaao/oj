/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  if (0 === strs.length) return "";

  var ret = "";
  for (var i = 0; ; ++i) {
    if (strs[0].length === i) break;

    var c = strs[0][i];
    for (var j = 1; j < strs.length; ++j) {
      if (strs[j].length === i || strs[j][i] != c) {
        i = -1;
        break;
      }
    }

    if (i >= 0) ret += c;
    else break;
  }

  return ret;
};
