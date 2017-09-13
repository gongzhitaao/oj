class Solution
{
 public:
  int findMinArrowShots(vector<pair<int, int>>& points)
  {
    if (points.empty()) return 0;

    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first < b.first;
    };
    sort(points.begin(), points.end(), cmp);

    pair<int, int> itv = points[0];
    int cnt = 1;
    for (int i = 1; i < points.size(); ++i) {
      auto& pt = points[i];
      itv.first = pt.first;
      itv.second = min(itv.second, pt.second);
      if (itv.first > itv.second) {
        itv = pt;
        ++cnt;
      }
    }
    return cnt;
  }
};
