class Solution
{
 public:
  int longestConsecutive(vector<int>& nums)
  {
    unordered_set<int> h;
    for (int n : nums) h.insert(n);

    int len = 0;
    while (!h.empty()) {
      int n = *h.begin(), m, cnt = 0;
      for (m = n-1; h.find(m) != h.end(); --m) h.erase(m);
      cnt += n-1 - m;
      for (m = n; h.find(m) != h.end(); ++m) h.erase(m);
      cnt += m - n;
      if (cnt > len) len = cnt;
    }
    return len;
  }
};
