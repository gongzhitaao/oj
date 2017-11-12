class Solution
{
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
  {
    unordered_map<string, string> name;
    unordered_map<string, string> par;

    for (vector<string>& acc : accounts) {
      for (int i = 1; i < acc.size(); ++i) {
        par[acc[i]] = acc[i];
        name[acc[i]] = acc[0];
      }
    }

    for (vector<string>& acc : accounts) {
      string p = find(par, acc[1]);
      for (int i = 2; i < acc.size(); ++i)
        par[find(par, acc[i])] = p;
    }

    unordered_map<string, set<string>> tmp;
    for (vector<string>& acc : accounts)
      for (int i = 1; i < acc.size(); ++i)
        tmp[find(par, acc[i])].insert(acc[i]);

    vector<vector<string>> ret;
    for (auto& elm : tmp) {
      ret.push_back({name[elm.first]});
      copy(elm.second.begin(), elm.second.end(), back_inserter(ret.back()));
    }

    return ret;
  }

  string find(unordered_map<string, string>& par, string& cur)
  {
    if (cur != par[cur]) par[cur] = find(par, par[cur]);
    return par[cur];
  }
};
