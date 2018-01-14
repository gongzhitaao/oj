class Solution
{
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    if (matrix.empty() || matrix[0].empty()) return false;

    for (int i = 0, j = matrix[0].size() - 1; i < matrix.size() && j >= 0;) {
      if (target == matrix[i][j]) return true;
      if (target < matrix[i][j])
        --j;
      else
        ++i;
    }

    return false;
  }
};
