class Solution
{
 public:
  vector<int> countSmaller(vector<int>& nums)
  {
    int n = nums.size();
    vector<int> ret(n, 0);
    vector<pair<int, int> > tmp;
    tmp.reserve(n);
    for (int i = 0; i < n; ++i)
      tmp.push_back({nums[i], i});
    mergesort(tmp, ret, 0, nums.size());
    return ret;
  }

  void mergesort(vector<pair<int, int> >& nums, vector<int>& cnt,
                 int i0, int len)
  {
    if (len <= 1) return;
    int j0 = i0 + len / 2;
    mergesort(nums, cnt, i0, j0-i0);
    mergesort(nums, cnt, j0, len-j0+i0);

    vector<pair<int, int> > buf;
    buf.reserve(len);
    int i, j, n = 0;
    for (i = i0, j = j0; i < j0 && j < i0+len; ) {
      if (nums[i].first <= nums[j].first) {
        cnt[nums[i].second] += n;
        buf.push_back(nums[i++]);
      } else {
        ++n;
        buf.push_back(nums[j++]);
      }
    }
    for (; i < j0; ++i) {
      cnt[nums[i].second] += n;
      buf.push_back(nums[i]);
    }
    for (; j < i0+len; ++j)
      buf.push_back(nums[j]);
    copy(buf.begin(), buf.end(), nums.begin()+i0);
  }
};
