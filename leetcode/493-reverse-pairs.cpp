class Solution
{
 public:
  int reversePairs(vector<int>& nums)
  {
    if (nums.empty()) return 0;

    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());

    vector<int> bit(nums.size() + 1, 0);
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
      cnt += query(bit, 1 + index(tmp, 2ll * nums[i] + 1));
      update(bit, 1 + index(tmp, nums[i]));
    }

    return cnt;
  }

  int query(vector<int>& bit, int i)
  {
    int ans = 0;
    for (; i < bit.size(); i += i & -i) ans += bit[i];
    return ans;
  }

  void update(vector<int>& bit, int i)
  {
    for (; i; i -= i & -i) ++bit[i];
  }

  int index(vector<int>& tmp, long long n)
  {
    int lo = 0, hi = tmp.size() - 1;
    for (; lo <= hi; ) {
      int mi = lo + (hi - lo) / 2;
      if (tmp[mi] < n) lo = mi + 1;
      else hi = mi - 1;
    }
    return lo;
  }
};
