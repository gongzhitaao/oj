class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;

    if (nums.empty()) return ret;

    int beg = nums[0];
    string range = to_string(beg);
    for (int i = 0; i < nums.size() - 1; ++i) {
      if ((long long)nums[i + 1] - nums[i] > 1LL) {
        if (beg != nums[i]) range += "->" + to_string(nums[i]);
        ret.push_back(range);

        beg = nums[i + 1];
        range = to_string(beg);
      }
    }

    if (beg != nums.back()) range += "->" + to_string(nums.back());
    ret.push_back(range);

    return ret;
  }
};
