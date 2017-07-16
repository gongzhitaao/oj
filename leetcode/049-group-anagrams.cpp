class Solution
{
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs)
  {
    unordered_map<int, vector<string> > dict;
    hash<string> fn;
    for (const string& str : strs) {
      string s = str;
      sort(s.begin(), s.end());
      dict[fn(s)].push_back(str);
    }
    vector<vector<string>> ret;
    for (auto& elm : dict)
      ret.push_back(elm.second);
    return ret;
  }
};
