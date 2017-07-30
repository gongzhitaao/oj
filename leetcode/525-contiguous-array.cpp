class Solution
{
 public:
  int findMaxLength(vector<int>& nums)
  {
    unordered_map<int, int> pos;
    pos[0] = -1;
    int ret = 0;
    for (int i = 0, diff = 0; i < nums.size(); ++i) {
      diff += (nums[i] << 1) - 1;
      if (pos.find(diff) == pos.end())
        pos[diff] = i;
      else if (i - pos[diff] > ret)
        ret = i - pos[diff];
    }
    return ret;
  }
};
