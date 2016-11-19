class Solution
{
 public:
  vector<vector<string> > groupStrings(vector<string>& strings)
  {
    int n = 'z' - 'a' + 1;
    unordered_multimap<int, vector<string> > tmp;
    for (string w : strings) {
      auto rng = tmp.equal_range(w.size());
      if (rng.first == tmp.end())
        tmp.emplace(make_pair(w.size(), vector<string>{w}));
      else {
        auto it = rng.first;
        for (; it != rng.second; ++it) {
          string tpl = *(it->second.begin());
          int diff = (tpl[0] - w[0] + n) % n;
          int i;
          for (i = 1; i < w.size(); ++i)
            if ((tpl[i]-w[i]+n) % n != diff) break;
          if (i == w.size()) break;
        }
        if (it != rng.second)
          it->second.push_back(w);
        else tmp.emplace(make_pair(w.size(), vector<string>{w}));
      }
    }

    vector<vector<string> > ret;
    for (auto p : tmp)
      ret.push_back(p.second);
    return ret;
  }
};
