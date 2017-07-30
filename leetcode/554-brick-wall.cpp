class Solution
{
 public:
  int leastBricks(vector<vector<int>>& wall)
  {
    unordered_map<int, int> cnt;
    for (vector<int>& line : wall) {
      for (int i = 0, sum = 0; i < line.size() - 1; ++i)
        ++cnt[sum += line[i]];
    }

    int ret = 0;
    for (auto& elm : cnt)
      if (elm.second > ret) ret = elm.second;
    return wall.size()-ret;
  }
};
