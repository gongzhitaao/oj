class Solution
{
 public:
  int maximumSwap(int num)
  {
    vector<int> n, p;
    for (int i = num, j = 0; i; i /= 10) {
      int k = i % 10;
      n.push_back(k);
      if (k > n[j]) j = n.size() - 1;
      p.push_back(j);
    }

    for (int i = p.size() - 1; i >= 0; --i) {
      if (n[i] != n[p[i]]) {
        swap(n[i], n[p[i]]);
        break;
      }
    }

    int ret = 0;
    for (auto it = n.rbegin(); it != n.rend(); ++it)
      ret = ret * 10 + *it;
    return ret;
  }
};
