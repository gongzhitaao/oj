class Solution
{
 public:
  vector<string> findItinerary(vector<pair<string, string>> tickets)
  {
    unordered_map<string, vector<string>> g;
    unordered_map<string, vector<bool>> v;
    for (auto& elm : tickets) {
      g[elm.first].push_back(elm.second);
      v[elm.first].push_back(false);
    }
    for (auto& elm : g) sort(elm.second.begin(), elm.second.end());

    vector<string> ret{"JFK"};
    dfs(g, v, ret, tickets.size() + 1, "JFK");
    return ret;
  }

  bool dfs(unordered_map<string, vector<string>>& g,
           unordered_map<string, vector<bool>>& v, vector<string>& ret, int n,
           string cur)
  {
    vector<string>& nb = g[cur];
    vector<bool>& visited = v[cur];
    for (int i = 0; i < nb.size(); ++i) {
      if (visited[i]) continue;
      visited[i] = true;
      ret.push_back(nb[i]);
      if (dfs(g, v, ret, n, nb[i])) return true;
      ret.pop_back();
      visited[i] = false;
    }
    return ret.size() == n;
  }
};
