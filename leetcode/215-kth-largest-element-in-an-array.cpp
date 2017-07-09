class Solution
{
 public:
  int findKthLargest(vector<int>& nums, int k)
  {
    int n = nums.size();
    for (int i = (n - 2) / 2; i >= 0; --i)
      max_heapify(nums, i, n);

    int ret = 0;
    for (int i = 0; ;) {
      ret = nums[0];
      if (++i >= k) break;

      swap(nums[0], nums[--n]);
      max_heapify(nums, 0, n);
    }

    return ret;
  }

 private:
  void max_heapify(vector<int>& nums, int i, int n)
  {
    int l = 2 * i + 1, r = 2 * i + 2;
    int k = i;

    if (l < n && nums[l] > nums[k]) k = l;
    if (r < n && nums[r] > nums[k]) k = r;

    if (k != i) {
      swap(nums[i], nums[k]);
      max_heapify(nums, k, n);
    }
  }
};
