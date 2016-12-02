class Solution
{
 public:
  vector<int>
  findMinHeightTrees(int n, vector<pair<int, int> >& edges)
  {
    if (edges.empty()) return {0};

    vector<unordered_set<int> > g(n, unordered_set<int>());
    for (auto e : edges) {
      g[e.first].insert(e.second);
      g[e.second].insert(e.first);
    }

    vector<int> leaves;
    for (int i = 0; i < n; ++i)
      if (g[i].size() == 1) leaves.push_back(i);

    while (n > 2) {
      n -= leaves.size();
      vector<int> newleaves;
      for (auto x : leaves) {
        int y = *(g[x].begin());
        g[y].erase(x);
        if (g[y].size() == 1) newleaves.push_back(y);
      }
      leaves = newleaves;
    }

    return leaves;
  }
};
