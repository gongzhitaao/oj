class Solution
{
 public:
  vector<int>
  findMinHeightTrees(int n, vector<pair<int, int> >& edges)
  {
    if (edges.empty()) return {0};

    unordered_map<int, unordered_set<int> > g;
    for (auto e : edges) {
      g[e.first].insert(e.second);
      g[e.second].insert(e.first);
    }

    while (g.size() > 2) {
      vector<pair<int, int> > kill;
      for (auto it = g.begin(); it != g.end(); )
        if (it->second.size() == 1) {
          kill.push_back({*(it->second.begin()), it->first});
          it = g.erase(it);
        } else ++it;
      for (auto x : kill)
        g[x.first].erase(x.second);
    }

    vector<int> ret;
    for (auto e : g)
      ret.push_back(e.first);
    return ret;
  }
};
