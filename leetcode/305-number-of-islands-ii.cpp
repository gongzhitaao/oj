class Solution
{
 public:
  typedef pair<int, int> id;

  vector<int>
  numIslands2(int m, int n, vector<id>& positions)
  {
    vector<int> ret;
    if (!m || !n) return ret;

    vector<vector<int> > G(m, vector<int>(n, 0));
    vector<vector<id> > P(m, vector<id>(n, {-1, -1}));

    const vector<int> step = {-1, 0, 1, 0, -1};
    vector<int> counts;
    int cnt = 0;
    for (id pos : positions) {
      int i = pos.first, j = pos.second;
      G[i][j] = 1;
      P[i][j] = {i, j};
      ++cnt;
      for (int k = 0; k < 4; ++k) {
        int r = i + step[k], c = j + step[k+1];
        if (0 <= r && r < m && 0 <= c && c < n && G[r][c])
          cnt -= myunion(P, G, P[i][j], P[r][c]);
      }
      counts.push_back(cnt);
    }
    return counts;
  }

  int myunion(vector<vector<id> >& P, vector<vector<int> >& G,
              id a, id b)
  {
    id pa = findpar(P, a), pb = findpar(P, b);
    if (pa == pb) return 0;

    if (G[pa.first][pa.second] < G[pb.first][pb.second])
      P[pa.first][pa.second] = pb;
    else if (G[pa.first][pa.second] > G[pb.first][pb.second])
      P[pb.first][pb.second] = pa;
    else {
      P[pb.first][pb.second] = pa;
      ++G[pa.first][pa.second];
    }
    return 1;
  }

  id findpar(vector<vector<id> >& P, id cur)
  {
    if (P[cur.first][cur.second] != cur)
      P[cur.first][cur.second] =
          findpar(P, P[cur.first][cur.second]);
    return P[cur.first][cur.second];
  }
};
