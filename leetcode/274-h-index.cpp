class Solution
{
 public:
  int hIndex(vector<int>& citations)
  {
    int n = citations.size();
    vector<int> bucket(n+1, 0);
    for (int i : citations)
      ++bucket[i > n ? n : i];
    int h = 0;
    for (int i = n; i > 0; --i)
      if ((h += bucket[i]) >= i) return i;
    return 0;
  }
};
