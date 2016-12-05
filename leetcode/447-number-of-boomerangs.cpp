class Solution
{
 public:
  int numberOfBoomerangs(vector<pair<int, int> >& points)
  {
    int n = points.size();
    if (!n) return 0;

    int ret = 0;
    for (int i = 0; i < n; ++i) {
      unordered_map<int, int> cnt;
      for (int j = 0; j < n; ++j) {
        ret += 2 * cnt[(points[i].first-points[j].first) *
                       (points[i].first-points[j].first) +
                       (points[i].second-points[j].second) *
                       (points[i].second-points[j].second)]++;
      }
    }
    return ret;
  }
};
