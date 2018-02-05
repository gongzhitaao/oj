class Solution
{
  typedef pair<int, int> id_t;

 public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions)
  {
    vector<int> ret;
    if (positions.empty()) return ret;
    vector<vector<id_t>> par(m, vector<id_t>(n, {-1, -1}));
    vector<vector<int>> rnk(m, vector<int>(n, 0));
    int cnt = 0;
    vector<int> d{-1, 0, 1, 0, -1};
    for (id_t p : positions) {
      par[p.first][p.second] = p;
      ++cnt;
      for (int i = 0; i < 4; ++i) {
        id_t nb = {p.first + d[i], p.second + d[i + 1]};
        if (nb.first < 0 || nb.second < 0 || nb.first >= m || nb.second >= n ||
            par[nb.first][nb.second].first < 0)
          continue;
        cnt -= Union(p, nb, par, rnk);
      }
      ret.push_back(cnt);
    }
    return ret;
  }

  id_t Find(id_t& p, vector<vector<id_t>>& par)
  {
    if (par[p.first][p.second] != p)
      par[p.first][p.second] = Find(par[p.first][p.second], par);
    return par[p.first][p.second];
  }

  int Union(id_t& a, id_t& b, vector<vector<id_t>>& par,
            vector<vector<int>>& rnk)
  {
    id_t pa = Find(a, par);
    id_t pb = Find(b, par);
    // They belong to the same island, so the total count does not decrease.
    if (pa == pb) return 0;
    if (rnk[pa.first][pa.second] < rnk[pb.first][pb.second])
      par[pa.first][pa.second] = pb;
    else {
      par[pb.first][pb.second] = pa;
      if (rnk[pa.first][pa.second] == rnk[pb.first][pb.second])
        ++rnk[pa.first][pa.second];
    }
    // Now we merge two islands, so the total count should decrease by 1.
    return 1;
  }
};
