class Solution
{
 public:
  int maxSubArrayLen(vector<int>& nums, int k)
  {
    map<int, int> pos;
    int maxlen = 0;
    for (int i = 0, sum = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (sum == k)
        maxlen = i + 1;
      else {
        auto it = pos.find(sum - k);
        if (it != pos.end() && i - it->second > maxlen)
          maxlen = i - it->second;
      }
      if (pos.find(sum) == pos.end())
        pos[sum] = i;
    }
    return maxlen;
  }
};
