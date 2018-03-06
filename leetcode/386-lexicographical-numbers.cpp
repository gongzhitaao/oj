class Solution
{
 public:
  vector<int> lexicalOrder(int n)
  {
    if (n < 1) return {};
    vector<int> ret(n, 0);
    ret[0] = 1;
    for (int i = 1; i < n; ++i) {
      int next = ret[i - 1] * 10;
      if (next > n) {
        for (next = ret[i - 1] + 1; next > n; next = (next - 1) / 10 + 1)
          ;
        for (; 0 == next % 10; next = next / 10)
          ;
      }
      ret[i] = next;
    }
    return ret;
  }
};
