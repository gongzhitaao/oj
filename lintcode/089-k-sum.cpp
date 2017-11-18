class Solution
{
 public:
  /*
   * @param A: An integer array
   * @param k: A positive integer (k <= length(A))
   * @param target: An integer
   * @return: An integer
   */
  int kSum(vector<int> &A, int k, int target)
  {
    if (A.empty() || target <= 0) return 0;

    sort(A.begin(), A.end());
    vector<vector<unordered_map<int, int>>> memo(
      A.size() + 1,
      vector<unordered_map<int, int>>(k + 1, unordered_map<int, int>()));
    return ksum_(A, k, target, 0, memo);
  }

  int ksum_(vector<int> &A, int k, int target, int i0,
            vector<vector<unordered_map<int, int>>> &memo)
  {
    int cnt = 0;

    if (memo[i0][k].find(target) != memo[i0][k].end())
      return memo[i0][k][target];

    if (1 == k) {
      for (int i = i0; i < A.size(); ++i)
        if (A[i] == target) ++cnt;
    } else if (2 == k) {
      for (int i = i0, j = A.size() - 1; i < j;) {
        if (A[i] + A[j] < target)
          ++i;
        else if (A[i] + A[j] > target)
          --j;
        else
          ++cnt, ++i, --j;
      }
    } else {
      for (int i = i0; i < A.size() - k + 1; ++i)
        cnt += ksum_(A, k - 1, target - A[i], i + 1, memo);
    }

    return memo[i0][k][target] = cnt;
  }
};
