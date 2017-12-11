class Solution
{
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
  {
    vector<unordered_set<int>> g(numCourses, unordered_set<int>());
    for (auto& edge : prerequisites) {
      if (g[edge.second].find(edge.first) != g[edge.second].end())
        return false;
      g[edge.first].insert(edge.second);
    }

    vector<int> v(numCourses, -1);
    for (int i = 0; i < numCourses; ++i)
      if (!dfs(g, i, v)) return false;
    return true;
  }

  bool dfs(vector<unordered_set<int>>& g, int cur, vector<int>& v)
  {
    if (0 == v[cur]) return true;
    if (1 == v[cur]) return false;

    v[cur] = 1;
    for (int nb : g[cur])
      if (!dfs(g, nb, v)) return false;
    v[cur] = 0;

    return true;
  }
};
