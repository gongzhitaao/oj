class Solution
{
 public:
  void wallsAndGates(vector<vector<int> >& rooms)
  {
    if (rooms.empty() || rooms[0].empty())
      return;

    int nrow = rooms.size(), ncol = rooms[0].size();
    vector<vector<int> > v(nrow, vector<int>(ncol, -1));
    queue<tuple<int, int, int> > q;
    for (int i = 0, k = 0; i < nrow; ++i)
      for (int j = 0; j < ncol; ++j)
        if (!rooms[i][j]) {
          q.push(make_tuple(i, j, 0));
          bfs(rooms, v, k++, q);
        }
  }

  void bfs(vector<vector<int> >& rooms,
           vector<vector<int> >& v, int k,
           queue<tuple<int, int, int> >& q)
  {
    int nrow = rooms.size(), ncol = rooms[0].size();
    static const vector<int> step = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
      tuple<int, int, int> p = q.front(); q.pop();
      for (int i = 0; i < 4; ++i) {
        int rr = get<0>(p) + step[i], cc = get<1>(p) + step[i+1];
        if (0 <= rr && rr < nrow && 0 <= cc && cc < ncol &&
            rooms[rr][cc] > 0 && v[rr][cc] < k) {
          v[rr][cc] = k;
          if (rooms[rr][cc] - 1 > get<2>(p)) {
            rooms[rr][cc] = get<2>(p) + 1;
            q.push(make_tuple(rr, cc, rooms[rr][cc]));
          }
        }
      }
    }
  }
};
