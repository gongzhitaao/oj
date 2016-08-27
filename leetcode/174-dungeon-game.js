/**
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function(dungeon) {
  var n = dungeon.length;
  var m = dungeon[0].length;
  var hp = Array.from({ length: m + 1 },
                      () => Number.MAX_SAFE_INTEGER);
  hp[m - 1] = 1;
  for (var i = n - 1; i >= 0; --i)
    for (var j = m - 1; j >= 0; --j)
      hp[j] = Math.max(Math.min(hp[j + 1], hp[j]) - dungeon[i][j], 1);
  return hp[0]
};
