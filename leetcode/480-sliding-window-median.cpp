class Solution
{
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k)
  {
    vector<double> ms;
    if (k < 1 || nums.empty()) return ms;

    multiset<long long> win(nums.begin(), nums.begin() + k);
    auto it = win.begin();
    advance(it, k / 2);
    if (k & 1)
      ms.push_back(*it);
    else {
      auto pre = it--;
      ms.push_back((*it + *pre) / 2.);
    }

    for (int i = 1; i <= nums.size() - k; ++i) {
      win.erase(win.find(nums[i - 1]));
      win.insert(nums[i + k - 1]);
      auto it = win.begin();
      advance(it, k / 2);
      if (k & 1)
        ms.push_back(*it);
      else {
        auto pre = it--;
        ms.push_back((*it + *pre) / 2.);
      }
    }

    return ms;
  }
};
