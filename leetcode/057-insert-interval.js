/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @param {Interval} newInterval
 * @return {Interval[]}
 */
var insert = function(intervals, newInterval) {
  var ret = [];
  var newitv = newInterval;
  var inserted = false;
  for (var i = 0; i < intervals.length; ++i) {
    var itv = intervals[i];
    if (inserted) {
      ret.push(itv);
    } else {
      if (newitv.end < itv.start) {
        inserted = true;
        ret.push(newitv);
        ret.push(itv);
      } else if (newitv.start > itv.end) {
        ret.push(itv);
      } else {
        newitv.start = Math.min(newitv.start, itv.start);
        newitv.end = Math.max(newitv.end, itv.end);
      }
    }
  }

  if (!inserted)
    ret.push(newitv);

  return ret;
};
