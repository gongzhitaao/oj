class Solution
{
 public:
  bool validTree(int n, vector<pair<int, int> >& edges)
  {
    vector<int> p(n, -1);

    if (edges.size() != n-1) return false;
    for (auto e : edges) {
      int x = findpar(p, e.first);
      int y = findpar(p, e.second);
      if (x == y) return false;
      p[x] = y;
    }
    return true;
  }

  int findpar(vector<int>& p, int cur)
  {
    if (p[cur] < 0) return cur;
    return p[cur] = findpar(p, p[cur]);
  }
};
