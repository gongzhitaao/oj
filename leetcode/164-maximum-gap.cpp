class Solution
{
 public:
  int maximumGap(vector<int>& nums)
  {
    if (nums.size() < 2) return 0;

    const int n = nums.size();
    int maxelem = *max_element(nums.begin(), nums.end());

    for (int k = 0, mask = 1; k < 31 && mask <= maxelem; mask <<= 1, ++k) {
      vector<int> b0, b1;
      for (int i = 0; i < n; ++i)
        if (nums[i] & mask) b1.push_back(nums[i]);
        else b0.push_back(nums[i]);
      copy(b0.begin(), b0.end(), nums.begin());
      copy(b1.begin(), b1.end(), nums.begin() + b0.size());
    }

    int ret = 0;
    for (int i = 0; i < nums.size() - 1; ++i)
      if (nums[i + 1] - nums[i] > ret) ret = nums[i + 1] - nums[i];

    return ret;
  }
};
