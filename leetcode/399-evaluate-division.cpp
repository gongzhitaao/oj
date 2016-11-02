class Solution
{
 public:
  vector<double>
  calcEquation(vector<pair<string, string> > equations,
               vector<double>& values,
               vector<pair<string, string> > queries)
  {
    unordered_map<string, unordered_map<string, double> > G;
    unordered_set<string> V;
    int n = values.size();
    for (int i = 0; i < n; ++i) {
      pair<string, string>& eq = equations[i];
      double val = values[i];
      G[eq.first][eq.first] = 1.0;
      G[eq.second][eq.second] = 1.0;
      G[eq.first][eq.second] = val;
      G[eq.second][eq.first] = 1 / val;
      V.insert(eq.first);
      V.insert(eq.second);
    }

    for (string k : V)
      for (auto i : G[k])
        for (auto j : G[k])
          G[i.first][j.first] = j.second / i.second;

    vector<double> ret;
    for (auto& qry : queries) {
      double val = -1;
      if (V.find(qry.first) != V.end() &&
          V.find(qry.second) != V.end() &&
          G[qry.first].find(qry.second) != G[qry.first].end())
        val = G[qry.first][qry.second];
      ret.push_back(val);
    }

    return ret;
  }
};
