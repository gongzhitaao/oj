class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    nth_element(nums.begin(), nums.begin() + (n >> 1), nums.end());
    int m = nums[n >> 1];
#define A(i) nums[(1 + 2 * (i)) % (n | 1)]
    for (int i = 0, j = 0, k = n - 1; j <= k; ) {
      if (A(j) > m) swap(A(i++), A(j++));
      else if (A(j) < m) swap(A(k--), A(j));
      else ++j;
    }
  }
};
