class Solution
{
 public:
  bool validTree(int n, vector<pair<int, int> >& edges)
  {
    vector<unordered_set<int> > g(n, unordered_set<int>());
    for (auto e : edges) {
      g[e.first].insert(e.second);
      g[e.second].insert(e.first);
    }
    vector<bool> v(n, false);
    if (!dfs(g, v, 0, -1)) return false;
    for (bool b : v) if (!b) return false;
    return true;
  }

  bool dfs(vector<unordered_set<int> >& g, vector<bool>& v,
           int cur, int par)
  {
    v[cur] = true;
    for (auto nb : g[cur]) {
      if (nb == par) continue;
      if (v[nb]) return false;
      if (!dfs(g, v, nb, cur)) return false;
    }
    return true;
  }
};
