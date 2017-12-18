class Solution
{
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList)
  {
    wordList.push_back(beginWord);

    const int n = wordList.size();
    int start = n - 1, end = -1;

    vector<unordered_set<int>> g(n, unordered_set<int>());
    for (int i = 0; i < n; ++i) {
      string& wi = wordList[i];
      if (end < 0 && wi == endWord) end = i;

      for (int j = i + 1; j < n; ++j) {
        string& wj = wordList[j];

        int cnt = 0;
        for (int k = 0; k < wi.size(); ++k)
          if (wi[k] != wj[k]) ++cnt;

        if (1 == cnt) {
          g[i].insert(j);
          g[j].insert(i);
        }
      }
    }

    vector<unordered_set<int>> par(n, unordered_set<int>());
    par[start].insert(start);

    vector<int> v(n, numeric_limits<int>::max());
    queue<int> p, q;

    int d = 0;
    for (p.push(start); p.size();) {
      int cur = p.front();
      p.pop();
      v[cur] = d;

      if (cur == end) break;

      for (int nb : g[cur]) {
        if (d + 1 <= v[nb]) {
          v[nb] = d + 1;
          par[nb].insert(cur);
          q.push(nb);
        }
      }

      if (p.empty()) {
        ++d;
        swap(p, q);
      }
    }

    vector<vector<string>> ret;
    if (!v[end]) return ret;

    dfs(par, end, ret, {}, wordList);
    wordList.pop_back();

    return ret;
  }

  void dfs(vector<unordered_set<int>>& g, int cur, vector<vector<string>>& ret,
           vector<string> path, vector<string>& dict)
  {
    path.push_back(dict[cur]);

    auto pars = g[cur];
    if (pars.find(cur) != pars.end()) {
      reverse(path.begin(), path.end());
      return ret.push_back(path);
    }

    for (int p : pars) dfs(g, p, ret, path, dict);
  }
};
