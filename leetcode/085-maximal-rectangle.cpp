class Solution
{
 public:
  int maximalRectangle(vector<vector<char>>& matrix)
  {
    if (matrix.empty() || matrix[0].empty()) return 0;
    const int row = matrix.size(), col = matrix[0].size();

    vector<int> h(col + 1, 0);

    int ret = 0;
    for (int i = 0; i < row; ++i) {
      stack<int> left;
      left.push(-1);

      matrix[i].push_back('0');
      for (int j = 0; j <= col; ++j) {
        h[j] = '0' == matrix[i][j] ? 0 : h[j] + 1;
        for (; left.size() > 1 && h[j] <= h[left.top()]; ) {
          int curh = h[left.top()];
          left.pop();
          int curarea = (j - left.top() - 1) * curh;
          if (curarea > ret) ret = curarea;
        }
        left.push(j);
      }
      matrix[i].pop_back();
    }

    return ret;
  }
};
