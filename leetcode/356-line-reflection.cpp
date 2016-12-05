class Solution
{
 public:
  bool isReflected(vector<pair<int, int> >& points)
  {
    int n = points.size();
    if (n < 2) return true;

    unordered_map<int, unordered_set<int> > pts;

    int xmin, xmax;
    if (n & 1) {
      xmax = xmin = points[0].first;
      pts[points[0].first].insert(points[0].second);
    }
    else {
      xmin = min(points[0].first, points[1].first);
      xmax = max(points[0].first, points[1].first);
      pts[points[0].first].insert(points[0].second);
      pts[points[1].first].insert(points[1].second);
    }

    for (int i = 3-(n&1); i < n; i += 2) {
      auto p0 = points[i-1], p1 = points[i];
      pts[p0.first].insert(p0.second);
      pts[p1.first].insert(p1.second);
      if (p0.first < p1.first) {
        if (p0.first < xmin) xmin = p0.first;
        if (p1.first > xmax) xmax = p1.first;
      } else {
        if (p1.first < xmin) xmin = p1.first;
        if (p0.first > xmax) xmax = p0.first;
      }
    }

    int xsum = xmax + xmin;
    for (auto p : points)
      if (pts.find(xsum-p.first) == pts.end() ||
          pts[xsum-p.first].find(p.second) == pts[xsum-p.first].end())
        return false;
    return true;
  }
};
