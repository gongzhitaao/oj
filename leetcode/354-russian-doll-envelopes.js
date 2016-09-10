/**
 * @param {number[][]} envelopes
 * @return {number}
 */
var maxEnvelopes = function(envelopes) {
  function lower_bound(a, k, comp=function(a, b) { return a < b; }) {
    var l = 0, cnt = a.length;
    while (cnt > 0) {
      var step = cnt >> 1;
      var m = l + step;
      if (comp(a[m], k)) {
        l = m + 1;
        cnt -= step + 1;
      } else cnt = step;
    }
    return l;
  }

  var sorted = envelopes.sort(function(a, b) {
    return a[0] === b[0] ? b[1] - a[1] : a[0] - b[0];
  });

  var lis = [];
  for (var i = 0; i < sorted.length; ++i) {
    var p = lower_bound(lis, sorted[i][1]);
    if (p == lis.length) lis.push(sorted[i][1]);
    else lis[p] = sorted[i][1];
  }
  return lis.length;
};
