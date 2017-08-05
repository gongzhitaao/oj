class Solution
{
 public:
  int leastInterval(vector<char>& tasks, int n)
  {
    unordered_map<char, int> cnt;
    for (char t : tasks) ++cnt[t];

    map<int, int> freq;
    for (auto& elm : cnt) ++freq[elm.second];

    int l = freq.rbegin()->first, f = freq.rbegin()->second;
    return max((int)tasks.size(), (l - 1) * n + l + f - 1);
  }
};
