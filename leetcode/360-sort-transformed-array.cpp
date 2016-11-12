class Solution
{
 public:
  vector<int>
  sortTransformedArray(vector<int>& nums, int a, int b, int c)
  {
    vector<int> ret;
    if (nums.empty()) return ret;

    if (!a) {
      if (b >= 0)
        for (int e : nums) ret.push_back(f(e, a, b, c));
      else
        for (auto it = nums.rbegin(); it != nums.rend(); ++it)
          ret.push_back(f(*it, a, b, c));
      return ret;
    }

    float center = -0.5 * b / a;
    int n = nums.size();
    if (a > 0) {
      int mid = distance(nums.begin(),
                         lower_bound(nums.begin(), nums.end(), center));
      int i = mid-1, j = mid;
      for (; i >= 0 && j < n; ) {
        if (center-nums[i] < nums[j]-center)
          ret.push_back(f(nums[i--], a, b, c));
        else
          ret.push_back(f(nums[j++], a, b, c));
      }
      for (; i >= 0; --i) ret.push_back(f(nums[i], a, b, c));
      for (; j < n; ++j) ret.push_back(f(nums[j], a, b, c));
    } else {
      int i = 0, j = n-1;
      for (; i <= j; ) {
        if (center-nums[i] > nums[j]-center)
          ret.push_back(f(nums[i++], a, b, c));
        else
          ret.push_back(f(nums[j--], a, b, c));
      }
    }
    return ret;
  }

  inline int f(int x, int a, int b, int c)
  {
    return a*x*x + b*x + c;
  }
};
