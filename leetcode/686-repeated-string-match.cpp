class Solution
{
 public:
  int repeatedStringMatch(string A, string B)
  {
    const int sa = A.size(), sb = B.size();
    for (int k = 0, i, j; k < sa; ++k) {
      for (i = k, j = 0; j < sb && A[i] == B[j]; ++j, i = ++i % sa)
        ;
      if (sb == j)
        return (k + j) / A.size() + ((k + j) % A.size() != 0 ? 1 : 0);
    }
    return A.empty() && B.empty() ? 1 : -1;
  }
};
