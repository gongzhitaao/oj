class Solution
{
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D)
  {
    const int n = A.size();

    unordered_map<int, int> ab;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ++ab[A[i] + B[j]];

    int cnt = 0;
    for (int i = 0, j = 0, k = 0; i < n; ++i) {
      if (0 == i || C[i] != C[i - 1]) {
        for (j = 0, k = 0; j < n; ++j) {
          auto it = ab.find(-C[i] - D[j]);
          if (it != ab.end()) k += it->second;
        }
      }
      cnt += k;
    }

    return cnt;
  }
};
