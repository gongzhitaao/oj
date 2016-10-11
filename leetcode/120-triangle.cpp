class Solution
{
 public:
  int minimumTotal(vector<vector<int> >& triangle)
  {
    int n = triangle.size();
    if (!n) return 0;
    const int imax = numeric_limits<int>::max();

    vector<int> sum(n, imax);
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
      int pre = imax;
      for (int j = 0; j <= i; ++j) {
        int tmp = sum[j];
        sum[j] = min(pre, sum[j]) + triangle[i][j];
        pre = tmp;
      }
    }
    return *min_element(sum.begin(), sum.end());
  }
};
