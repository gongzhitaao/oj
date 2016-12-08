class Solution
{
 public:
  int countComponents(int n, vector<pair<int, int> >& edges)
  {
    vector<int> p(n, -1), r(n, 0);
    for (auto e : edges) {
      int x = findpar(p, e.first);
      int y = findpar(p, e.second);
      if (x == y) continue;
      if (r[x] < r[y]) p[x] = y;
      else if (r[x] > r[y]) p[y] = x;
      else p[x] = y, ++r[y];
    }

    unordered_set<int> ret;
    for (int i = 0; i < n; ++i) {
      int t = findpar(p, i);
      if (ret.find(t) == ret.end())
        ret.insert(t);
    }
    return ret.size();
  }

  int findpar(vector<int>& p, int cur)
  {
    if (p[cur] < 0) return cur;
    return p[cur] = findpar(p, p[cur]);
  }
};
