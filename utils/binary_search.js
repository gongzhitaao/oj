function upper_bound(a, k, comp=function(a, b) { return a < b; }) {
  var l = 0, cnt = a.length;
  while (cnt > 0) {
    var step = cnt >> 1;
    var m = l + step;
    if (!comp(k, a[m])) {
      l = m + 1;
      cnt -= step + 1;
    } else cnt = step;
  }
  return l;
}

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
