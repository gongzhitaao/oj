class Solution
{
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    if (matrix.empty() || matrix[0].empty() ||
        target < matrix[0][0] || target > matrix.back().back())
      return false;

    int nrow = matrix.size(), ncol = matrix[0].size();
    for (int lo = 0, hi = nrow * ncol - 1; lo <= hi; ) {
      int mi = lo + (hi - lo + 1) / 2;
      int r = mi / ncol, c = mi % ncol;
      if (matrix[r][c] == target) return true;
      if (matrix[r][c] < target) lo = mi + 1;
      else hi = mi - 1;
    }
    return false;
  }
};
