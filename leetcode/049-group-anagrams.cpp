class Solution
{
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs)
  {
    unordered_map<string, vector<string>> kv;
    for (string& s : strs) {
      string t = s;
      sort(t.begin(), t.end());
      kv[t].push_back(s);
    }

    vector<vector<string>> ret;
    for (auto& elm : kv)
      ret.push_back(elm.second);

    return ret;
  }
};
