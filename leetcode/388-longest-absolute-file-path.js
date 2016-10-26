/**
 * @param {string} input
 * @return {number}
 */
var lengthLongestPath = function(input) {
  var maxlen = 0;
  var text = input + '\n';
  var stk = [0];
  for (var i = 0, cnt = 0, curlev = 0, isfile = 0;
       i < text.length; ++i) {
    switch (text[i]) {
    case '\n':
      while (stk.length > curlev + 1)
        stk.pop();
      stk.push(cnt + stk[stk.length-1]);
      if (isfile) {
        isfile = 0;
        if (curlev + stk[stk.length-1] > maxlen)
          maxlen = curlev + stk[stk.length-1];
      }
      curlev = 0;
      cnt = 0;
      break;
    case '\t':
      ++curlev;
      break;
    case '.':
      isfile = 1;
    default:
      ++cnt;
      break;
    }
  }
  return maxlen;
};
