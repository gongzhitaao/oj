class Solution
{
 public:
  vector<string>
  findMissingRanges(vector<int>& nums, int lower, int upper)
  {
    vector<string> ret;
    if (nums.empty() || nums.back() < upper)
      nums.push_back(upper+1);
    for (int i = 0, cur = lower; i < nums.size(); ++i) {
      string range;
      if (nums[i] > cur + 1)
        ret.push_back(to_string(cur) + "->" + to_string(nums[i]-1));
      else if (nums[i] > cur)
        ret.push_back(to_string(cur));
      cur = nums[i] + 1;
    }
    return ret;
  }
};
