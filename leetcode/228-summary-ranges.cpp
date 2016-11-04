class Solution
{
 public:
  vector<string> summaryRanges(vector<int>& nums)
  {
    vector<string> ret;
    int n = nums.size();
    if (!n) return ret;

    int start = nums[0], end = start-1;
    for (int i = 1; i < n; ++i) {
      if ((long long)nums[i]-nums[i-1] > 1) {
        end = nums[i-1];
        if (start == end)
          ret.push_back(to_string(start));
        else
          ret.push_back(to_string(start) + "->" + to_string(end));
        start = nums[i];
        end = start - 1;
      }
    }
    if (end < start) {
      end = nums.back();
      if (start == end)
        ret.push_back(to_string(start));
      else
        ret.push_back(to_string(start) + "->" + to_string(end));
    }
    return ret;
  }
};
