class Solution
{
 public:
  int countSubstrings(string s)
  {
    vector<int> cur, last;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      swap(cur, last);
      cur.clear();
      for (int p : last)
        if (p > 0 && s[i] == s[p - 1])
          cur.push_back(p - 1);
      cur.push_back(i);
      if (i > 0 && s[i] == s[i - 1])
        cur.push_back(i - 1);
      cnt += cur.size();
    }
    return cnt;
  }
};
