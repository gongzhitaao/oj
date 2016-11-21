class Solution
{
 public:
  vector<string> findItinerary(vector<pair<string, string> > tickets)
  {
    unordered_map<string, map<string, int> > g;
    for (auto tic : tickets)
      ++g[tic.first][tic.second];
    vector<string> ret;
    dfs(g, "JFK", ret, tickets.size());
    return ret;
  }

  bool dfs(unordered_map<string, map<string, int> >& g,
           string from, vector<string>& ret, int n)
  {
    ret.push_back(from);
    if (!n) return true;

    for (auto& to : g[from]) {
      if (!to.second) continue;
      --to.second;
      if (dfs(g, to.first, ret, n-1))
        return true;
      ++to.second;
    }

    ret.pop_back();
    return false;
  }
};
