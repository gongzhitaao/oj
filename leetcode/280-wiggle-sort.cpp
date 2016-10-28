class Solution
{
 public:
  void wiggleSort(vector<int>& nums)
  {
    int n = nums.size();
    if (n < 2) return;

    nth_element(nums.begin(), nums.begin() + n/2, nums.end());
    int median = nums[n/2];
    for (int i = 0, j = 1; i < n && j < n; ) {
      if (nums[i] >= median) {
        swap(nums[i], nums[j]);
        j += 2;
      } else i += 2;
    }
  }
};
