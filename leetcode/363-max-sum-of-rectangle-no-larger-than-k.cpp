class Solution
{
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
  {
    const int row = matrix.size(), col = matrix[0].size();
    vector<int> buf(row, 0);
    int maxsum = numeric_limits<int>::min();
    for (int l = 0; l < col; ++l) {
      fill(buf.begin(), buf.end(), 0);
      for (int r = l; r < col; ++r) {
        for (int i = 0; i < row; ++i) buf[i] += matrix[i][r];
        map<int, int> lookup;
        int cursum = 0;
        for (int i = 0; i < row; ++i) {
          cursum += buf[i];
          if (maxsum < cursum && cursum <= k) maxsum = cursum;
          auto p = lookup.lower_bound(cursum - k);
          if (p != lookup.end() && cursum - p->first > maxsum)
            maxsum = cursum - p->first;
          if (maxsum == k) return maxsum;
          lookup[cursum] = i;
        }
      }
    }
    return maxsum;
  }
};
