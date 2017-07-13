class Solution
{
 public:
  int maxSubArrayLen(vector<int>& nums, int k)
  {
    map<int, int> pos;
    pos[0] = 0;

    int sum = 0, ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (pos.find(sum - k) != pos.end()) {
        int len = i - pos[sum - k] + 1;
        if (len > ret) ret = len;
      }
      if (pos.find(sum) == pos.end())
        pos[sum] = i + 1;
    }

    return ret;
  }
};
