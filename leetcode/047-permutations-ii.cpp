class Solution
{
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret{nums};
    for (; next_perm(nums); ret.push_back(vector<int>{nums}))
      ;
    return ret;
  }

  bool next_perm(vector<int>& arr)
  {
    int i;
    for (i = arr.size() - 2; i >= 0 && arr[i] >= arr[i + 1]; --i)
      ;
    if (i < 0) return false;

    int j;
    for (j = arr.size() - 1; arr[i] >= arr[j]; --j)
      ;

    swap(arr[i], arr[j]);
    reverse(arr.begin() + i + 1, arr.end());
    return true;
  }
};
