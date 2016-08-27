class Solution {
 public:
  int calculateMinimumHP(vector<vector<int> >& dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();
    vector<int> hp(m + 1, numeric_limits<int>::max());
    hp[m - 1] = 1;
    for (int i = n - 1; i >= 0; --i)
      for (int j = m - 1; j >= 0; --j)
        hp[j] = max(min(hp[j + 1], hp[j]) - dungeon[i][j], 1);
    return hp[0];
  }
};
