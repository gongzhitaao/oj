class Solution
{
 public:
  int getMoneyAmount(int n)
  {
    vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    return foo(dp, 1, n);
  }

  int foo(vector<vector<int> >& vec, int start, int end)
  {
    if (vec[start][end] >= 0) return vec[start][end];
    if (start >= end) return vec[start][end] = 0;

    int sum = min(start + foo(vec, start+1, end),
                  foo(vec, start, end-1) + end);
    for (int i = start+1; i < end; ++i) {
      int tmp = i + max(foo(vec, start, i-1), foo(vec, i+1, end));
      if (tmp < sum) sum = tmp;
    }
    return vec[start][end] = sum;
  }
};
