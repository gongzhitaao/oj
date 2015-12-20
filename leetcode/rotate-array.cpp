class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    if (nums.empty()) return;

    int n = nums.size();
    int step = k % n;

    if (!step) return;

    for (int cnt = 0, beg = 0, i = 0, t = nums[0];
         cnt < nums.size(); ++cnt) {
      int j = (i + step) % n;
      int num = nums[j];
      nums[j] = t;
      t = num;

      if (beg == j)
        t = nums[beg = i = (j + 1) % n];
      else
        i = j;
    }
  }
};
