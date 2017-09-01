class Solution
{
 public:
  vector<int> majorityElement(vector<int>& nums)
  {
    int v0 = 0, v1 = 0, c0 = 0, c1 = 0;
    for (int num : nums) {
      if (num == v0) ++c0;
      else if (num == v1) ++c1;
      else if (0 == c0) v0 = num, ++c0;
      else if (0 == c1) v1 = num, ++c1;
      else --c0, --c1;
    }

    c0 = c1 = 0;
    for (int num : nums) {
      if (num == v0) ++c0;
      else if (num == v1) ++c1;
    }

    vector<int> ret;
    int n = nums.size();
    if (c0 > n / 3) ret.push_back(v0);
    if (c1 > n / 3) ret.push_back(v1);

    return ret;
  }
};
