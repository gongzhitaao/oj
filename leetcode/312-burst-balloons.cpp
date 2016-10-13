class Solution
{
 public:
  int maxCoins(vector<int>& nums)
  {
    int n = nums.size();
    if (0 == n) return 0;
    if (1 == n) return nums[0];

    vector<int> A = {1};
    A.insert(end(A), begin(nums), end(nums));
    A.push_back(1);

    vector<vector<int> > v(n+1, vector<int>(n+2, 0));
    const int imin = numeric_limits<int>::min();
    for (int i = n-1; i >= 0; --i) {
      for (int j = i+2; j <= n+1; ++j) {
        int cur = imin;
        for (int k = i+1; k <= j-1; ++k) {
          int t = v[i][k] + v[k][j] + A[i]*A[k]*A[j];
          if (t > cur) cur = t;
        }
        v[i][j] = cur;
      }
    }

    return v[0][n+1];
  }
};
