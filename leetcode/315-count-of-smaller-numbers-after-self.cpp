class Solution
{
 public:
  vector<int> countSmaller(vector<int>& nums)
  {
    if (nums.empty()) return nums;

    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());

    const int n = nums.size();

    vector<int> cnt(n, 0);
    vector<int> bit(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int p0 = index(tmp, nums[i] + 1ll);
      int p1 = index(tmp, nums[i]);
      cnt[i] = p1 - query(bit, p1 + 1);
      update(bit, p0 + 1);
    }

    return cnt;
  }

  int query(vector<int>& bit, int i)
  {
    int ans = 0;
    for (; i; i -= i & -i) ans += bit[i];
    return ans;
  }

  void update(vector<int>& bit, int i)
  {
    for (; i < bit.size(); i += i & -i) ++bit[i];
  }

  int index(vector<int>& tmp, long long n)
  {
    int lo = 0, hi = tmp.size() - 1, mi;
    for (; lo <= hi; ) {
      mi = lo + (hi - lo) / 2;
      if (tmp[mi] < n) lo = mi + 1;
      else hi = mi - 1;
    }
    return lo;
  }
};
