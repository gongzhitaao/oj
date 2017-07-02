class Solution
{
 public:
  int minDistance(string word1, string word2)
  {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    vector<vector<int>> step(m, vector<int>(n, -2));

    lcs(word1, m-1, word2, n-1, memo, step);

    int sum = 0, acc = 0;
    // for (int i = m-1, j = n-1; i >= 0 && j >= 0; ) {
    //   acc += step[i][j];
    //   if (step[i][j] < 0) --i;
    //   else if (step[i][j] > 0) --j;
    //   else {
    //     sum += abs(acc);
    //     acc = 0;
    //     --i, --j;
    //   }
    // }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        cout << step[i][j] << ' ';
      cout << endl;
    }

    return sum;
  }

 private:
  int lcs(const string& s0, int i, const string& s1, int j,
          vector<vector<int>>& memo, vector<vector<int>>& step)
  {
    if (i < 0) {
      for (int jj = 0; jj <= j; ++jj)
        step[i][jj] = 1, memo[i][jj] = 0;
      return 0;
    }

    if (j < 0) {
      for (int ii = 0; ii <= i; ++ii)
        step[ii][j] = -1, memo[ii][j] = 0;
      return 0;
    }

    if (memo[i][j] >= 0)
      return memo[i][j];

    if (s0[i] == s1[j]) {
      step[i][j] = 0;
      return memo[i][j] = lcs(s0, i-1, s1, j-1, memo, step) + 1;
    }

    int a = lcs(s0, i, s1, j-1, memo, step);  // from right
    int b = lcs(s0, i-1, s1, j, memo, step);  // from top

    if (a > b) {
      step[i][j] = 1;
      return memo[i][j] = a;
    }

    step[i][j] = -1;
    return memo[i][j] = b;
  }
};
