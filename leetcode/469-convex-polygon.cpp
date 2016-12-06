class Solution
{
 public:
  bool isConvex(vector<vector<int> >& points)
  {
    points.push_back(points[0]);
    points.push_back(points[1]);
    long long pre = 0, cur;
    for (int i = 2; i < points.size(); ++i) {
      if (cur = ccw(points[i-2], points[i-1], points[i])) {
        if (pre) {
          if (pre * cur < 0) return false;
        } else pre = cur;
      }
    }
    return true;
  }

  inline int ccw(vector<int>& p1, vector<int>& p2, vector<int>& p3)
  {
    return (p2[0]-p1[0])*(p3[1]-p1[1]) - (p3[0]-p1[0])*(p2[1]-p1[1]);
  }
};
