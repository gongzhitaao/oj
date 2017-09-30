class Solution
{
 public:
  int leastInterval(vector<char>& tasks, int n)
  {
    vector<int> cnt(26, 0);
    for (char ch : tasks) ++cnt[ch - 'A'];

    sort(cnt.begin(), cnt.end());

    int i;
    for (i = 25; i >= 0 && cnt[i] == cnt[25]; --i)
      ;

    return max(int(tasks.size()), (cnt[25] - 1) * (n + 1) + 25 - i);
  }
};
