/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function(s) {
  var enc = {A: 4, C: 5, G: 6, T: 7}, cnt = {};
  var ret = [];
  var k = 0;
  for (var i = 0; i < s.length; ++i) {
    k = ((k << 3) | enc[s[i]]) & 0x3fffffff;
    if (k & 0x20000000) {
      if (k in cnt) {
        if (1 === cnt[k]) ret.push(s.substr(i - 9, 10));
        ++cnt[k];
      } else cnt[k] = 1;
    }
  }
  return ret;
};
