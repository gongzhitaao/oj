class Solution
{
 public:
  vector<vector<int>> permute(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret{nums};
    for (; next_perm(nums); ret.push_back(vector<int>{nums}))
      ;
    return ret;
  }

  bool next_perm(vector<int>& nums)
  {
    int i;
    for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i + 1]; --i)
      ;
    if (i < 0) return false;

    int j;
    for (j = nums.size() - 1; nums[j] <= nums[i]; --j)
      ;

    swap(nums[i], nums[j]);
    reverse(nums.begin() + i + 1, nums.end());
    return true;
  }
};
