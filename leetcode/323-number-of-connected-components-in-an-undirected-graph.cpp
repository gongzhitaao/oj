class Solution
{
 public:
  int countComponents(int n, vector<pair<int, int> >& edges)
  {
    vector<unordered_set<int> > g(n, unordered_set<int>());
    for (auto e : edges) {
      g[e.first].insert(e.second);
      g[e.second].insert(e.first);
    }

    vector<bool> v(n, false);
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i]) continue;
      ++cnt;
      q.push(i);
      while (!q.empty()) {
        int cur = q.front(); q.pop();
        v[cur] = true;
        for (int nb : g[cur])
          if (!v[nb]) q.push(nb);
      }
    }

    return cnt;
  }
};
