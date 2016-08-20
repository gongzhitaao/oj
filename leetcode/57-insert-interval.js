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
  if (0 == intervals.length)
    return [newInterval];

  var merging = -1;
  var start = null;
  var ret = [];
  for (var i = 0; i < intervals.length; ++i) {
    var itv = intervals[i];
    switch (merging) {
    case -1:
      if (newInterval.end < itv.start) {
        merging = 1;
        ret.push(newInterval);
        ret.push(itv);
      } else if (newInterval.end <= itv.end) {
        merging = 1;
        start = Math.min(newInterval.start, itv.start);
        ret.push(new Interval(start, itv.end));
      } else if (newInterval.start <= itv.end) {
        merging = 0;
        start = Math.min(newInterval.start, itv.start);
      } else {
        ret.push(itv);
      }
      break;
    case 0:
      if (newInterval.end < itv.start) {
        merging = 1;
        ret.push(new Interval(start, newInterval.end));
        ret.push(itv);
      } else if (newInterval.end <= itv.end) {
        merging = 1;
        ret.push(new Interval(start, itv.end));
      }
      break;
    case 1:
      ret.push(itv);
      break;
    default: /* empty */
      break;
    }
  }

  if (-1 == merging)
    ret.push(newInterval);
  else if (0 == merging)
    ret.push(new Interval(start, newInterval.end));

  return ret;
};
