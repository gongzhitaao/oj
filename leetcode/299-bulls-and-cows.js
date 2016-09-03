/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
  var bull = 0, cow = 0;
  var cnt = {}, i;
  for (i = 0; i < 10; ++i) cnt[''+i] = 0;
  for (i = 0; i < secret.length; ++i) {
    var c0 = secret[i], c1 = guess[i];
    if (c0 == c1) ++bull;
    else {
      if (cnt[c0] < 0) ++cow;
      if (cnt[c1] > 0) ++cow;
      ++cnt[c0], --cnt[c1];
    }
  }
  return bull + 'A' + cow + 'B';
};
