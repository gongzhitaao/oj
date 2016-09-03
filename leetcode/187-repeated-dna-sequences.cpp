class Solution
{
 public:
  vector<string> findRepeatedDnaSequences(string s)
  {
    vector<string> ret;
    unordered_map<int, int> cnt;
    unordered_map<char, int> hash = {{'A', 4}, {'C', 5}, {'G', 6}, {'T', 7}};
    unsigned key = 0;
    for (int i = 0; i < s.size(); ++i) {
      key = (key << 3 | hash[s[i]]) & 0x3fffffff;
      if ((key & 0x20000000) && 2 == ++cnt[key])
        ret.push_back(s.substr(i - 9, 10));
    }
    return ret;
  }

};
