class Solution
{
 public:
  int longestConsecutive(vector<int>& nums)
  {
    unordered_set<int> h;
    for (int n : nums) h.insert(n);

    int len = 0;
    for (int n : h) {
      if (h.find(n-1) != h.end()) continue;
      int m;
      for (m = n; h.find(m) != h.end(); ++m);
      if (m-n > len) len = m - n;
    }
    return len;
  }
};
