class Solution
{
 public:
  int hIndex(vector<int>& citations)
  {
    sort(citations.begin(), citations.end());
    int sz = citations.size();
    for (int h = sz; h > 0; --h) {
      int i = sz - h;
      if (citations[i] >= h && (!i || citations[i-1] <= h))
        return h;
    }
    return 0;
  }
};
