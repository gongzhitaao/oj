class Solution
{
 public:
  void wallsAndGates(vector<vector<int> >& rooms)
  {
    for (int i = 0; i < rooms.size(); ++i)
      for (int j = 0; j < rooms[0].size(); ++j)
        if (!rooms[i][j]) dfs(rooms, 0, i, j);
  }

  void dfs(vector<vector<int> >& rooms, int d, int r, int c)
  {
    if (r<0 || r>=rooms.size() || c<0 || c>=rooms[0].size() ||
        rooms[r][c]<0 || rooms[r][c]<d) return;
    rooms[r][c] = d;
    static const vector<int> step = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; ++i)
      dfs(rooms, d+1, r+step[i], c+step[i+1]);
  }
};
