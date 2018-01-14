class Solution
{
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    if (matrix.empty() || matrix[0].empty()) return false;
    return lookup(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1,
                  target);
  }

  bool lookup(vector<vector<int>>& mat, int ilo, int ihi, int jlo, int jhi,
              int target)
  {
    if (ilo > ihi || jlo > jhi) return false;
    int imi = ilo + (ihi - ilo) / 2, jmi = jlo + (jhi - jlo) / 2;

    if (mat[imi][jmi] == target) return true;
    if (mat[imi][jmi] < target)
      return lookup(mat, imi + 1, ihi, jlo, jhi, target) ||
             lookup(mat, ilo, imi, jmi + 1, jhi, target);
    return lookup(mat, ilo, imi - 1, jlo, jhi, target) ||
           lookup(mat, imi, ihi, jlo, jmi - 1, target);
  }
};
