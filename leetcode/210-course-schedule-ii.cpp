class Solution
{
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
  {
    vector<unordered_set<int>> g(numCourses, unordered_set<int>());
    for (auto& p : prerequisites) {
      g[p.first].insert(p.second);
      if (g[p.second].find(p.first) != g[p.second].end())
        return {};
    }

    vector<int> ret, vis(numCourses, 0);
    for (int i = 0; i < numCourses; ++i)
      if (!vis[i] && dfs(g, i, ret, vis))
        return {};
    return ret;
  }

  bool dfs(const vector<unordered_set<int>>& g, int node,
           vector<int>& ret, vector<int>& vis)
  {
    vis[node] = 1;
    for (int nb : g[node]) {
      if (vis[nb] > 0 || (!vis[nb] && dfs(g, nb, ret, vis)))
        return true;
    }
    vis[node] = -1;
    ret.push_back(node);
    return false;
  }
};
