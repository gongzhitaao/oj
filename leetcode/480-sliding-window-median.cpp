class Solution
{
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k)
  {
    vector<double> ret;
    multiset<long long> w(nums.begin(), nums.begin() + k);
    auto mid = next(w.begin(), k / 2);
    for (int i = k; ; ++i) {
      ret.push_back((*mid + *prev(mid, 1 - (1 & k))) / 2.);

      if (i == nums.size())
        break;

      w.insert(nums[i]);
      if (nums[i] < *mid) --mid;

      if (nums[i - k] <= *mid) ++mid;
      w.erase(w.lower_bound(nums[i - k]));
    }

    return ret;
  }
};
