class Solution
{
 public:
  int kEmptySlots(vector<int>& flowers, int k)
  {
    vector<int> sum(flowers.size() + 1, 0);
    for (int i = 0; i < flowers.size(); ++i) {
      int j = flowers[i];
      update(sum, j);

      if (j - k - 1 > 0) {
        int a = query(sum, j - k - 2),
            b = query(sum, j - k - 1),
            c = query(sum, j - 1);
        if (1 == b - a && 0 == c - b) return i + 1;
      }

      if (j + k + 1 < sum.size()) {
        int a = query(sum, j),
            b = query(sum, j + k),
            c = query(sum, j + k + 1);
        if (0 == b - a && 1 == c - b) return i + 1;
      }
    }
    return -1;
  }

  void update(vector<int>& sum, int i)
  {
    for (; i < sum.size(); i += i & -i) ++sum[i];
  }

  int query(vector<int>& sum, int i)
  {
    int ret = 0;
    for (; i; i -= i & -i) ret += sum[i];
    return ret;
  }
};
